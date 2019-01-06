#include <stdio.h>

char *getString()
{
  char *str = "GfG"; /* Stored in read only part of shared segment */

  /* No problem: remains at address str after getString() returns*/
  return str;
}

int main()
{
    char *p = getString();
    printf("%c", *p);
    printf("%c", *(p + 1));
    return 0;
}
