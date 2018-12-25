#include <stdio.h>

char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void iota(int n, int b, char s[]) {
    int i, sign;
    
    if((sign = n) < 0) 
        n = -n;
    i = 0;

    do {
        s[i++] = arr[n % b];
    } while((n /= b) > 0);
    
    if(sign < 0) s[i] = '-';
    else i--;
    s[i + 1] = '\0';
  
    char temp;
    for(int j = 0; i > j; j++, i--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    char *prefix;

    if(b == 16) prefix = "0x";
    else if(b == 8) prefix = "0";
    else if(b == 10) prefix = "";
    
    printf("%s%s\n", prefix, s);
}

int main() {
    char s[15];
    iota(-123, 16, s);
    return 1;
}
