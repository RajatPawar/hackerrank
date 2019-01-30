#include <stdio.h>
#include <string.h>

void findinstring(char *str, char *sub, int sub_len, int left, int right, int *min, int *max) {

    if(left < right) {
    
        int hash[26];
        for(int i = 0; i < strlen(sub); i++) 
        {
            //printf("\nDEBUG: Calculating occurences");
            hash[sub[i] - 'a']++;
        }
        
        int count = 0;
        for(int i = left; i < right; i++) 
        {
            //printf("\nDEBUG: Comparing");
            if(hash[str[i] - 'a']-- > 0) count++;
        }

        if(count == sub_len)
        {

            //printf("\nDEBUG: count = sub_len");
            *min = left;
            *max = right;
        }


        printf("\nDEBUG: findinstring(str, sub, %d, %d, %d, %d, %d)", sub_len, left + 1, right, *min, *max);
        printf("\nDEBUG: findinstring(str, sub, %d, %d, %d, %d, %d)", sub_len, left, right - 1, *min, *max);
        findinstring(str, sub, sub_len, left + 1, right, min, max);
        findinstring(str, sub, sub_len, left, right - 1, min, max);

}

int main() {
    char *str, *sub;
    str = "Hello, this is bullshit I think";
    sub = "tis";
    int min = 0, max = strlen(str);
    findinstring(str, sub, 3, 0, strlen(str), &min, &max);
    printf("%d to %d", min, max);
    return 0;
}
