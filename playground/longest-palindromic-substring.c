#include <stdio.h>
#include <string.h>

int longest_palin_sub(char str[], int len) {
    int matrix[len][len];
    for(int i = 0; i < len; i++) 
        matrix[i][i] = 1;
    return 1;
}

int main() {
    char input[] = "absafqabba";
    printf("\n%d\n", longest_palin_sub(input, strlen(input)));
    return 0;
}
