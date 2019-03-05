#include <iostream>
#include <queue>
#include <map>

using namespace std;

typedef struct Node {
    struct Node *left, *right;
    int data;
} Node;

Node* node(int data) {
    Node *temp = new Node;
    temp->data = data;
    return temp;
}

int leaves_print(Node *root, multimap<int, int> &m, int level) {
    if(!root) return 0;
    if(!root->left && !root->right) {
        cout<<endl<<root->data;
        return level + 1;
    }

    level = leaves_print(root->left, m, level) + leaves_print(root->right, m, level);
    
    m.insert(pair<int, int>(level, root->data));
    
    return level;
}

void process(multimap<int, int> &m) {
    for(multimap<int, int>::iterator x = m.begin(); x != m.end(); x++) {
        cout<<endl<<x->second;
    }
}

void print_bottom_leaves(Node *root) {
    multimap<int, int> m;
    leaves_print(root, m, 0);
    process(m);
}

int main() {
    /*Node *root = node(1);
    root->left = node(2);
    root->left->left = node(4);
    root->left->left->left = node(10);
    root->left->left->right = node(11);

    root->left->right = node(5);
    root->left->right->left = node(6);
    root->left->right->right = node(7);
    root->left->right->right->left = node(8);
    root->left->right->right->right = node(9);

    root->right = node(12);
    root->right->left = node(13);
    root->right->right = node(14);
    */

    Node *root = node(1);
    root->right = node(3);
    root->right->left = node(6);
    root->right->right = node(7);

    root->left = node(2);
    root->left->left = node(4);
    root->left->left->left = node(8);
    root->left->left->left->left = node(9);
    root->left->left->left->right = node(10);
    root->left->left->left->left->left = node(11);
    root->left->left->left->left->right = node(12);

    print_bottom_leaves(root);
    return 0;
}
