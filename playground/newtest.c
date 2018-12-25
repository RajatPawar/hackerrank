#include <stdio.h>

int main() {
    int n = 255;
    n = n & ~077;
    printf("%d", n);
}
