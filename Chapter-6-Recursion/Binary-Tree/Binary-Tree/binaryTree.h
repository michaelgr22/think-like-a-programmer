#pragma once
class binaryTree {
public:
    int publicCountLeaves();
    void buildbinaryTree();
private:
    struct binaryTreeNode {
        int data;
        binaryTreeNode* left;
        binaryTreeNode* right;
    };
    typedef binaryTreeNode* treePtr;
    treePtr _root = new binaryTreeNode;
    int privateCountLeaves(treePtr rootPtr);
    
};

