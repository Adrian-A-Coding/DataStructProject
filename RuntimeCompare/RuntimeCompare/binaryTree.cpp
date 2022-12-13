#include "binaryTree.h"

template <typename T>
Node<T>::Node(T value)
{
	data = value;
	left = right = NULL;
}

template <typename T>
Node<T>* Node<T>::nodeCreator(T data)
{
	Node* newNode = new Node(data);
	return newNode;
}

template <typename T>
Node<T>* Node<T>::nodeInsertion(Node* root, T data)
{
	if (!root)
	{
		root == nodeCreator();
		return root;
	}
	if (data > root->data)
	{
		root->right = nodeInsertion(root->right, data);
	}
	else if(data < root->data)
	{
		root->left = nodeInsertion(root->left, data);
	}
	return root;
}

template <typename T>
void Node<T>::vectorTree(vector<T> dataSet)
{
	Node* root = NULL; //Initial node for the recursive use later with insertion
	for (int t = 0; t <= dataSet.size(); t++)
	{
		nodeInsertion(root, dataSet[t]);
	}
	cout << "Complete";
}

template <typename T>
void Node<T>::deleteNode(Node* root, T value)
{
	if (!root)
		return NULL;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->data == value)
			return NULL;
		else
			return root;
	}
	Node* keyNode = NULL;
	Node* tem, last;
	vector<Node*> holder;
	holder.push_back(root);
	while (!holder.empty())
	{
		tem = holder.front();
		holder.pop_back();
		if (tem->data == value)
			keyNode = tem;
		if (tem->left)
		{
			last = tem;
			holder.push_back(tem->left);
		}
		if (tem->right)
		{
			last = tem;
			holder.push_back(tem->right);
		}
	}
	if (keyNode != NULL)
	{
		keyNode->data = tem->data;
		if (last->right == tem)
			last->right = NULL;
		else
			last->left = NULL;
		delete(tem);
	}
	return root;
}

template <typename T>
Node<T>* Node<T>::SearchBT(Node* root, T key)
{
	if (root == NULL || root->data == key)
	{
		return root;
	}
	if (root->data < key)
	{
		return search(root->right, key);
	}
	return search(root->left, key);
}

template <typename T>
void Node<T>::quickSortBT(Node* root)
{
	if (root != NULL && root != root->right && root != root->left)
	{
		Node* part = partitionBT(root);
		quickSortBT(part->left);
		quickSortBT(part->right);
	}
}

template <typename T>
void Node<T>::heapify(Node* root, T value)
{
	if (!root)
	{
		root = nodeCreator(value);
		return root;
	}
	Node* largest = root;
	if (largest->data < largest->left->data)
		largest = largest->left;
	if (largest->data < largest->right->data)
		largest = largest->right;
	if (largest->data != value)
	{
		dataSwap(root, largest);//should swap root->data with the largest as value will be the initial root->data
		heapify(largest, largest->data);//This demonstrates above point
	}
}

template <typename T>
void Node<T>::dataSwap(Node* firstVal, Node* secondVal)
{
	Node* temp = *firstVal;
	*firstVal = *secondVal;
	*secondVal = temp;
}

template <typename T>
Node<T>* Node<T>::partitionBT(Node* root)
{
	T piv = root->data;
	Node* tem = root->left;
	for (Node* current = root; current != tem; current = current->right)
	{
		if (current->data <= piv)
		{
			tem = (tem == NULL) ? root : tem->right;
			dataSwap(&(tem->data), (&root->data));
		}
	}
	tem = (tem == NULL) ? root : tem->right;
	dataSwap(&(tem->data), (&root->data));
	return tem;
}