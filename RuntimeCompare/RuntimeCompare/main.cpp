#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SLList.h"
#include "doublyLinkedList.h"
#include "binaryTree.h"

using namespace std;

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
	//This is the small data set done for the linked list
	LList<string> Alist;
	Alist.vectorList(smallOutputs);
	//Call the funcs for Alist and calculate the duration between the calls. Use bubble sort for this one
	//This is the linked list large data set
	LList<string> ABigList;
	ABigList.vectorList(largeOutputs);
}