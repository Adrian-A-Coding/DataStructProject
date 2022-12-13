#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	void insertPush(LList** headRef, L value);
	void nodeRemoval(LList*& head, L key);
	bool nodeSearch(LList* head, L key);
	LList* quickSortLL(LList* head, LList* tail);
	LList* insertionSort(LList* headRef);
	//Utility funcs for Linked lists sorting
	LList* tailNode(LList* currNode);
	LList* listPartition(LList* head, LList* tail, LList* newHead, LList* newTail);
};