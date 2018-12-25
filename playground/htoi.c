#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char []);

int main() {
    printf("Hex string: %s, integer value: %d", "AF", htoi("AF"));
    return 0;
}

int htoi(char arr[]) {
    int n = 0, temp;
    for(int i = 0; i < strlen(arr); i++) {
        // For ASCII

        if(!isdigit(arr[i])) temp = arr[i] - '7';
        else arr[i] = temp - '0';
        n = (n * 16) + temp;
    }
    return n;
}

