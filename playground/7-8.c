#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

int main(int argc, char *argv[]) {
    int page = 1;
    int maxlen = 100;
    char buffer[maxlen];

    while(--argc > 0) {
        FILE *fp = fopen(*(++argv), "r");
        clear();
        printf("----------------- %s (Page %d) --------------- \n", *argv, page++);
        while(fgets(buffer, maxlen, fp)) {
            puts(buffer);
        }
        getchar(); 
    }

    return 0;
}
