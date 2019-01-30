#include <stdio.h>
#include <string.h>
void prints(char *s, int left, int right) {
    printf("\n");
    if(left < right) {
        for(int i = left; i < right; i++) printf("%c", s[i]);
        prints(s, left + 1, right);
        prints(s, left, right - 1);
    }
}

int main() {
    char *test = "Hello";
    prints(test, 0, strlen(test));
    return 0;
}
