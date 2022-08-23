#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

namespace bst
{
	template<typename T>
	struct node
	{
		T data;
		node* leftNode = nullptr;
		node* rightNode = nullptr;
	};

	template<typename T>
	node<T>* findMinRightSubTree(node<T>* target)
	{
		if (nullptr == target) 
		{
			return target;
		}
		else if (nullptr == target->leftNode )
		{
			return target;
		}
		else
		{
			return findMinRightSubTree(target->leftNode);
		}
	}

	template<typename T>
	node<T>* search(node<T>* target, T data)
	{
		if (nullptr == target)
		{
			return target;
		}
		else 
		{
			if (data < target->data)
			{
				target = search(target->left, data);
			}
			else if (data > target->data)
			{
				target = search(target->right, data);
			}

			return target;
		}
	}

	template<typename T>
	void insertNode(node<T>* &target, T data )
	{

		if (nullptr == target)
		{
			target = new node<T>();
			target->data = data;
			target->leftNode = NULL;
			target->rightNode = NULL;
		}
		else 
		{
			if (data < target->data)
			{
				insertNode(target->leftNode, data);
			}
			else
			{
				insertNode(target->rightNode, data);
			}
		}
	}

	template<typename T>
	node<T>* deleteNode(node<T>* &target, T data)
	{
		if (nullptr == target) 
		{
			return nullptr;
		}
		else 
		{
			if (data < target->data) 
			{
				target->leftNode = deleteNode(target->leftNode, data);
			}
			else if (data > target->data) 
			{
				target->rightNode = deleteNode(target->rightNode, data);
			}
			else 
			{
				if ( nullptr == target->leftNode && nullptr == target->rightNode) 
				{
					delete target;
					return nullptr;
				}
				else if (nullptr == target->leftNode) 
				{
					node<T>* temp = target;
					target = target->rightNode;
					delete temp;
				}
				else if (nullptr == target->rightNode) 
				{
					node<T>* temp = target;
					target = target->leftNode;
					delete temp;
				}
				else 
				{
					node<T>* min = findMinRightSubTree(target->rightNode);
					target->data = min->data;
					target->rightNode = deleteNode(target->rightNode, target->data);
				}
			}
		}

		return target;
	}

	template<typename T>
	void inOrder(node<T>* target)
	{
		if (nullptr != target) 
		{
			inOrder(target->leftNode);
			std::cout << target->data << " ";
			inOrder(target->rightNode);
		}
	}

	template<typename T>
	void preOrder(node<T>* target)
	{
		if (nullptr != target)
		{
			std::cout << target->data << " ";
			preOrder(target->leftNode);
			preOrder(target->rightNode);
		}
	}

	template<typename T>
	void postOrder(node<T>* target)
	{
		if (nullptr != target)
		{
			postOrder(target->leftNode);
			postOrder(target->rightNode);
			std::cout << target->data << " ";
		}
	}
}

#endif