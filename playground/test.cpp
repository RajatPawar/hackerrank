#include <iostream>

int fun(int &x, int c) {
    printf("\nCall f(%d, %d)", x, c);
    c = c - 1;
    if(!c) return 1;
    x = x + 1;
    return fun(x, c) * x;
}

int main () {
    int x = 5;
    std::cout<<std::endl<<fun(x, x);
    return 0;
}
