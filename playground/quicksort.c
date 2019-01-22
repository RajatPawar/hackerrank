#include <stdio.h>

#define ASC  1
#define DESC 0

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high, int order) {
    int tillWhereSmallDone = low - 1;
    int pivot = high;

    for(int traverser = low; traverser <= high - 1; traverser++) {
        if(order ? arr[traverser] <= arr[pivot] : arr[traverser] >= arr[pivot]) {
            // Populate in the beginning of the partition then
            tillWhereSmallDone++;
            swap(&arr[tillWhereSmallDone], &arr[traverser]);
        }
    }
    // Finally, get pivot to right position (just after tillWhereSmallIsDone)
    swap(&arr[tillWhereSmallDone + 1], &arr[pivot]);

    return (tillWhereSmallDone + 1); // place of pivot now

}

void quicksort(int *arr, int left, int right, int order) {
    if(left < right) {
        int pivot_place = partition(arr, left, right, order);

        quicksort(arr, left, pivot_place - 1, order);
        quicksort(arr, pivot_place + 1, right, order);
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
    quicksort(a, 0, n - 1, DESC);
    print_arr(a, n);
    
    return 0;
}
