#include <stdio.h>

#define DEBUG(param, fspecifier) printf(#param " = " #fspecifier "\n", param)

int main() {
    int x = 3;
    float b = 1.56;
    DEBUG(x, %d);
    DEBUG(b, %f);
    return 0;
}
