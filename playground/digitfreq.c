#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int *arr = calloc(10, sizeof(int));
    char *str = NULL;

    size_t size;

    int read = getline(&str, &size, stdin);
    realloc(str, strlen(str) + 1);
    char *till = str + strlen(str);

    while(str < till) {
        if(*str >= '0' && '9' >= *str) {
            arr[*str - '0']++;
        }
        str++;
    }
    printf("sizeof arr: %d \n sizeof int : %d\n", sizeof(arr[]), sizeof(int)); 
    for(int i = 0; i < 10; i++) 
        printf("%d ", arr[i]);

    return 0;
}

