#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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