#include <stdio.h>

int bitcount(unsigned x) {
    int set = 0;
    int bitcounttest = 0;
    // Until the shift or AND results a 0
    while(x) {
        // Deletes right most set bit (increment and shift to right)
        x = (x & (x-1));
        x >>= 1;
        set++;
    }
    return set;
}

int main() {
    unsigned x = 255;
    printf("Set bits are: %d", bitcount(x));
    return 0;
}
