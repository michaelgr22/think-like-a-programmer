#include "binaryTree.h"
#include <iostream>

int binaryTree::privateCountLeaves(treePtr rootPtr) {
    if (rootPtr == NULL) return 0;
    if (rootPtr->right == NULL && rootPtr->left == NULL)
        return 1;
    int leftCount = privateCountLeaves(rootPtr->left);
    int rightCount = privateCountLeaves(rootPtr->right);
    return leftCount + rightCount;
}
int binaryTree::publicCountLeaves() {
    return privateCountLeaves(_root);
}

void binaryTree::buildbinaryTree() {

    _root->data = 1;

	binaryTreeNode* left = new binaryTreeNode;
	left->data = 2;
	binaryTreeNode* right = new binaryTreeNode;
	right->data = 3;

	_root->left = left;
	_root->right = right;

	left->left = NULL;
	left->right = NULL;
	right->left = NULL;
	right->right = NULL;
}

