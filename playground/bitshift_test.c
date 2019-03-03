#include <stdio.h>


// Description of problem - Cracking the coding interview Q5.1 PG 115 (5th edition)
int shift(int n, int m, int i, int j) {
    return ((((m & 1) << i) | (n & ~(~1 << i))) & n);
}

int main() {
    printf("\n%d\n", shift(1024, 19, 2, 6));
    return 0;
}
