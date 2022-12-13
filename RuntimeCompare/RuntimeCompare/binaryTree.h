#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node* left;
	Node* right;

	Node()
	{
		left = right = NULL;
	}
	Node(T value);
	Node* nodeCreator(T data);
	Node* nodeInsertion(Node* root, T data); //Not reliant on vector, called in func with vector
	void vectorTree(vector<T> dataSet); //Loop through the given vector and create Nodes from the i value to create a tree
	void deleteNode(Node* root, T value);
	Node* SearchBT(Node* root, T key);
	void heapify(Node* root, T value);//sort1 as is
	void quickSortBT(Node* root);//sort2
	//Utility funcs for sorting
	void dataSwap(Node* firstVal, Node* secondVal);
	Node* partitionBT(Node* root);
};