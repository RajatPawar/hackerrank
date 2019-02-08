#include <iostream>

int getlen(char *s) {
    char *tr = s;
    while(*tr++) printf("%c", *tr);
    return (tr - s);
}

int main() {
//    Test t;
    char *str = "HelloWow";
    printf("\n%d\n", getlen(str));
    return 0;
}
