#include <stdio.h>
#include <string.h>


#define MAX_LINE    1000
#define MAX_NUMS     10

int mygetline(char src[], int maxlen) {
    int c, count = 0;
    while((c = getchar()) != '\n' && count < maxlen) {
        src[count++] = c;
    }
    
    if(count < maxlen) src[count] = '\0';
    else src[maxlen - 1] = '\0';
    return count;
}

void copy(char src[], char dest[][MAX_LINE], int line) {
    int i = 0;
    while((dest[line][i] = src[i]) != '\0')
        i++;
}

int main() {
    int curr_len = 0;
    char curr_line[MAX_LINE];
    char print_lines[MAX_NUMS][MAX_LINE];
    int tbp_line = 0;

    memset(print_lines, -1, sizeof print_lines);
    while((curr_len = mygetline(curr_line, MAX_LINE)) > 0) {  // Break on an empty input 
        if(curr_len > 80) {
            copy(curr_line, print_lines, tbp_line);
            tbp_line++;
        }
    }
    printf("\n");
    for(int i = 0; i < MAX_NUMS && print_lines[i][0] != -1; i++) {
        for(int j = 0; print_lines[i][j] != '\0'; j++) {
            putchar(print_lines[i][j]);
        }
        printf("\n");
    }
    return 0;
}

