#include <stdio.h>
#include <stdlib.h>

#define NO          0
#define POSSIBLE    1
#define COMMENT     2

void remove_comments(char* filea) {
    FILE *filei = fopen(filea, "r+");
    FILE *filec = fopen("modified.c", "w+");
    int c, i = 0;
    int entering_comment = NO;
    
    // Get size of file to initalise buffer
    fseek(filei, 0, SEEK_END);
    int size = ftell(filei);
    rewind(filei);
    
    
    char* buff = malloc(sizeof(char) * size);

    while((c = getc(filei)) != EOF) {
        if(c == '/' && entering_comment == NO) entering_comment = POSSIBLE;
        else if(c == '/' && entering_comment == POSSIBLE) {
            entering_comment = COMMENT;
            buff[i] = ' ';
            buff[i - 1] = ' ';
            continue;
        }
        else if(entering_comment == COMMENT && c != '\n') {
            buff[i++] = ' ';
            continue;
        }
        else if(c == '\n') entering_comment = NO;
        buff[i++] = c;
    }
    buff[i] = EOF;
    for(int j = 0; buff[j] != EOF; j++) putc(buff[j], filec);

    fclose(filei);
    fclose(filec);
}

int main() {
    char* filea;

    printf("\nEnter file: ");
    scanf("%s", filea);
    
    remove_comments(filea);
    //print_file(file);
    
    return 0;
}
