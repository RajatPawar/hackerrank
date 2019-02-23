#include <stdio.h>

struct test {
    int a;
    char b;
    double x;
};

int main() {
    struct test t;
    struct test *tptr = &t;
    tptr->a = 1;
    char *ptr = (char*) &t;
    printf("t = %x, tptr = %x, ptr = %d, ptr + 1 = %d, ptr + 2 = %d\n", &t, tptr, *ptr, *(ptr + 1), *(ptr + 2));
    return 0;
}
