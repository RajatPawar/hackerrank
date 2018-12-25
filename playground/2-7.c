#include <stdio.h>

unsigned char reverse(unsigned char x, int pos, int num) {
   return (x ^ (~(1 << num)  << (pos + 1 - num)));
}

int main() { 
    int arr[7] = {1, 2, 45, 3, 3, 2, 1};
    int v = 0;
    printf("\n");
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        
        printf("\nConsidering: %d ^ %d, v is now: %d", v, arr[i], (v = v ^ arr[i]));
    }
    printf("\n\n%d", v);
    return 0;
}
