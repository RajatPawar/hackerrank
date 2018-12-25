#include <stdio.h>

unsigned char setbits(unsigned char org, unsigned char pos, unsigned char num, unsigned char dest) {
    return ((dest << num) | ((org >> (pos + 1 - num)) &  ~(~0 << num)));
}

int main() { 
    unsigned char x = 16;
    unsigned char y = 255;
    printf("%d", setbits(x, 5, 2, y));
    printf("\n%d", y << 2); return 0;
}
