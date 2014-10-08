// =========================================================

//HW3P1 Singularly Linked List
//Your name: Kristen Osborne
//Complier:  gcc
//File type: implementation file .cpp

//==========================================================

#include <iostream>
using namespace std;

#include "llist.h"

llist::llist()
{
	front = NULL;
	count = 0;
}

llist::~llist()
{
	//nothing?
}

bool llist::isEmpty()
{
	if(front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void llist::displayEmpty()
{

	if(isEmpty())
		cout << "The list is empty." << endl;
	else
		cout << "The list is not empty." << endl;
}


void llist::displayAll()
{
	if(isEmpty())
	{
		cout << "The linked list is empty." << endl;
	}
	else
	{
		NodePtr current = front;
		while(current != NULL)
		{
			cout << current -> Elem << " ";
			current = current -> next;
		}
		cout << endl;
	}
}

void llist::addRear(el_t newNum)
{
	NodePtr current = front;
	NodePtr p = new Node(newNum);
	if(front == NULL)
		front = p;
	else
	{
		while(current -> next != NULL)
			current = current -> next;
		current -> next = p;
		p -> next = NULL;
	}
	count++;
}

void llist::deleteFront(el_t& oldNum)
{
	if(isEmpty())
		throw llist::Underflow();

	else
	{
		NodePtr p = front;
		front = front -> next; //this will also take care of the case if front -> next is NULL then front will then be null
		oldNum = p -> Elem;
		delete p;
		count--;
	}
}

void llist::addFront(el_t newNum)
{
	NodePtr p = new Node(newNum);

	if(front == NULL)
	{
		front = p;
	}
	else
	{
		p -> next = front;
		front = p;
	}
	count++;
}

void llist::deleteRear(el_t& oldNum)
{
	if(isEmpty())
		throw llist::Underflow();
	else if(count == 1)
	{
		oldNum = front -> Elem;
		front = NULL;
	}
	else
	{
		NodePtr current = front;
		NodePtr previous = front;
		while(current -> next != NULL)
		{
			previous = current;
			current = current -> next;
		}
		previous -> next = NULL;
		oldNum = current -> Elem;

		delete current;
		count--;
	}
}

void llist::deleteIth(int i, el_t& oldNum)
{

	if(isEmpty() || i < 1)
		throw llist::Underflow();
	else if(i > count)
		throw llist::Overflow();
	else
	{
		if(i == 1)
		{
			deleteFront(oldNum);
		}
		else if(i == count)
		{
			deleteRear(oldNum);
		}
		else
		{
			int j = 1;
			NodePtr current = front;
			NodePtr previous = front;
			while(j != i)
			{
				previous = current;
				current = current -> next;
				j++;
			}
			previous -> next = current -> next;
			oldNum = current -> Elem;
			delete current;
			count--;
		}
	}
}

void llist::addBeforeIth(int i, el_t newNum)
{
	if(isEmpty() || i < 1)
		throw llist::Underflow();
	else if(i > count+1)
		throw llist::Overflow();
	else
	{
		if(i == 1)
			addFront(newNum);
		else if(i == count + 1)
			addRear(newNum);
		else
		{
			int j = 0;
			NodePtr p = new Node(newNum);
			NodePtr previous = front;
			NodePtr current = front;
			while(j != i-1)
			{
				previous = current;
				current = current -> next;
				j++;
			}
			previous -> next = p;
			p -> next = current;
			count++;
		}
	}
}