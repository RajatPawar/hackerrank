#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} Node;

Node* new(int data) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    return temp;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    if(!node) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int get_balance_factor(Node *node) {
    if(!node) return 0;
    return height(node->left) - height(node->right);
}

Node* left_rotation(Node *node) {
    Node* right_subtree = node->right;

    // If we make right_subtree root now, and node its child, then 
    // the left child of right_subtree is going to be bigger than right_subtree
    // which is inaccurate, so we need to shift it to be node's child
    
    Node* tree_that_needs_to_be_shifted_if_exists = right_subtree->left;
    
    right_subtree->left = node;
    node->right = tree_that_needs_to_be_shifted_if_exists;


    return right_subtree;
}

Node* right_rotation(Node *node) {
    Node* left_subtree = node->left;
    Node* tree_that_needs_to_be_shifted_if_exists = left_subtree->right;

    // If we make left_subtree root now, and node its child, then right
    // child of left_subtree will be smaller than left_subtree so we need
    // to make it nodes left child (smaller than node)
    
    left_subtree->right = node;
    node->left = tree_that_needs_to_be_shifted_if_exists;

    return left_subtree;
}

Node* insert(Node *root, int data) { 
    if(!root) return new(data);
    if(data >= root->data) {
        root->right = insert(root->right, data);
    }
    else if(data < root->data) {
        root->left = insert(root->left, data);
    }

    int balance_factor = get_balance_factor(root); 
    
    if(balance_factor > 1 && data < root->left->data) {
        // Left left case
        printf("\nLL");
        return right_rotation(root);
    }
    else if(balance_factor > 1 && data > root->left->data) {
        // Left right case
        printf("\nLR");
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }

    if(balance_factor < -1 && data > root->right->data) {
        // Right right case
        printf("\nRR");
        return left_rotation(root);
    }
    else if(balance_factor < -1 && data < root->right->data) {
        // Right left case
        printf("\nRL");
        root->right = right_rotation(root->left);
        return left_rotation(root);
    }

    return root;
}

Node* search(Node *root, int data) {
    if(!root) return NULL;
    if(data == root->data) return root;
    if(data >= root->data)
        return search(root->right, data);
    else if(data < root->data)
        return search(root->left, data);
}

void preorder(Node *root) {
    if(root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node *root = new(1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    printf("\n");
    preorder(root);
    printf("\n");
    return 0;
}
