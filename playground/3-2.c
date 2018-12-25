#include <stdio.h>

void escape(char s[], char t[]) {
    for(int i = 0, j = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\t': 
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
        }
    }
    printf("\nSource: %s", t);
    printf("\nDest: %s", s);
}

int main() {
    char arr[100];
    char src[100] = "eagskj\nwqg wq  sa"
                     "$$sagasgsag   " 
                     "";
    escape(arr, src);
    return 0;
}
