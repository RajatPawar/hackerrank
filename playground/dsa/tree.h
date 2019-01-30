#ifndef __TREE_INCLUDED__   // if x.h hasn't been included yet...
#define __TREE_INCLUDED__   //   #define this so the compiler knows it has been included

class TreeNode;

class Tree {
    TreeNode *root;

    public:
    Tree()
}

template <class Generic>
class TreeNode {

    Generic data;
    TreeNode *left, *right;

    public:
    Generic get_content();
    bool is_valid();
};

#endif 
