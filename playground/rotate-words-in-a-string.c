#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 10
#define MAX_WORDS       20

void rotate_words(char arr[], int rot) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int i = 0;

    strcpy(words[i], strtok(arr, " "));
    
    while(words[i] != NULL) {
        //printf("\n i is %d and word is %s", i, words[i]);
        strcpy(words[++i], strtok(NULL, " "));
    }

    for(int j = (i + 1) - rot, counter = 0; counter < rot; j = (j + 1) % (i + 1), counter++) 
        printf(" %s ", words[j]);
}

int main() {
    char arr[15] = "Hi I am Rajat";
    rotate_words(arr, 4);
    return 0;
}
