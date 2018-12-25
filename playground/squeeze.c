#include <stdio.h>

void squeeze(char [], char []);

int main() {
    char original[] = "To be deleted";
    char offwithit[] = "abc";
    squeeze(original, offwithit);
    printf("\n%s\n", original);
    return 0;
}

void squeeze(char org[], char tbd[]) {
    int org_index = 0;
    for(int i = 0; org[i] != '\0'; i++) {
        for(int j = 0; tbd[j] != '\0'; j++) {
            if(org[i] == tbd[j]) // matches
                break;
            if(tbd[j + 1] == '\0')
                org[org_index++] = org[i];
        }
    }
    org[org_index] = '\0';
}
