#include <iostream>

class Heap {
    int *arr, size;
    public:

    Heap(int size): size(size) {
        arr = new int[size];
    }

    void insert(int);
    int get_min();
};

int Heap :: get_min() {
    return arr[0];
}

void Heap :: insert(int data) {
    int idx = 0,
        root_idx = (2 * idx),
        left_idx = (2 * idx) + 1,
        right_idx = (2 * idx) + 2;
    //while(root_idx)
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

