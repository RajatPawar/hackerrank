#include <stdio.h>

int fun(int *p, int c) {
    printf("\nCall fun(%d, %d)", *p, c);
    c = c - 1;
    if(c == 0) return 1;
    *p = *p + 1;
    return (*p * fun(p, c));
}

int main() {
    int p = 5, c = 5;
    printf("\n%d\n", fun(&p, c));
    return 0;
}
