#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node *left;
    struct node *right;
} node;

node* talloc() {
    return (node*) malloc(sizeof(node));
}


void initnode(node **tnode, int data) {
    (*tnode)->data = data;
    (*tnode)->left = (*tnode)->right = NULL;
    (**tnode).left = NULL;
}

void freenode(node **tnode) {
    free(*tnode);
}

int main() {
    node *root = talloc();
    initnode(&root, 12);
    
    
    return 0;
}
