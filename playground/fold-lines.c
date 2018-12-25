#include <stdio.h>

#define FOLD_LENGTH     (50)
#define VARIANCE        (5)

void process_line_folding(char*, int, int, int);
int rgetline(char*);

int main() {
    char* curr_line;
    int curr_len;

    while((curr_len = rgetline(curr_line)) > 0) {
        process_line_folding(curr_line, curr_len, FOLD_LENGTH, VARIANCE);
    }

    return 0;
}

int rgetline(char* arr) {
    int c, counter = 0;
    while((c = getchar()) != '\n') {
        arr[counter++] = c;
    }
    arr[counter] = '\0';
    return counter;
}

void process_line_folding(char* arr, int len, int fold_len, int variance_org) {
    if(len < fold_len) {
        printf("%s", arr);
        return;
    }    
    
    int index = fold_len, lower = 0, variance;
    while(index < len) {
        
        variance = variance_org;

        while((arr[index - variance] != ' ' || arr[index - variance] != '.') && variance > 0) {
            variance--;
        }      
        for(int i = lower; i < (index - variance); i++) {
            putchar(arr[i]);
        }
        lower = (index - variance);
        index += fold_len;
        printf("\n");
    }
    if(index + fold_len > len) {
        for(int i = lower; i < len; i++) {
            putchar(arr[i]);
        }
    }
}
