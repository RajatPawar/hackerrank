#include <stdio.h>
#include <ctype.h>

int main() {
    char c = 0;
    while((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
    return 0;
}
