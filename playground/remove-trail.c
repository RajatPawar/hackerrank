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

void copy(char* src, char dest[][MAX_LINE], int line) {
    int i = 0;
    while((dest[line][i] = src[i]) != '\0')
        i++;
}

char* removetrails(char src[], int max) {
    int start = 0, end = max;
    while(1) {
        if(src[start] == ' ') src[start++] = '\0';
        else if(src[end] == ' ') src[end--] = '\0';
        else break;
    }
    return &src[start];
}

int main() {
    int curr_len = 0;
    char curr_line[MAX_LINE];
    char print_lines[MAX_NUMS][MAX_LINE];
    int tbp_line = 0;

    memset(print_lines, -1, sizeof print_lines);
    while((curr_len = mygetline(curr_line, MAX_LINE)) > 0) {  // Break on an empty input 
        char* str = removetrails(curr_line, curr_len);
        copy(str, print_lines, tbp_line);
        tbp_line++;
    }
    printf("\n");
    for(int i = 0; i < MAX_NUMS && print_lines[i][0] != -1; i++) {
        printf("%s", print_lines[i]);
        printf("\n");
    }
    return 0;
}

