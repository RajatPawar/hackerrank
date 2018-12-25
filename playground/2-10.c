#include <stdio.h>
#include <ctype.h>

// Returns lowercase for uppercase, and just returns itself for everything else
char lower(char x) {
    return (x >= 'A' && 'Z' >= x) ? ((x - 'A') + 'a') : x;
}

int main() {
    printf("\n%c %c %c\n", lower('G'), lower('1'), lower('a'));
    return 0;
}
