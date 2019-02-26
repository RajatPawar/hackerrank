#include <iostream>

enum {
    LEFT,
    RIGHT
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap {
    int *heap_arr, // Points to the array representing the heap
        curr_size, // How many elems does the heap have?
        max_capacity;
    
    void heapify(int);

    public:
    
    MinHeap(int capacity): max_capacity(capacity), curr_size(0), heap_arr(new int[capacity]) {}

    int peek_min();
    int pop_min();
    int parent(int);
    int child(int, int);
    void print_arr();
    int set_val(int, int);
    void del_val(int);
    void insert(int); 
};

void MinHeap :: heapify(int idx) {
    int left = child(idx, LEFT);
    int right = child(idx, RIGHT);
    int smallest = idx;

    if(heap_arr[left] < heap_arr[idx] && left < curr_size)
        smallest = left;
    if(heap_arr[right] < heap_arr[idx] && right < curr_size)
        smallest = right;
    
    // If left or right is bigger than parent, then repeat procedure for them
    if(smallest != idx) {
        swap(&heap_arr[smallest], &heap_arr[idx]);
        heapify(smallest);
    }
}

int MinHeap :: peek_min() {
    return heap_arr[0];
}

int MinHeap:: parent(int idx) {
    return ((idx - 1) / 2);
}

int MinHeap :: child(int idx, int side) {
    if(side != LEFT || side != RIGHT) return -1;
    return (side == LEFT) ? ((2 * idx) + 1) : ((2 * idx) + 2);
}

int MinHeap :: set_val(int idx, int new_val) {
   heap_arr[idx] = new_val;
   
   while(idx > 0 && heap_arr[parent(idx)] > heap_arr[idx]) {
       swap(&heap_arr[parent(idx)], &heap_arr[idx]);
       idx = parent(idx);
   }
}

void MinHeap :: del_val(int idx) {
    set_val(idx, -9999999);
    pop_min();
}

int MinHeap :: pop_min() {
    if(!curr_size) return -99999999;
    else if(curr_size == 1) {
        curr_size--;
        return heap_arr[0];
    }
    
    int ret = heap_arr[0];
    heap_arr[0] = heap_arr[curr_size - 1];
    curr_size--;
    
    heapify(0);
    return ret;
}

void MinHeap :: insert(int key) {
    if(curr_size == max_capacity) return;
    curr_size++;

    int to_insert_at = curr_size - 1;
    if(!curr_size) to_insert_at = 0;
    heap_arr[to_insert_at] = key;
    
   while(to_insert_at > 0 && heap_arr[parent(to_insert_at)] > heap_arr[to_insert_at]) {
       swap(&heap_arr[parent(to_insert_at)], &heap_arr[to_insert_at]);
       to_insert_at = parent(to_insert_at);
   }

}

void MinHeap :: print_arr() {
    std::cout<<std::endl<<"----------";
    for(int i = 0; i < curr_size; i++ ) std::cout<<heap_arr[i]<< " ";
    std::cout<<"----------"<<std::endl;
}

int main() {
    MinHeap h(11); 
    h.insert(3); 
    h.print_arr();
    h.insert(2); 
    h.print_arr();
    h.del_val(1); 
    h.print_arr();
    h.insert(15); 
    h.print_arr();
    h.insert(5); 
    h.print_arr();
    h.insert(4); 
    h.print_arr();
    h.insert(45); 
    h.print_arr();
    std:: cout << h.pop_min() << " "; 
    std:: cout << h.peek_min() << " "; 
    h.set_val(2, 1); 
    std:: cout << h.peek_min()<<" NOW DEBUG "<<std::endl;     
    h.print_arr();
    return 0;
}
