#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "SLList.h"
#include "doublyLinkedList.h"
#include "binaryTree.h"

using namespace std;
using namespace std::chrono;

int main()
{
	vector<string> smallOutputs;
	vector<string> largeOutputs;
	//Above are empty vectors to hold the data from the two different csv files
	//Below are temporary strings to hold the data as it's moved from file to vector
	string holding;
	ifstream smallFile("smallDataSet.csv");
	while (getline(smallFile, holding))
	{
		smallOutputs.push_back(holding);
	}
	//The the larger data will be transferred now
	ifstream largeFile("largeDataSet.csv");
	while (getline(largeFile, holding))
	{
		largeOutputs.push_back(holding);
	}

	//Create the h file of each data strucutre to be template classes
	//This is the small data set done for the linked list, can be swapped with the others for testing purposes
	//For current intents and purposes this will demonstrate the single linked list
	LList<string> Alist;
	Alist.vectorList(smallOutputs);
	auto startNodeRemoval = high_resolution_clock::now();
	Alist.nodeRemoval(Alist.headNode, "A HEALTH QUEST");
	auto stopNodeRemoval = high_resolution_clock::now();
	auto nodeRemovalDuraton = duration_cast<microseconds>(stopNodeRemoval - startNodeRemoval);
	cout << "The node removal process took " << nodeRemovalDuraton << " microseconds." << endl;
	auto startNodeSearch = high_resolution_clock::now();
	Alist.nodeSearch(Alist.headNode, "THREE MOONS");
	auto stopNodeSearch = high_resolution_clock::now();
	auto nodeSearchDuration = duration_cast<microseconds>(stopNodeSearch - startNodeSearch);
	cout << "The process to search for a node took " << nodeSearchDuration << " microseconds." << endl;
	auto startSort1 = high_resolution_clock::now();
	Alist.quickSortLL(Alist.headNode, Alist.tailNode(Alist.headNode));
	auto stopSort1 = high_resolution_clock::now();
	auto sort1Duration = duration_cast<microseconds>(stopSort1 - startSort1);
	cout << "The process to sort the list using quick sort took " << sort1Duration << " microseconds." << endl;
	//These can be swapped for a larger dataset and for a doubly linke list and binary tree as needed.
}