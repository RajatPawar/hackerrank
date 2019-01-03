#include <stdio.h>

char *rstrcat(char *source, char *add) {
    char *orig = source;
    while(*(source++) != '\0')
        ;
    source--;

    while((*(source++) = *(add++))) 
        ; 
    *source = '\0';
    return orig;
}

int main() {
    char src[] = "Hello";
    char dest[] = " Rajat";
    printf("%s", rstrcat(src, dest));
    return 0;
}
