#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

/* Head ends here */

 typedef struct TreeNode {
     double data;
     struct TreeNode *left, *right;
 } Node;

 Node *new (double data) {
   Node *temp = (Node *)malloc(sizeof(Node));
   temp->data = data;
   return temp;
 }

 double max(double a, double b) { return (a > b) ? a : b; }

 double height(Node *node) {
   if (!node)
     return 0;
   return 1 + max(height(node->left), height(node->right));
 }

 double get_balance_factor(Node *node) {
   if (!node)
     return 0;
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

 Node *insert(Node *root, int data) {
   if (!root)
     return new (data);
   if (data > root->data) {
     root->right = insert(root->right, data);
   } else if (data <= root->data) {
     root->left = insert(root->left, data);
   }

   double balance_factor = get_balance_factor(root);

   if (balance_factor > 1 && data < root->left->data) {
     // Left left case
     return right_rotation(root);
   } else if (balance_factor > 1 && data > root->left->data) {
     // Left right case
     root->left = left_rotation(root->left);
     return right_rotation(root);
   }

   if (balance_factor < -1 && data > root->right->data) {
     // Right right case
     return left_rotation(root);
   } else if (balance_factor < -1 && data < root->right->data) {
     // Right left case
     root->right = right_rotation(root->left);
     return left_rotation(root);
   }

   return root;
 }

 void median(int N, char (*s)[3], int *x) {
   double *arr = (double *)malloc(sizeof(double) * N), val;
   int counter = 0, valid_elems = 0;
   char op;

   for (int query = 0; query < N; query++) {

     op = s[query][0];
     val = *x++;

     if (op == 'a') {
       arr[counter++] = val;
     } else if (op == 'r') {
       for (int i = 0; i < counter; i++) {
         if (arr[i] == val) {
           arr[i] = __DBL_MAX__;
           break;
         }
       }
     }
     Node *root = NULL;

     for (int i = 0; i < counter; i++) {
       if (arr[i] != __DBL_MAX__) {
         root = insert(root, arr[i]);
         valid_elems++;
       }
     }
     if (!valid_elems)
       printf("Wrong!\n");
     else {
       if (valid_elems % 2 || valid_elems == 1) { // ODD
         printf("%0.0lf\n", root->data);
       } else if (!(valid_elems % 2) && valid_elems > 1) {
         double result;
         if (!root->right && root->left)
           result = (root->data + root->left->data) / 2.0f;
         if (!root->left && root->right)
           result = (root->data + root->right->data) / 2.0f;
         //if(result % 1 != 0) printf("%0.1lf\n", result);
         //else
         printf("%0.0lf\n", result);
       }
     }
     valid_elems = 0;
     }
 }

 int main() {

   // Helpers for input/output
   int i, N;

   scanf("%d", &N);
   char s[N][3];
   int x[N];

   for (i = 0; i < N; i++) {
     scanf("%s %d", &(s[i]), &(x[i]));
   }

   median(N, s, x);
	
}


