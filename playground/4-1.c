#include <stdio.h>
#include <string.h>

int rgetline(char arr[], int max) {
    char c;
    int i = 0;
    
    while((c = getchar()) != '\n' && c != EOF) 
        arr[i++] = c;
    
    arr[i++] = '\n';
    
    arr[i] = '\0';
    return i;
}

int find_occurence(char arr[], int arr_n, char tbf[], int tbf_n) {
    for(int i = arr_n - 1; i >= tbf_n - 1; i--) {
        for(int k = i, j = tbf_n - 1; k >= 0 && j >= 0; k--, j--) {
            if(arr[k] != tbf[j]) break;
            if(j ==  0) return ((i + 1) - tbf_n);
        }
    }
    return -1;
}

int main() {
    char arr[100];
    int found;
    int len;
    while((len = rgetline(arr, 100)) > 0) {
        found = -1;
        if((found = find_occurence(arr, len, "rajat", 5)) != -1)
            printf("Found it at %d in %s", found, arr);
        memset(arr, 0, sizeof(arr));
    }
    return 1;
}
