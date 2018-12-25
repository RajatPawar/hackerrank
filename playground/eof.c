#include <stdio.h>

main() {

    static int c, tabs, blanks, newlines;
    while((c = getchar()) != EOF) {
        if(c == '\t') tabs++;
        else if(c == '\n') newlines++;
        else if(c == ' ') blanks++;
        else putchar(c);
        printf("\nTab: \\t: \t");
    }
    printf("\nBlanks: %d, newlines: %d, tabs: %d", blanks, newlines, tabs);
}

