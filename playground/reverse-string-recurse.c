#include <stdio.h>

void reverse(char *arr, int from, int to) {
    
   // if(from > to) return;
    
    char temp = arr[from];
    arr[from] = arr[to];
    arr[to] = temp;   

    reverse(arr, from + 1, to - 1); 
}

int main() {
    char arr[] = "This";
    reverse(arr, 0, sizeof(arr) - 2); // Subtracting delimiter and 1th index
    printf("\n%s\n", arr);
    return 0;
}
