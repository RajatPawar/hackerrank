#include <stdio.h>
#include <stdlib.h>

char *readlines[10];

void printcontents(char** content, int n) {
    for(int i = 0; i < n; i++)
        printf("\n**content - %s", *(content + i)); 
}

int readline(char **ptr) {
    *ptr = (char *) malloc(10 * sizeof(char));
    char* orig = *ptr;

    while((**ptr = getchar()) != '\n')
        (*ptr)++;
        
    **ptr = '\0';

    int len = (*ptr - orig);
    *ptr = orig;
    
    return len;
}


int main() {
    printf("\nEnter new line: ");
    int len = 0;
    for(int i = 0; i < 10; i++) {
        
        if((len = readline(&readlines[i])) > 0)
            printf("\n(Previous: %d) Enter new line: ", len);

        else break; 
    }
    
    printcontents(readlines, 10);
    return 0;
}
