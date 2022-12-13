#include "SLList.h"

template <typename L>
LList<L>::LList(L value)
{
	data = value;
	headNode = next = NULL;
}

template <typename L>
void LList<L>::vectorList(vector<L> dataList)
{
	//Here is where the count down for the runtime should begin as the insert will be called in a loop
	for (int j = 0; j <= dataList.size(); j++)
	{
		insertPush(dataList[j]);
	}
	//It should then end here, otherwise it'd have to happen once elsewhere for the comparison
	//Should be variable that holds this function's runtime such as LLInsertRuntime
	cout << "Done";
}

template <typename L>
void LList<L>::insertPush(LList** headRef, L value)
{
		LList* newNode = new LList(value);
		newNode->next = (*headRef);
		(*headRef) = newNode;
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