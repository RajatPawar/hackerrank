#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define YES 1
#define NO 0
int COMMENT;

int getword(char *word, int limit) {
    int c;
    // Skipped all the whites
    while(isspace(c = getc(stdin)))
            ;
    // Get the valid token condition
    if(c != EOF) 
        *word++ = c;
    
    if(c == '/' && ((c = getc(stdin)) == '*' || c == '/')) 
        // Comment
        COMMENT = YES;
    else {
        ungetc(c, stdin);
        ungetc(*(--word), stdin);
    }

    if(COMMENT) ;
    // If it is a number, just add it to the char arr and throw it back
    if(!isalpha(c)) {
        *word = '\0';
        return c;
    }
    
    for(; --limit > 0; word++) {
        if(!isalnum(*word = getc(stdin)) && *word != '_') {
            ungetc(*word, stdin);
            break;
            // Found a space during read so break, otherwise keep reading
        }
    }
    *word = '\0';
    return word[0];
}

int main() {
    char arr[10];
    while(getword(arr, 10) != '\n') 
        printf("\n%s\n", arr);
    return 0;
}
