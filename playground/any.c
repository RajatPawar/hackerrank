#include <stdio.h>

int any(char [], char []);

int main() {
    char original[] = "To be deleted";
    char offwithit[] = "ac";
    int pos = any(original, offwithit);
    printf("\n%d\n", pos);
    return 0;
}

int any(char org[], char tbd[]) {
    for(int i = 0; org[i] != '\0'; i++) {
        for(int j = 0; tbd[j] != '\0'; j++) {
            if(org[i] == tbd[j]) // matches
               return i;
        }
    }
    return -1;
}
