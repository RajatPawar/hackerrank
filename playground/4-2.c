#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int atoi(char s[], int from, int to) {
    int result = 0;
    for(int i = from; i < to; i++) {
        result = (10 * result) + (s[i] - '0');
    }
    return result;
}

double atof(char s[], int n) {
    int power = 0, decimal = n - 1;
    double result = 0.0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            decimal = i;
            continue;
        }
        else if(tolower(s[i]) == 'e') {
            // handle exponenti
            decimal = i - decimal;
            if(s[i + 1] == '-') {
                power = -atoi(s, i + 2, n);
            }
            else power = atoi(s, i + 1, n);
            break;
        }
        result = (10 * result) + (s[i] - '0');
    }
    
    double final = (result/pow(10.0, decimal)) * pow(10, power);
    return final;
}

int main() {
    char s[10] = "123.45e2";
    printf("%f", atof(s, strlen(s)));
    return 0;
}
