#include <stdio.h>
#include <string.h>

#define sizeint(X) (sizeof(X)/sizeof(int)) 

main() {
    int nw = 0, c, nc = 0, counter = 0;
    int length[100];
    memset(length, -1, sizeof(length)/sizeof(int));

    while((c = getchar()) != '$') {
        if(c == '\t' || c == '\n' || c == ' ') {
            nw++;
            length[counter++] = nc;
            nc = 0;
        }
        else nc++;
    }
    
    int max = -100;
    for(int i = 0; i < sizeint(length) && length[i] != -1; i++) {
        if(length[i] > max) max = length[i];
    }
    
    printf("\n\n");

    for(int i = max; i > 0; i--) {
        for(int j = 0; j < sizeint(length) && length[j] != -1; j++) {
            if(length[j] == i) {
                printf("\t|");
                length[j]--;
            }
            else printf("\t");
        }
        printf("\n");
    }
    printf("\n");
    // Headers
    for(int i = 0; i < sizeint(length) && length[i] != -1; i++) {
        printf("\tWord %d", i + 1);
    }

   


}
