#include <stdio.h>

void print(int *arr, int curr, int lim) {
    if(curr == lim) return;
    printf(" %d ", arr[curr]);
    print(arr, curr + 1, lim);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    print(a,0, 6);
    return 0;
}
