#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE   26

main() {
    int c, freq[ALPHABET_SIZE];
    memset(freq, 0, ALPHABET_SIZE * sizeof(int));
    while((c = getchar()) != '$') {
        if('a' < c && c < 'z') {
            freq[c - 'a']++;
        }
        else if('A' < c && c < 'Z') {
            freq[c - 'A']++;
        }
    }

    int max = -1;
    for(int i = 0; i < sizeof(freq)/sizeof(int); i++) {
        if(freq[i] > max) max = freq[i];
    }
    for(int i = max; i > 0; i--) {
        for(int j = 0; j < sizeof(freq)/sizeof(int); j++) {
            if(freq[j] == i) {
                printf("|\t");
                freq[j]--;
            }
            else printf("\t");
        }
        printf("\n");
    }

    for(int i = 0; i < 26; i++) {
        printf("-\t");
    }
    printf("\n");

    for(int i = 'a'; i < 'z'; i++) {
        printf("%c\t", i);
    }
    printf("\n");
}
