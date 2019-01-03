#include <stdio.h>
#include <string.h>


#define MAX_WORDS   10

void rotate(char arr[], int n, int rot) {
    int word_index = 0, words = 1, word_indices[MAX_WORDS] = {0};
    for(int i = 0, j = 0; i < n; i++) {
        if(arr[i] == ' ') {
            words++;
            word_indices[++j] = i;
        }
    }

    // Counted number of words

    int from = word_indices[words - (rot % words)] + 1; // Got the space index of the word to begin with
    
    char temp;
    int to = 0;
    
    while(from < n) {
        temp = arr[from];
        // Right shift
        for(int i = from - 1; i >= to; i--) 
            arr[i + 1] = arr[i];
        arr[to++] = temp;
        from++;
    }

    for(int i = n - 1; i >= to; i--)
             arr[i + 1] = arr[i];

    arr[to] = ' ';
    arr[from] = '\0';
    printf("\n%s\n", arr);
}


int main() {
    char arr[] = "Hi I am Rajat";
    rotate(arr, strlen(arr), 2);
    return 0;
}
