#include <stdio.h>
#include <string.h>


void reverse_word_while(char arr[], int n) {
    int i = 0, j = 0;
    while(j < n) {
   
        if(a[j] == ' ') {
            for(int init = i, final = j - 1; init < final; init++, final--) {
                char temp = arr[init];
                arr[init] = arr[final];
                arr[final] = temp;
                printf("\nSwapping %c and %c", arr[init], arr[final]);
            }
            i = j + 1;
        }
        j++;
    } 
}


int main() {
    char arr[] = "Hi this is Rajat";
    //reverse_word(arr, 0, strlen(arr)); 
    reverse_word_while(arr, strlen(arr));
    printf("\n\n%s\n\n", arr);
    return 0;
}
