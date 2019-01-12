#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int maxlen = 100;
    char *line = (char*) malloc(maxlen), 
         *line_two = (char*) malloc(maxlen);
    FILE *source, *dest;

    if(argc != 3) {
        printf("\nUSAGE: 7-6 file1 file2\n");
        exit(1);
    }

    source = fopen(argv[1], "r");
    dest = fopen(argv[2], "r");

    while(!strcmp(fgets(line, maxlen, source), fgets(line_two, maxlen, dest))) 
        ;
    printf("\nLine at which they differ: %s %s\n", line, line_two);
    return 0;
}
