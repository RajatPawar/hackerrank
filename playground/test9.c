#include <stdio.h>
#include <string.h>


void test(char arr[3]) {
    for(int i = 0; i < 20; i++) { printf("\nFUNCTION WALA Address: %x, %c, Strlen in func: %d\n", &arr[i], arr[i], strlen(arr)); if(i == 10) arr[i] = 'S'; 
    }
}

int main() {
    char a[5] = "hello";
    printf("\nMAINWALA EXEC: Address: %x, Size in func: %lu\n", a[5], a, sizeof(a));
    test(a);
    printf("%s", a);
    return 0;
}
