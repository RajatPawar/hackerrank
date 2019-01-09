#include <stdio.h>

int a = 77;
int main()
{
    int a=10,b=9;
    {
        int a=0;
        printf("%d",b);
        {
            int b=5;
            extern a;
            printf("%d",a);
        }
        printf("%d",b);

    }
    return 0;
}
