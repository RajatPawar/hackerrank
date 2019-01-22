#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, char **d) {
    char *temp = *s;
    *s = *d;
    *d = temp;
}

void reverse(char **s, int from, int len) {
    char **fptr,
        **tptr,
        *temp;

    while(from < len) {
        
        fptr = &s[from];
        tptr = &s[len];
            
        //printf("\nPointing to %s and %s & from = %d, len = %d", *fptr, *tptr, from, len);    
        
        // Swap
        temp = *fptr;
        *fptr = *tptr;
        *tptr = temp;
        
        // Point to next elems
        ++from;
        --len;
    }
}

int next_permutation(int n, char **s)
{
	int size = n,
        leastImpactIndex = -1;
    while(--size > 0) {
        if(strcmp(s[size], s[size - 1]) > 0) // right most greater than left one
        {
            leastImpactIndex = size - 1;
            break;
        }
    }
    if(leastImpactIndex == -1) return 0;
    
    int j = leastImpactIndex + 1, justMaxThanLeastImpact = j, byHowMuch = 99999;
    while(j < n) {
        int greaterBy = strcmp(s[j], s[leastImpactIndex]);
        if(greaterBy <= byHowMuch && greaterBy >= 0)
            byHowMuch = greaterBy, justMaxThanLeastImpact = j;
        j++;
    }
    swap(&s[justMaxThanLeastImpact], &s[leastImpactIndex]);
    //printf("\nDebug: After one swap, the array is - ");
    //for(int i = 0; i < n; i++) { printf(" %s ", s[i]); }
    reverse(s, leastImpactIndex + 1, n - 1);
    //for(int i = 0; i < n; i++) { printf(" %s ", s[i]); }
    //printf("\n"); 
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
