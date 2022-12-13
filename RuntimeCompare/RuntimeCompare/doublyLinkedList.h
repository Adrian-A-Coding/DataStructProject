#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class D>
class DLList //Doubly linked list
{
public:
	D data;
	DLList* left, right, headRef;

	DLList()
	{
		left = right = NULL;
	}
	DLList(D value);
	void linkedVector(vector<D> dataGroup); //Data sets will be taken and call the append func to creat a doubly linked list
	DLList* appendInsert(DLList* node, D value);
	void beginingDeletion();
	void searchDLL(DLList* head, D key);
	void quickSortDLL(DLList* node, DLList* head);
	void quickSortCaller(DLList* headRef);
	void mergeSort(DLList* headRef);//sort2

	//Utility funcs for sorting
	DLList* partitionDLL(DLList* node, DLList* headRef);
	DLList* tailNode(DLList* headRef);
	void swapData(D* first, D* second);
	DLList* spliter(DLList* headRef);
	DLList* merger(DLList* firstNode, DLList* secondNode);
};

//Funcs are defined below

template <typename D>
DLList<D>::DLList(D value)
{
	data = value;
	left = right = NULL;
}

template <typename D>
void DLList<D>::linkedVector(vector<D> dataGroup)
{
	DLList* start = NULL;
	for (int k = 0; k <= dataGroup.size(); k++)
	{
		appendInsert(start, dataGroup[k]);
	}
}

template <typename D>
DLList<D>* DLList<D>::appendInsert(DLList* node, D value)
{
	DLList* newNode = new DLList(value);
	if (!node)
	{
		newNode->left = NULL;
		headRef = newNode;
		return;
	}
	newNode->right = node->right;
	node->right = newNode;
	newNode->left = node;
	if (newNode->right != NULL)
	{
		newNode->right->left = newNode;
	}
}

template <typename D>
void DLList<D>::beginingDeletion()
{
	headRef = headRef->right;
}

template <typename D>
void DLList<D>::searchDLL(DLList* head, D key)
{
	DLList* tempNode = head;
	while (head->data != key || head->right != NULL)
	{
		tempNode = tempNode->right;
	}
	if (tempNode->data != key)
	{
		cout << "That piece of data isn't present in this structure." << endl;
		return;
	}
	cout << "That data was found in the structure." << endl;
	return;
}

template <typename D>
void DLList<D>::quickSortDLL(DLList* node, DLList* head)
{
	if (head != NULL && node != head && node != head->right)
	{
		DLList* part = partitionDLL(node, head);
		quickSortDLL(node, part->left);
		quickSortDLL(part->right, head);
	}
}

template <typename D>
void DLList<D>::quickSortCaller(DLList* headRef)
{
	DLList* tail = tailNode(headRef);
	quickSortDLL(headRef, tail);
}

template <typename D>
void DLList<D>::mergeSort(DLList* headRef)
{
	if (!headRef || !headRef->right)
	{
		return headRef;
	}
	DLList* second = spliter(headRef);
	headRef = mergeSort(headRef);
	second = mergeSort(second);
	return merger(headRef, second);
}

template <typename D>
DLList<D>* DLList<D>::partitionDLL(DLList* node, DLList* headRef)
{
	D pivot = headRef->data;
	DLList* temp = node->left;
	for (DLList* current = node; current != headRef; current = current->right)
	{
		if (current->data <= pivot)
		{
			temp = (temp == NULL) ? node : temp->right;
			swapData(&(temp->data), &(headRef->data));
		}
	}
	temp = (temp == NULL) ? node : temp->right;
	swapData(&(temp->data), &(headRef->data));
	return temp;
}

template <typename D>
void DLList<D>::swapData(D* first, D* second)
{
	D tem = *first;
	*first = *second;
	*second = tem;
}

template <typename D>
DLList<D>* DLList<D>::tailNode(DLList* headRef)
{
	while (headRef && headRef->right)
	{
		headRef = headRef->right;
	}
	return headRef;
}

template <typename D>
DLList<D>* DLList<D>::spliter(DLList* headRef)
{
	DLList* one = headRef, * two = headRef;
	while (one->right && one->right->right)
	{
		one = one->right->right;
		two = two->right;
	}
	DLList* tem = two->right;
	two->right = NULL;
	return tem;
}

template <typename D>
DLList<D>* DLList<D>::merger(DLList* firstNode, DLList* secondNode)
{
	if (!firstNode)
	{
		return secondNode;
	}
	if (!secondNode)
	{
		return firstNode;
	}
	if (firstNode->data < secondNode->data)
	{
		firstNode->right = merger(firstNode->right, secondNode);
		firstNode->right->left = firstNode;
		firstNode->left = NULL;
		return firstNode;
	}
	else
	{
		secondNode->right = merger(firstNode, secondNode->right);
		secondNode->right->left = secondNode;
		secondNode->left = NULL;
		return secondNode;
	}
}