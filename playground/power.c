#include <stdio.h>

double pow2(double, int);

int main() {
    for(int i = -3; i < 3; i++) {
        printf("2 raised to %d: %.2f\n", i, pow2(2, i));
        printf("3 raised to %d: %.2f\n", i, pow2(3, i));
    }
    return 0;
}

double pow2(double base, int exp) {
    double result = 1.0;
    if(exp > 0) {
        for(int i = exp; i > 0; i--) {
            result = result * base;
        }
    }
    else if(exp < 0) {
        for(int i = exp; i < 0; i++) {
            result = result * (1/base);
        }
    }
    return result;
}
