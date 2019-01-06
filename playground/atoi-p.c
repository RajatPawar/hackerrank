#include <stdio.h>
#include <ctype.h>

int atoi(char *s) {
    int res = 0;
    while(*s != '\0') {
        res = (10 * res) + (*s++ - '0');
    }
    return res;
}

int main() {
    char a[] = "1239";
    printf("%d", atoi(a));
    return 0;
}
