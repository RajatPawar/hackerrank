#include <stdio.h>

#define swap(t,x,y) t temp = x; x = y; y = temp;

int main() {
    int a = 5;
    int b = 11;
    printf("\n%d %d", a, b);
    swap(int, a, b);
    printf("\n%d %d", a, b);
    
    int p[3] = {12, 13, 14};
    float s[3] =   {1.2, 1.3, 1.4};
    int *ptr = p;
    float *fptr = s;

    printf("%d %d %d", *ptr, *(ptr+1), *(ptr+2));
    printf("%f %f %f", *fptr, *(fptr + 1), *(fptr + 2));
    
    return 0;
}
