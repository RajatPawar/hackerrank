#include <iostream>

class TreeNode {
    public:
        TreeNode *left, *right;
        int data;

        TreeNode(int data) : left(nullptr), right(nullptr), data(data) {}
};

int min(int a, int b) {
    return (a >=b) ? b : a;
}

int min_depth(TreeNode *root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    if(root) {
        return (min(1 + min_depth(root->left), 1 + min_depth(root->right)));
    }
    return 0;
}

int main() {
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->left->left = new TreeNode(30);
    root->left->left->left = new TreeNode(30);
    root->left->left->left->right = new TreeNode(30);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    root->right->right->right = new TreeNode(20);
    printf("\nmin depht: %d\n", min_depth(root));
    return 0;
}
