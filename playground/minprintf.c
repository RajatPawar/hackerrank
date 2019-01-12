#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
    int arg;
    float farg;
    char *carg, *p;
    
    va_list ap;
    va_start(ap, fmt); 

    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        else switch(*(++p)) {
            case 'd': {
                  arg = va_arg(ap, int);
                  printf("%d", arg);
                  break;
            }
            case 'f': {
                farg = va_arg(ap, double);
                printf("%f", farg);
                break;
            }
            case 's': {
                carg = va_arg(ap, char *);
                for(; *carg; carg++) 
                    putchar(*carg);
                break;
            }
            default:
                putchar(*p);
        }
    }
    va_end(ap);
}

int main() {
    minprintf("%s is %d chars long bab", "hello", 5);
    return 0;
}
