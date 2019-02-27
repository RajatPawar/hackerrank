#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

// getline - returns length of the string and stores the line in the supplied array with length

int rgetline(char arr[], int len) {
    int i = 0;
    while((arr[i] = getchar()) != '\n' && i < len)
            i++;
    arr[i] = '\0';
    return i;
}

int readlines(char *arr[], int lines) {
    int i = 0, len = 0;
    char temp[MAX_LINE_LENGTH];
    while((len = rgetline(temp, MAX_LINE_LENGTH)) > 0 && i < lines) {
        char *ptr = malloc(MAX_LINE_LENGTH * len);
        strcpy(ptr, temp);
        arr[i++] = ptr;
    }
    return i;
}

void writelines(char *arr[], int lines) {
    for(int i = 0; i < lines; i++) {
        printf("\n%s", arr[i]);
    }
}

int comparator(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main() {
    int lines = 0;
    char *arr[10];
    if((lines = readlines(arr, 5)) > 0) 
    {
        //writelines(arr, lines);
        //qsort(arr, lines - 1, sizeof(char), comparator);
    }
    printf("\nLines: %d", lines);
    writelines(arr, lines);
    return 0;
}
