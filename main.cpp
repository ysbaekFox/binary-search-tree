#include <iostream>
#include "bst.h"

int main()
{
	bst::node<int>* root = nullptr;

	bst::insertNode(root, 10);
	bst::insertNode(root, 5);
	bst::insertNode(root, 12);
	bst::insertNode(root, 7);
	bst::insertNode(root, 4);
	bst::insertNode(root, 6);

	bst::deleteNode(root, 5);

	bst::preOrder(root);
	std::cout << std::endl;
	bst::inOrder(root);
	std::cout << std::endl;
	bst::postOrder(root);
	std::cout << std::endl;

	return 0;
}