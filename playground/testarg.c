#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *a = (int *) malloc(3 * sizeof(int)); 
    a =  &{1, 2, 3};
    
    for(int i = 0; i < 3; i++) {
        printf("| %d |", *(a + i));
    }
    
    return 0;
}
