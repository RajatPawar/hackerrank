#include <stdio.h>

#define uc unsigned char

uc rotright(uc num, int pos) {
    return ((num >> pos) | ((~(1 << pos) & num) << (8 - pos)));
}

int main() { 

    uc x = 75;
    printf("%d", rotright(x, 3));
    return 0;
}
