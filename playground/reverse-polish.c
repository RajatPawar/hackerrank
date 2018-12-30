#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// Definitions

#define NUMBER          254
#define MAX_SIZE        10
#define MAX_STACK_SIZE  10
#define MIN_STACK_SIZE  -1
#define MAX_BUFF_SIZE   10
#define YES             1
#define NO              0

// Forward declarations

int gettok(char []); // Function to store operand/operator in char array and return its type
double pop();        // Function to pop from stack
void push(double);   // Function to push into stack
int rgetchar();     // Function to make it possible to ungetchar 
void rungetchar();   // Push back char on buffer to read again
int is_stack_empty();

// Helper functions for getting a char

char buffer[MAX_BUFF_SIZE];
int buffer_pointer = 0;

int rgetchar() {
    if(buffer_pointer > 0) return buffer[--buffer_pointer];
    else return getchar();
    
}

void rungetchar(int c) {
    if(buffer_pointer >= MAX_BUFF_SIZE) 
        printf("\nERROR: Buffer full\n");
    else buffer[buffer_pointer++] = c; 
} 

int main() {
    
    int token;
    char oper[MAX_SIZE];
    double v;

    memset(oper, '\0', sizeof(oper));

    while((token = gettok(oper)) != EOF) {
        switch(token) {
            case NUMBER:
                push(atof(oper));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                push(pop() - pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                v = pop();
                if(v != 0.0) {
                    push(pop() / v);
                }
                else printf("\nERROR: Zero division\n");
                break;
            case '\n':
                v = pop();
                if(is_stack_empty())
                    printf("%4.2f\n\n", v);
                else
                    push(v);
                break;
            case ' ':
                break;
            default:
                break;
        }
    }
    return 0;
}

// get next operator or operand
int gettok(char op[]) {
    static char unchar; 
    char c;
    int i = 0;
    int negative = NO;

    while((c = rgetchar()) == ' ' || c == '\t') 
        ;

    if(c == '-') // Negatives
    {
        c = rgetchar(); 
        if(isdigit(c)) negative = YES;
        
        // Put it back after peeking 
        rungetchar(c);
        c = '-';
    }

    // The above skips all spaces and tabs that lead the expression
    if(!isdigit(c) && c != '.' && !negative) // Something weird or an operator!
    {
        return c;
    
    }
    if(isdigit(c) || negative) {
        
        printf("\nGoing into it and char is %c", c);
        if(negative == YES)
        {
            negative = !negative;
            op[i++] = '-';
            c = rgetchar();
        }

        printf("\nChar is now %c", c);
        op[i] = c; 
        
        while(isdigit(op[++i] = (c = rgetchar()))) 
            ;
        // Collected integer part
    }
    if(c == '.') 
    {
        // Add decimal
        op[i++] = c;
        while(isdigit(op[++i] = (c = rgetchar()))) 
            ;
    }
    // Once you are done collecting, end string
    // If you weren't a number, you were returned long ago

    op[i + 1] = '\0';
    printf("\n%s\n", op);

    if(c != EOF) // it is not a number, something else that we need to put back on the buffer to make it available to be processed again
        unchar = c;
    return NUMBER;
}

double stack[MAX_STACK_SIZE];
int top = -1;

void push(double val) {
    if(top != MAX_STACK_SIZE) {
        stack[top++] = val;
    }
    else printf("\nERROR: Stack is full\n");
}

double pop() {
    if(top != MIN_STACK_SIZE) {
        return stack[--top];
    }
    else printf("\nERROR: Stack is empty\n");
    return 0.0;
}

int is_stack_empty() {
    return (top == MIN_STACK_SIZE);
}
