// =========================================================

//HW3P1 Singularly Linked List
//Your name: Kristen Osborne
//Complier:  gcc
//File type: client .cpp

//==========================================================

#include <iostream>
using namespace std;
#include "llist.h"

int main()
{
	llist list1;
	el_t num = 0;
	cout << "\n==========\nCase 1:\n==========\n" << endl;
	list1.displayEmpty();
	list1.displayAll();
	list1.addRear(1);
	list1.addRear(2);
	list1.addRear(3);
	list1.displayAll();
	list1.deleteFront(num);
	cout << "Element removed: " << num << endl;
	list1.deleteFront(num);
	cout << "Element removed: " << num << endl;
	list1.displayAll();
	list1.displayEmpty();
	list1.deleteFront(num);
	cout << "Element removed: " << num << endl;
	list1.displayEmpty();


	llist list2;
	cout << "\n==========\nCase 2:\n==========\n" << endl;
	list2.addFront(5);
	list2.addFront(4);
	list2.deleteFront(num);
	list2.addRear(6);
	list2.addRear(8);
	list2.addRear(9);
	list2.displayAll();
	list2.addBeforeIth(1,4);
	list2.addBeforeIth(4,7);
	list2.addBeforeIth(7,10);

	try
	{
		list2.addBeforeIth(9,12);

	}
	catch(llist::Overflow){
		cout << "Out of Range." << endl;
	}

	try
	{
		list2.addBeforeIth(0,0);
	}
	catch(llist::Underflow){
		cout << "Out of Range." << endl;
	}

	list2.displayAll();
	list2.deleteIth(1,num);
	list2.deleteIth(6,num);
	list2.deleteIth(3,num);
	try{
		list2.deleteIth(5,num);
	}
	catch(llist::Overflow){
		cout << "Out of Range." << endl;
	}
	try
	{
		list2.deleteIth(0,num);
	}
	catch(llist::Underflow){
		cout << "Out of Range." << endl;
	}

	list2.displayAll();
	while(!list2.isEmpty())
	{
		list2.deleteRear(num);
		cout << "Element removed: " << num << endl;
	}
	list2.displayAll();



	llist list3;
	cout << "\n==========\nCase 3:\n==========\n" << endl;
	try
	{
		list3.addBeforeIth(0,0);
	}
	catch(llist::Underflow){
		cout << "Out of Range." << endl;
	}
	try
	{
		list3.deleteFront(num);
	}
	catch(llist::Underflow){
		cout << "Underflow." << endl;
	}


	llist list4;
	cout << "\n==========\nCase 4:\n==========\n" << endl;
	try
	{
		list4.deleteIth(2,num);
	}
	catch(llist::Underflow){
		cout << "Out of Range." << endl;
	}
	try
	{
		list4.deleteRear(num);
	}
	catch(llist::Underflow){
		cout << "Underflow." << endl;
	}

	return 0;
}