#include <stdio.h>

int glob;
int test[] = {12, 3, 3, 3,1,1};

long a = 10L * 2512L * 12421L * 1251L;

int main() {
    void *ptr;
    int *ptri;
    printf("Sizeof: usignedint: %d, FLOAT: %d, LONG DOUBLE: %d, VOID: %d, VOIDPTR: %d, INTPTR: %d, LONGINT: %d, SHORTINT: %d, INT: %d, LONG: %d, DOUBLE: %d, SHORT: %d CHAR: %d", sizeof(unsigned int), sizeof(float), sizeof(long double), sizeof(void), sizeof(ptr), sizeof(*ptri), sizeof(long int), sizeof(short int), sizeof(int), sizeof(long),sizeof(double), sizeof(short), sizeof(char));

    int local = sizeof(test);
    const int glob = 5;
    char a = 'X';
    printf("%d", local);
    //printf("\n\nGlob: %d, local: %d, char: %c, intchar: %d, octal: %d", glob, local, a, a, sizeof(0177));

}
