#include <iostream>
#include <map>
#include <queue>

using namespace std;

class TreeNode {
    private: // By default
        int data, hor_dist;
        TreeNode *left, *right;
        static int node_count;

    public:
        TreeNode(int data): data(data) {
            if(!node_count) hor_dist = 0;
        }
        void create_left(int);
        void create_right(int);
        TreeNode* get_left();
        TreeNode* get_right();
        int get_data();
        int get_hd();
};

int TreeNode :: node_count = 0;

void TreeNode :: create_left(int data) {
    this->left = new TreeNode(data);
    this->left->hor_dist = this->hor_dist - 1;
}

void TreeNode :: create_right(int data) {
    this->right = new TreeNode(data);
    this->right->hor_dist = hor_dist + 1;
}

TreeNode* TreeNode :: get_left() {
    return this->left;
}

TreeNode* TreeNode :: get_right() {
    return this->right;
}

int TreeNode :: get_data() {
    return this->data;
}

int TreeNode :: get_hd() {
    return this->hor_dist;
}

void traverse(TreeNode *root, map<int, int> *hd) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);

    TreeNode *temp;
    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if(!hd->count(temp->get_hd()))
            hd->insert({temp->get_hd(), temp->get_data()});
        if(temp->get_left() != NULL) q.push(temp->get_left());
        if(temp->get_right() != NULL) q.push(temp->get_right());
    }
}


void print_top_view(TreeNode *node) {
    if(!node) return;
    std :: map<int, int> hd;
    std :: map<int, int> :: iterator itr;
    
    traverse(node, &hd);

    for(itr = hd.begin(); itr != hd.end(); itr++) 
        cout<<"\n"<<itr->second;
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->create_left(2);
    root->create_right(3);
    root->get_left()->create_right(4);
    root->get_left()->get_right()->create_right(5);
    root->get_left()->get_right()->get_right()->create_right(6);

    print_top_view(root);
    return 0;
}
