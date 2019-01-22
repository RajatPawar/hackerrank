#include <stdio.h>


void permute(char *s, int left, int right) {

    static int cnt;

    if(left == right) {
        printf("\n%s cnt - %d", s, ++cnt);
    }
    else {
        for(int i = left; i < right; i++) {
            char temp = s[left];
            s[left] = s[i];
            s[i] = temp;
            permute(s, left + 1, right);
            char x= s[left];

             s[left] = s[i];
             s[i] = x;
        }
    }
}

int main() {
    char a[4] = "aabc";
    permute(a, 0, 4);
    return 0;
}
