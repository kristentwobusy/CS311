// =========================================================

//HW2P2 mergeSort
//Your name: Kristen Osborne
//Complier:  gcc
//File type: .cpp

//==========================================================
#include <iostream>
#include <vector>
using namespace std;

//prototype
void combine(vector<int> L1, vector<int> L2, vector<int>& L3);

/*The purpose of the program is to implement merge sorting. To compile,
use g++ mergeSort.cpp. There are no other files to run with the program.
The overall design is to have two lists. The data for each list is 
inputted by the user. It will take the first two elements of each list 
and compare the two. The smaller will be placed into L3. It will follow
this algorithm until there are no more elements.*/

//begin main
int main()
{
	vector<int> L1; //vector 1 that holds values inputted by user
	vector<int> L2; //vector 2 that holds values inputted by user
	vector<int> L3; //vector that holds merged sorted list of L1 and L2
	int input; //number entered by user that will be pushed into the
			   //appropriate vector
	const int MAX = 3; //this can be changed depending on desired size.
				   //for this assignment, we only want 3 per list

	cout << "Please enter 3 integers in increasing order to be placed into L1" << endl;
	for(int i = 0; i < MAX; i++) //takes in inputted number and inserts into vector
	{							//until max desired size is reached
		cout << i + 1 << ": ";
		cin >> input;
		L1.push_back(input);
	}
	cout << "Please enter 3 integers in increasing order to be placed into L2" << endl;
	for(int i = 0; i < MAX; i++)//takes in inputted number and inserts into vector
	{							//until max desired size is reached
		cout << i + 1 << ": ";
		cin >> input;
		L2.push_back(input);
	}

	combine(L1,L2,L3); //call function that will combine and sort

	cout << "The merged sort is: " << endl;
	for(int i = 0; i < L3.size(); i++) //displays elements of L3
	{
		cout << L3[i] << " ";
	}
	cout << endl;

	return 0;
} //end main


/*This function will take the elements of L1 and L2 then compare and sort
the two and place the smaller into L3. It will follow this design until
all elements are sorted in L3. The purpose of the parameters: L1 is the 
first list that gets compared. L2 is the second. L3 is where the sorted
elements are placed. L3 is then returned to main by reference. It uses 
while loops to compare L1 verses L2. They will then place the correct 
elements into the merge sorted L3.*/
void combine(vector<int> L1, vector<int> L2, vector<int>& L3)
{
	int index1 = 0; //index for L1
	int index2 = 0; //index for L2
	int index3 = 0; //index of L3

	//while there are still elements left in both L1 and L2,
	//put the smallest number in first to L3
	while(index1 != L1.size() && index2 != L2.size()) 
	{
		if(L1[index1] < L2[index2])
		{
			index3 = L1[index1];
			L3.push_back(index3);
			index1++; //incrementing index1 will move to the next element
					  //in L1 that will be compared and sorted
		}
		else
		{
			index3 = L2[index2];
			L3.push_back(index3);
			index2++; //incrementing index1 will move to the next element
					  //in L1 that will be compared and sorted
		}
	}

	//if there are elements in L1, but not L2
	//just insert those elements to L3
	while(index1 != L1.size())
	{
		index3 = L1[index1];
		L3.push_back(index3);
		index1++;
	}
	//if there are elements in L2, but not L1
	//just insert those elements to L3
	while(index2 != L2.size())
	{
		index3 = L2[index2];
		L3.push_back(index3);
		index2++;
	}
}