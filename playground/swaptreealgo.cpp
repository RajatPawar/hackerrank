#include <iostream>
#include <map>
#include <queue>

using namespace std;

class TreeNode {
    private: // By default
        int data, hor_dist;
        TreeNode *left, *right;

    public:
        TreeNode(int data): data(data) {}
        void create_left(int);
        void create_right(int);
        TreeNode* get_left();
        TreeNode* get_right();
        void set_right(TreeNode*);
        void set_left(TreeNode*);
        int get_data();
};

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

void TreeNode :: set_right(TreeNode *right) {
    this->right = right;
}

void TreeNode :: set_left(TreeNode *left) {
    this->left = left;
}

void traverse(TreeNode *root, int swap_level) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    q.push((TreeNode*) -1);

    swap_level -= 1;
    int level = 0;

    TreeNode *temp = NULL;

    while(!q.empty()) {
        temp = q.front();
        q.pop();
        
        if(temp == (TreeNode*) -1) {
            level++;
            temp = q.front();
            q.pop();
        }

        if(level == swap_level) {
            cout<<endl<<"Right: "<<temp->get_right()->get_data()<<" & left: "<<temp->get_left();
            TreeNode *swap = temp->get_left();
            temp->set_left(temp->get_right());
            temp->set_right(swap);
            cout<<endl<<"Right: "<<temp->get_right()->get_data()<<" & left: "<<temp->get_left();
            break;
        }

        if(temp == (TreeNode*) -1) break;

        if(temp->get_left() != NULL) 
            q.push(temp->get_left());
        if(temp->get_right() != NULL) 
            q.push(temp->get_right());

        q.push((TreeNode*) -1);
    }
    cout<<endl<<"Level is "<<level;
}

void print_preorder(TreeNode *root) {
    if(!root) return;
    cout<<"\n"<<root->get_data();
    print_preorder(root->get_left());
    print_preorder(root->get_right());
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->create_left(2);
    root->create_right(3);
    root->get_left()->create_right(4);
    root->get_right()->create_right(5);

    print_preorder(root);
    for(int i = 0; i < 3; i++) cout<<endl;
    traverse(root, 1);
    for(int i = 0; i < 3; i++) cout<<endl;
    print_preorder(root);
    return 0;
}
