#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class L>
class LList //Linked List
{
public:
	L data;
	LList* next, *headNode;

	LList()
	{
		headNode = next = NULL;
	}
	LList(L value);
	void vectorList(vector<L> dataList); //Will take the data files and call the insert func to create a list
	void insertPush(LList* headRef, L value);
	void nodeRemoval(LList*& head, L key);
	bool nodeSearch(LList* head, L key);
	LList* quickSortLL(LList* head, LList* tail);
	LList* insertionSort(LList* headRef);
	//Utility funcs for Linked lists sorting
	LList* tailNode(LList* currNode);
	LList* listPartition(LList* head, LList* tail, LList* newHead, LList* newTail);
};

//All the functions for this class below

template <typename L>
LList<L>::LList(L value)
{
	data = value;
	headNode = next = NULL;
}

template <typename L>
void LList<L>::vectorList(vector<L> dataList)
{
	LList* head = NULL;
	auto startListInsert = high_resolution_clock::now();
	for (int j = 0; j <= dataList.size(); j++)
	{
		insertPush(head, dataList[j]);
	}
	auto stopListInsert = high_resolution_clock::now();
	auto insertDuration = duration_cast<microseconds>(stopListInsert - startListInsert);
	cout << "Done with the insert time duration being " << insertDuration << " microseconds" << endl;
}

template <typename L>
void LList<L>::insertPush(LList* headRef, L value)
{
	LList* newNode = new LList(value);
	newNode->next = headRef;
	headRef = newNode;
}

template <typename L>
void LList<L>::nodeRemoval(LList*& head, L key)
{
	if (!head)
	{
		cout << "No such element is present." << endl;
		return;
	}
	if (head->data == key)
	{
		LList* temp = head;
		head = head->next;
		delete(temp);
		return;
	}
}

template <typename L>
bool LList<L>::nodeSearch(LList* head, L key)
{
	if (head == NULL)
	{
		cout << "This node doesn't exist in the linked list." << endl;
		return false;
	}
	if (head->data == key)
	{
		cout << "The element " << head->data << "does exist in the linked list." << endl;
		return true;
	}
	return nodeSearch(head->next, key);
}

template <typename L>
LList<L>* LList<L>::quickSortLL(LList* head, LList* tail)
{
	if (!head || head == NULL)
	{
		return head;
	}
	LList* newHead = NULL, * newTail = NULL;
	LList* pivot = listPartition(head, tail, newHead, newTail);
	if (newHead != pivot)
	{
		LList* temp = newHead;
		while (temp->next != pivot)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = quickSortLL(newHead, temp);
		temp = tailNode(newHead);
		temp->next = pivot;
	}
	pivot->next = quickSortLL(pivot->next, newTail);
	return headNode = newHead;
}

template <typename L>
LList<L>* LList<L>::insertionSort(LList* headRef)
{
	LList* sorted = NULL;
	LList* currNode = headRef;
	while (currNode != NULL)
	{
		LList* next = currNode->next;
		insertionSort(currNode);
		currNode = next;
	}
	headNode = currNode;
}

template <typename L>
LList<L>* LList<L>::tailNode(LList* currNode)
{
	while (currNode != NULL && currNode->next != NULL)
	{
		currNode = currNode->next;
	}
	return currNode;
}

template <typename L>
LList<L>* LList<L>::listPartition(LList* head, LList* tail, LList* newHead, LList* newTail)
{
	LList* pivot = tail;
	LList* previous = NULL, * current = head, * tail = pivot;
	while (current != pivot)
	{
		if (current->data < pivot->data)
		{
			if ((*newHead) = NULL)
			{
				(*newHead) = current;
			}
			previous = current;
			current = current->next;
		}
		else
		{
			if (previous)
			{
				previous->next = current->next;
			}
			LList* temp = current->next;
			current->next = NULL;
			tail->next = current;
			tail = current;
			current = temp;
		}
	}
	if ((*newHead) == NULL)
	{
		(*newHead) = pivot;
	}
	(*newHead) = tail;
	return pivot;
}