#include <iostream>
#include "binaryTree.h"
using std::cin;
using std::cout;


int main()
{
	binaryTree bTree;

	bTree.buildbinaryTree();
	int count = bTree.publicCountLeaves();

	cout << count;
	
}
