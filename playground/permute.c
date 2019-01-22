#include <stdio.h>
#include <string.h>

void permute(char *a, int left, int right) {
    if(left == right) {

    printf("\n %s", a);
        return;
    }

    //printf("\nNEW CALL");
    // Start with 0 till n in the first case - fix ith char & swap with left
    for(int i = left; i < right; i++) {
        //swap(a[i], a[left])
    //    printf("\nDEBUG: Swapping %c with %c", a[i], a[left]);
        char temp = a[i];
        a[i] = a[left];
        a[left] = temp;

        permute(a, i + 1, right);
    }
}

int main() {
    char str[] = "abc";
    permute(str, 0, strlen(str));
    return 0;
}
