#include <stdio.h>

int main() {
    int *a = {12, 13, 14, 15, 16};
    printf("%d %d %d", sizeof(a), sizeof(*a), sizeof(a[0]));
    return 0;
}
