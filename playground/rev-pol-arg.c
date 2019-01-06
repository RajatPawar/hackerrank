#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ELEMS  10

int top = 0;
static int stack[MAX_ELEMS];

int pop() {
    if(--top >= 0) return stack[top];
    else return INT_MAX;
} 

void push(int v) {
    if(top != MAX_ELEMS)
        stack[top++] = v;
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("ERROR: No arguments supplied");
    }
    else {
        while(--argc > 0) {
            if(isdigit(*(++argv)[0])) // skips program name 
                push(atoi(*argv));
            
            else {
                int one = pop();
                int two = pop();
                switch(*argv[0]) {
                    case '+':
                        push(one + two);
                        break;
                    case '-':
                        push(two - one);
                        break;
                    case '*':
                        push(one * two);
                        break;
                    case '/': 
                        if(one != 0)
                            push(two/one);
                        break;
                    default:
                        printf("\nERROR: Invalid operator");
                        break;
                }
            }
        }
    }
    int result = pop();
    if(pop() == INT_MAX) printf("\n\nResult: %d", result);
    else printf("\nERROR: Invalid expression");
    return 0;
}
