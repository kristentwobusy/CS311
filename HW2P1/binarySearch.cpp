// =========================================================

//HW2P2 binarySearch
//Your name: Kristen Osborne
//Complier:  gcc
//File type: .cpp

//==========================================================
#include <iostream>
using namespace std;

//prototype
int binarySearch(int array[], int find, int first, int last);


//the purpose of the program is to implement and test the binary search function.
//to compile, use g++ binarySearch.cpp
//it has an array with set elements. It will ask the user to enter a number
//it will call the binarySearch function. This function uses recursion until the
//if-else statements find the number or not.
int main()
{
	int array[] = {1,3,5,7,9,11,13,15,17,19}; //array that holds the required numbers
	int myFirst = 0; //index of first element
	int myLast = 9; //index of last element
	int resultLoc = 0; //result of where the found number is stored
	int find; //number entered by user that is to be found

	cout << "Please enter a number to search for: ";
	cin >> find;
	resultLoc = binarySearch(array, find, myFirst, myLast);
	
	if(resultLoc == -1) //-1 represents that the number entered was not found
		cout << "The number was not found." << endl;
	else //number was found
	{
		cout << find << " was found in position " << (resultLoc + 1) << "." << endl;
	}
	
} //end main

//the purpose of the function is to find a number in an array
//the purpose of the parameters: the array is what is being searched through,
//find is the number entered which is being searched for, first and last are indexes
//if-else statements are used to move indexes or return the number.
//Recursion is used until found or not
int binarySearch(int array[], int find, int first, int last)
{
	int middle = (first + last)/2; //finds the middle index
	if(find == array[middle]) //if the number was the middle number
		return middle;
	else if(find < array[middle]) //if the number is less than middle
		last = middle - 1;		  //then set last to middle-1
	else if(find > array[middle]) //if number is greater than middle
		first = middle + 1;		  //then set first to middle+1
	if(last < first) //if last < first then the number was not found
		return -1;
	return binarySearch(array, find, first, last); //use recursion until number is found or last<first
} //end function