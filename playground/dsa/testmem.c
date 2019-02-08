#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*) malloc(6 * sizeof(int));
    free(p);
    p[3] = 4;
    for(int i = 0; i < 6; i++) printf("%d ", p[i]);
    return 0;
}
