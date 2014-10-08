// =========================================================

//HW3P1 Singularly Linked List
//Your name: Kristen Osborne
//Complier:  gcc
//File type: .cpp

//==========================================================
#ifndef llist_h
#define llist_h

class Node;
typedef int el_t;
typedef Node* NodePtr;
class llist;

class Node
{
public:
	el_t Elem;
	NodePtr next;
	Node(){Elem = 0; next = NULL;};
	Node(el_t num){Elem = num; next = NULL;};
};

class llist
{
protected:
	NodePtr front;
	int count;

public:
	class Underflow{};
	class Overflow{};

	llist();
	~llist();

	bool isEmpty();
	void displayEmpty();
	void displayAll();
	void addRear(el_t newNum);
	void deleteFront(el_t& oldNum);
	void addFront(el_t newNum);
	void deleteRear(el_t& oldNum);
	void deleteIth(int i, el_t& oldNum);
	void addBeforeIth(int i, el_t newNum);

};

#endif