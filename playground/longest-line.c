#include <stdio.h>
#include <limits.h>

#define MAX_LINE    1000

int mygetline(char curr_line[], int maxlen) {
    int c, counter = 0;
    while(1) {
        c = getchar();
        if(c == '\n') break;
        if(counter < maxlen) curr_line[counter] = c;
        counter++;
    }
    if(counter < maxlen) curr_line[counter] = '\0';
    else curr_line[maxlen - 1] = '\0';
    return counter;
}

void copy(char to[], char from[], int maxlen) {
    int counter = 0;
    while((from[counter] = to[counter]) != '\0' && counter < maxlen)
        counter++;
}


int main() {
    int current_len = 0; // Length of current line 
    int max_len = 0; // Length of max line
    char current_line[MAX_LINE + 1];
    char max_line[MAX_LINE + 1];

    while(((current_len = mygetline(current_line, MAX_LINE)) > 0)) {
        if(current_len == INT_MAX) {
            printf("Line was too long to be processed. Breaking");
        }
                if(current_len > max_len) {
                    max_len = current_len;
                    copy(current_line, max_line, MAX_LINE);
                }
                
    }

    printf("\nMax length: %d\n", max_len);
    for(int i = 0; max_line[i] != '\0'; i++) {
        printf("%c", max_line[i]);
    }
    return 0;
}

