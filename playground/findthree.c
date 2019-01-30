#include <stdio.h>

void find_three(int [], int, int, int []);
void print_arr(int [], int);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("\nEnter k to find: ");
    
    int k = -1;
    scanf("%d", &k);

    int res[3];
    find_three(arr, sizeof(arr)/sizeof(int), k, res);
    print_arr(res, sizeof(res)/sizeof(int));

    return 0;
}

void swap(int a[], int to, int from) {
    int temp = a[to];
    a[to] = a[from];
    a[from] = temp;
}

int partition(int a[], int low, int high) {
    int pivot = high;
    int tillWhereSmall = low - 1;
    int i = low;

    while(i < high) {
        printf("\nChecking %d (idx %d) > %d (idx %d)", a[pivot], pivot, a[i], i);
        if(a[pivot] > a[i]) {
            tillWhereSmall++;
            printf("\nDEBUG: Swapping %d and %d", tillWhereSmall, i);
            swap(a, tillWhereSmall, i);
        }
        i++;
    }
    tillWhereSmall++;
    swap(a, tillWhereSmall, pivot);
    return tillWhereSmall;
}

void quick_sort(int a[], int low, int high) {
    printf("\nDEBUG: Being called as quick_sort(a, %d, %d)", low, high);
    int pivot = partition(a, low, high);
    if(low < high) {
        printf("\nDEBUG: Calling qs(a, %d, %d) && qs(a, %d, %d)", low, pivot - 1, pivot + 1, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot, high);
    }
}

void find_three(int a[], int n, int k, int res[]) {
    int j, l;

    quick_sort(a, 0, n - 1);
    print_arr(a, n);

    for(int i = 0; i < n - 2; i++) {
        j = i + 1;
        l = n - 1;
        int sum;

        while(j < l) {
            sum = a[i] + a[j] + a[l];
            if(sum == k) {
                res[0] = a[i];
                res[1] = a[j];
                res[2] = a[l];
                return;
            }
            else if(sum > k) l--;
            else j++;
        }   
    }
    res[0] = res[1] = res[2] = -1;
}

void print_arr(int arr[], int n) {
    printf("\n");
    for(int i = 0; i < n; i++) 
        printf(" %d", arr[i]);
}
