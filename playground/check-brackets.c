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
    int open = 0;
    while((c = getc(filei)) != EOF) {
        if(c == '(' || c == '{') open++;
        else if(c == ')' || c == '}') open--;
    }

    if(open != 0) printf("ERROR");
    else printf("GOOD");
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
