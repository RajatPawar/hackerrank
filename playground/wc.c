#include <stdio.h>

#define OUT 1
#define IN  0

main() {
    int c, nl, nc, nw;
    nl = nc = nw = 0;
    int STATE = OUT;

    while((c = getchar()) != EOF) {
        // New character so increment
        nc++;
        // If it is a newline, then increment newline counter
        if(c == '\n') {
            nl++;
        }

        // If it is a space, tab or a newline, you have just gotten OUT of a word
        if(c == ' ' || c == '\t' || c == '\n') {
            STATE = OUT;
        }

        // If it is not any of the above, then it is a character (number or letter) and you have begun a new word
        else if(STATE == OUT) {
          STATE = IN;
          nw++;
        }    
    }
    printf("Lines: %d | Words: %d | Chars: %d", nl, nw, nc);
}
