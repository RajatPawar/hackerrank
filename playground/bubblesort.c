#include <stdio.h>

#define ASC  1
#define DESC 0

void bubblesort(int *arr, int n, int order) {
    for(int i = 0; i < n; i++) {
        
        // The i loop tells us the position till where j has to compare 
        // Or the number of elems that are in the correct place

        for(int j = 0; j < n - i - 1; j++) {
           
            // The j loop actually considers two adj elems to compare
            // them and swap if the order is not correct
            
            if(order ? (arr[j + 1] < arr[j]) : (arr[j + 1] >  arr[j])) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print_arr(int *a, int n) {
    for(int i = 0; i < n; i++) 
        printf(" %d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {12, 5, 5, 1, 6, 10, 4, 3, 8},
        n = sizeof(a)/sizeof(int);
    
    print_arr(a, n);
    bubblesort(a, n, DESC);
    print_arr(a, n);
    
    return 0;
}
