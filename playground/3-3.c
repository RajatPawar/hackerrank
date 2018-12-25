#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 15

void expand(char dest[], char src[]) {
    // Print any leading/trailing -
    int i = 0, j = strlen(src) - 1, leading = 0, trailing = 0;
    
    for(; src[i] == '-'; i++) 
        leading++;

    for(; src[j] == '-'; j--)
        trailing++;

    char sym[MAX_SYMBOLS], counter = 0;
    memset(sym, 0, sizeof(sym));

    for(; i <= j; i++) {
        if(src[i] == '-') continue;
        sym[counter++] = src[i];
    }

    for(int l = 0; l < leading; l++) printf("-");
    
    for(int k = 0; k < sizeof(sym); k++) {
        if(sym[k + 1] - sym[k] <= 26 && isalpha(sym[k]) && isalpha(sym[k + 1])) {
            // Expand alphabetical
            for(char a = sym[k]; a <= sym[k + 1]; a++) {
                printf("%c ", a);
            }
        }
        else if(isdigit(sym[k + 1]) && isdigit(sym[k]) && sym[k + 1] - sym[k] < 10) {
            for(int z = sym[k]; z <= sym[k + 1]; z++) 
                printf("%c ", z);
        }
    }

    for(int t = 0; t < trailing; t++) printf("-");
}

int main() {
    char arr[15], src[15] = "-a-}";
    expand(arr, src);
   // expand(arr, "-a-z");
   // expand(arr, "a-z0-9-");
}
