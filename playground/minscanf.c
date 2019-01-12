#include <stdio.h>
#include <stdarg.h>

void minscanf(char *fmt, ...) {
    char *sarg, *traverser;
    int arg;
    float farg;

    va_list arg_pointer;
    va_start(arg_pointer, fmt);
    
    for(traverser = fmt; *traverser; traverser++) {
        if(*traverser != '%') {
           getchar();
           continue; 
        }
        else {
            switch(*(++traverser)) {
                case 'd': {
                    int *to = va_arg(arg_pointer, int*);
                    scanf("%d", to);
                    break;
                }
                case 's': {
                     char c;
                     char *str = va_arg(arg_pointer, char *);
                     while((c = getchar()) != '\n') *str++ = c;
                     *str = '\0';
                     break;
                }
                default:
                    printf("No match");
            }
            continue;
        }
    }

    va_end(arg_pointer);
}

int main() {
    int a;
    char *str;
    minscanf("%d what %s", &a, str);
    printf("a is %d and str is %s", a, str);
    return 0;
}
