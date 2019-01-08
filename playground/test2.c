#include <stdio.h>
#include <string.h>

void swap(char* x, char* y) {
    char a[2], b[2];
    
    strcpy(a, x);
    strcpy(b, y);
    
    char temp = a[0];
    a[0] = b[0];
    b[0] = temp;

    strcpy(x, a);
    strcpy(y, b);
}

int main() {
    char ax = (void) 3;
    char* a = "a";
    char* b = "x";
    printf("\na is %s and b is %s", a, b);
    swap(a, b);
    printf("\na is %s and b is %s", a, b);
    return 0;
}
