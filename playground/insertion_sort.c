#include <stdio.h>

void insertion_sort(int a[], int n) {
    for(int i = 0; i < n; i++) {
        int j = i,
            temp = a[i];

        while(j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = temp;
    }
}

int main() {
    int a[] = {56, 16, 6, 71, 2};
    insertion_sort(a, 5);
    for(int i = 0; i < 5; i++) printf(" %d ", a[i]);
    return 0;
}
