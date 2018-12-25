#include <stdio.h>

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};

int binary_search(int elem, int arr[], int n) {
    int low = 0,
        high = n - 1,
        middle;

    while(low <= high) {
        middle = (low + high) / 2;
        if(arr[middle] == elem) 
            return middle;
        else if(arr[middle] > elem) {
            // Search lower half
            high = middle - 1;
        }
        else if(arr[middle] < elem) {
            // Search upper half
            low = middle + 1;
        }
    }

    return -1;
}


int main() { 
    printf("Element is present at p(sition %d in arr", binary_search(1, a, sizeof(a)/sizeof(int)));
    return 0;
}
