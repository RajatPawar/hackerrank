#include <stdio.h>

#define MAX_LINE 1000

int rgetline(char line[]) {
    int c, i = 0;
    while((c = getchar()) != '\n' && i < MAX_LINE) {
        line[i++] = c;
    }
    return i;
}

void reverse_print(char* arr, int len) {
    while(len > 0) {
        putchar(arr[--len]);
    }
}

int main() {
    int curr_len;
    char curr_line[MAX_LINE];
    while((curr_len = rgetline(curr_line)) > 0) {
        reverse_print(curr_line, curr_len);
    }
    return 0;
}
