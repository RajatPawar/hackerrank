#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE(x)                 (sizeof(x)/sizeof(x[0]))
#define MAX_ANMLKNGDM_SIZE      (8)
#define MAX_ALLIES              (5)
#define MIN_INPUT_LENGTH        (4) // Least kingdom name len + a comma

#define NOT_ALLIED              (0)
#define ALLIED                  (1)

#define ANIMAL                  (1)
#define KINGDOM                 (0)


enum READING_STATES {
    READING_INVALID = -1,         
    READING_KINGDOM,         
    READING_SECRET_MSG      
};

char kingdom_animal_array[MAX_ALLIES][2][MAX_ANMLKNGDM_SIZE] = {
    {"Air", "owl"},
    {"Land", "Panda"},
    {"Ice", "Mammoth"},
    {"Water", "Octopus"},
    {"Fire", "Dragon"}
};

// Converts entire string to lower
char* strtolower(char *s) {
    for (char *p = s; *p; ++p) *p = tolower(*p);
    return s;
}

// Trims whitespaces on either side
char* trim_ends(char *s) {
    char *end = s + strlen(s) - 1;
    while(*s++ == ' ') ;
    while(*end-- == ' ') ;
    *(end + 2) = '\0';
    return --s;
}

// Returns animal for given kingdom or vice versa
char* get_data(char *data, int get_type_data) {
    int compare = (get_type_data == ANIMAL) ? 1 : 0; 
    for(int i = 0; i < SIZE(kingdom_animal_array); i++) 
        if(!strcmp(kingdom_animal_array[i][!compare], data)) 
            return kingdom_animal_array[i][compare];
    return NULL;
}

// Returns index for given kingdom/animal
int get_index_from_data(char *data) {
    for(int i = 0; i < SIZE(kingdom_animal_array); i++)
         if(!strcmp(kingdom_animal_array[i][0], data) || !strcmp(kingdom_animal_array[i][1], data)) return i;
    return -1;
}

// Returns data (kingdom/animal based on 2nd param) for given index
char* get_data_from_index(int index, int type_wanted) {
    if(index >= 0 && index < SIZE(kingdom_animal_array))
        return kingdom_animal_array[index][type_wanted];
    return NULL;
}

// Returns kingdom match from secret message
int decipher_check(char *smsg, char *animal) {
    char *chrptr;
    int found = 0, itr = 0, len_anim = strlen(animal);
    while(itr < len_anim) {
        if((chrptr = strchr(smsg, animal[itr++])) != NULL) {
            found++;
            *chrptr = '1'; // Marking that char in the secret message as read
        }
    }
    if(found == len_anim) 
        return get_index_from_data(animal);
    return -1;
}

int get_num_allies(int arr[]) {
    int allies = 0;

     // Prefer SIZE(kingdom_animal_array) than SIZE(arr) so that
     // we make sure that arr.len always equals kingdom_animal_array.len
     for(int i = 0; i < SIZE(kingdom_animal_array); i++) {
         if(arr[i] == ALLIED) allies++;
     }
    return allies;
}

// Prints all the allied kingdoms
void print_allied_kingdoms(int arr[]) {
    char *toprint = NULL, first = 1;
    printf("\n");

    int allies = get_num_allies(arr);
    if(allies > 0) {
        for(int i = 0; i < SIZE(kingdom_animal_array); i++) {
            if(arr[i] == ALLIED)
            {
                if(first) toprint = "%s", first = 0;
                else toprint = ", %s"; 

                printf(toprint, get_data_from_index(i, KINGDOM));
            }
        }
        printf("\n");
    }
    else printf("None\n");
}

// Prints if King Shan is the ruler or not
void print_ruler(int arr[]) {
    printf((get_num_allies(arr) >= 3) ? "\nKing Shan" : "\nNone");
}


// It all starts here!
int main() {
    char *input, *token, *str, *freemem, *animal;
    int token_in_consideration = READING_INVALID,
        input_asks = 1, 
        allies[MAX_ALLIES] = {NOT_ALLIED, NOT_ALLIED, NOT_ALLIED, NOT_ALLIED, NOT_ALLIED}, dec_result = -1;

    size_t MAX_BUFFER_SIZE = 1024;
    ssize_t nread;

    
    input = (char *) malloc(sizeof(char) * MAX_BUFFER_SIZE);
    freemem = input;

    printf("\nNOTE: Valid input is - <Kingdom>, <Secret message>\n\nInput: ");
    while((nread = getline(&input, &MAX_BUFFER_SIZE, stdin)) >= MIN_INPUT_LENGTH) {
        str = strdup(trim_ends(input));
        while((token = strsep(&str, ","))) {
            if(++token_in_consideration == READING_KINGDOM)
                animal = get_data(token, ANIMAL);
            else if(token_in_consideration == READING_SECRET_MSG) {
                if(animal) {
                    dec_result = decipher_check(strtolower(token), strtolower(animal));
                    if(dec_result != -1) 
                        allies[dec_result] = ALLIED;
                }
            }
        }
        token_in_consideration = READING_INVALID;
        if(input_asks++ < MAX_ALLIES) printf("\nInput: ");
        else break; // No more asks (5 kingdoms only)
    }
    
    printf("\nWho is the ruler of Southeros?");
    print_ruler(allies);

    printf("\nAllies of King Shan?");
    print_allied_kingdoms(allies);

    free(freemem);
    return 0;
}
