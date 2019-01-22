#include<stdio.h>
#include <string.h>

struct p{
       int len;
       char str[8];
};

int main(){
       struct p a, *b;

       a.len = 12;
       strcpy(a.str, "Hello");
    
       b = &a;
       char *pt = (char*) b;
       printf("\nADD a: %x, b: %x, b+1: %x, pt: %x", &a, b, b+1, pt);
       
       for(; pt < (char*) (b + 1); pt++) {
           printf("\nDEBUG: ptr is now at %x less than %x, printing %c (%d)", pt, (void *) (b + 1), *pt, *pt);
       }
   
       printf("\nDEBUG: ptr is now %x", pt);
       return 0;
}
