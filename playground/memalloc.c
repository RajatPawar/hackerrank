// My own mem alloc funcs

#include <stdio.h>
#include <unistd.h>

// Our metadata struct to store allocated block information
typedef struct alloc_block {
    int free; // 0 is not free
    struct alloc_block *next; // Points to the next free
    size_t size; // How long is this block?
} alloc_block;

#define METADATA_SIZE sizeof(alloc_block)

/* The idea is to allocate alloc_block before allocating 
 * memory, sort of like meta_data when we need to free a
 * previously allocated block
*/

// Our global list head (yes, it is global unfortunately - static as per K&R
// gives a variable internal linkage only - cannot be accessed from outside
static alloc_block *global_head = NULL;

/* Function to get memory from the os if we find nothing in our free list
*/
alloc_block* request_os_space(alloc_block **head, size_t size) {
    // Check if size is valid
    if(size <= 0) return NULL;
    
    // Where is the sbrk heap ptr right now?
    alloc_block *alloc_current = sbrk(0);

    // Attempt to allocate size + meta_size
    void *alloc_block_attempt = sbrk(size + METADATA_SIZE);

    // Check if it is a valid allocation
    if(alloc_block_attempt == (void *) -1)
        return NULL;

    if(alloc_block_attempt == alloc_current) {
        alloc_current->size = size;
        alloc_current->free = 0;
    
        // Allocate this to start of our linked list maintaining used blocks
        if(*head) {
            alloc_current->next = *head;
            *head = alloc_current;
        }
        else {
            *head = alloc_current;
            alloc_current->next = NULL;
        }

        return alloc_current;
    }
    return NULL;
}


/* Function to iterate through our free list and get the first matching
 * free block
*/
alloc_block* find_free_block(alloc_block **head, size_t size) {
    if(size <= 0) return NULL;
    alloc_block *itr = *head;
    while(itr) {

        // Found a match (first match)
        if(itr->free && itr->size >= size) 
            return itr;

        // Look for the next block
        itr = itr->next;
    }
    
    // itr is NULL here
    return NULL;
}

/* The actual malloc function */
void* malloc(size_t size) {
    
    if(size <= 0) return NULL;
    
    alloc_block* mem;

    // If global_head is NULL, it will automatically be checked there
    mem = find_free_block(&global_head, size);
    if(!mem) {
        // Didn't find any free block in the list or list isn't created yet
        mem = request_os_space(&global_head, size);
        
        // Any problem, we'll return an error
        if(!mem) 
            return (void*) -1;
    }

    // Reiterating some assignments, we can actually skip all this
    mem->free = 0;
    mem->size = size;

    // Free memory actually starts from mem + sizeof(alloc_block)
    return mem + 1; 
}

// Get where the metadata starts from
alloc_block* get_metadata_addr_from_block(void *ptr) {
    // Cast ptr to alloc_block and subtract 1
    return (alloc_block*) ptr - 1;
}

/* The free function */
void free(void* ptr) {
    if(!ptr) return;
    else {
        alloc_block* fptr = get_metadata_addr_from_block(ptr);
        if(fptr->free) return;
        
        fptr->free = 1;
    }
}

// Copy size bytes from ptr to new_memory
void memory_copy(void *new_memory, void *ptr, int size) {
    if(size <= 0) return;

    int to_copy_bytes = size;
    while(to_copy_bytes--)
        *((char*) new_memory++) = *((char*) ptr++);
}

/* Reallocation function */
void* realloc(void* ptr, size_t size) {
   if(!ptr) return malloc(size);
   
   alloc_block *metadata_ptr = get_metadata_addr_from_block(ptr);

   // If size <= oldsize, let's just return the same ptr as of now
   if(size <= metadata_ptr->size) 
       return ptr;

   // We want more space, second case
   void* new_memory = malloc(size);

   // Failure to give more memory
   if(!new_memory)
       return NULL;

   // Copy contents to new one & free old memory
   int to_copy_bytes = metadata_ptr->size;
   memory_copy(new_memory, ptr, to_copy_bytes);
   free(ptr);

   return new_memory;
}

int main() {
    int *test_int = malloc(sizeof(int));
    char *test_char_arr = malloc(6);

    *test_int = 4;
    printf("\nTest: %d\n @ %p\n & meta starts from %p", *test_int, test_int, get_metadata_addr_from_block(test_int));
    free(test_int);
    
    test_char_arr = "Hello";
    printf("\nTest: %s\n @ %p\n & meta starts from %p\n", test_char_arr, test_char_arr, get_metadata_addr_from_block(test_char_arr));
    
    realloc(test_char_arr, 15);
    test_char_arr = "Hello world!";
    printf("\nRealloc test: %s\n @ %p\n & meta starts from %p\n", test_char_arr, test_char_arr, get_metadata_addr_from_block(test_char_arr));
    free(test_char_arr);

    return 0;
}
