#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <string.h>

#define MAX_STACK_SIZE  10

int top = 0;
int stack[MAX_STACK_SIZE];

int pop() {
  if(top >= 0) return stack[top--];
  else return -1;
}

void push(int val) {
  if(top == MAX_STACK_SIZE - 1) printf("Stack full");
  else stack[++top] = val;
}

int peek() {
  return stack[top];
}

void swap_top_two() {
  int v = pop();
  int d = pop();
  push(v);
  push(d);
}

int main() {
  char str[] = "Helloasgfasfgasg";
  char source[] = "Wow";
  memcpy(source, str, sizeof(str));
  return 0;
}
