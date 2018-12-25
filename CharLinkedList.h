
/* Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Header and Declaration
 *  Modified By (UTLN):odayo01
 *           On       :02/07/2017
 *
 */
#ifndef CHARSEQUENCE_H
#define CHARSEQUENCE_H
#include <iostream>
using namespace std;
class CharLinkedList
{
//public declarations of functions and variables used by the program
public:
	//constructor that declares and initializes an empty linked list
	CharLinkedList();
	
	//constructor that declares and initializes an single node linked list
	CharLinkedList(char x);

	//constructor that declares and initializes a 
	//linked list with a given set of characters
	CharLinkedList(char array[], int length);

	//constructor to delete allocated memory on the heap used by the program
	~CharLinkedList(); 

	//function to check if the linked list is empty
	bool isEmpty();

	//function to clear out a linked list
	void clear();

	//function to check how many nodes a linked list has
	int size();

	//function to get the element of the first node in the linked list
	char first();

	//function to get the element of the last node in the linked list
	char last();

	//function to get the element of the node at a given index
	char elementAt(int x);

	//function to print out a linked list
	void print();

	//function to add a xter to the back of a linked list
	void pushAtBack(char x);

	//function to add a xter to the back of a linked list
	void pushAtFront(char x);

	//function to add a xter to a linked list at a given index
	void insertAt(char x, int y);

	//function to add a xter to a linked list in alphabetical order
	void insertInOrder(char x);

	//function to remove the first xter in a linked list
	void popFromFront();

	//function to remove the first xter in a linked list
	void popFromBack();

	//function to remove a xter at a given index in a linked list
	void removeAt(int x);

	//function to replace a xter at a given index in a linked list with another one
	void replaceAt(char x, int y);

	//function to add a linked list to the back of another
	void concatenate(CharLinkedList* ptr);

	//function to remove any unused nodes in a linked list
	void shrink();

	//function to find a xter in a given linked list
	bool find(char x);

	

//private member functions and variables of the program
private:
	//struct object that defines a node in the linked list
	struct CharNode {
               char item;
               CharNode *next;
			CharNode *previous;
	};

	//pointer to the first node of a linked list
	CharNode *head;

	//pointer to the last node of a linked list
	CharNode *tail;

	//pointer to a new node to take the position of the last node
	CharNode *newTail;

	//pointer that travels across the linked list to find necessary xters
	CharNode *traverse;

	//an integer to track the size of the linked list
	int index;

	//function to create the initial node in a linked list
	void firstNode(char x);

	//function to throw exceptions as needed
	void throwexception(string exceptiontype);

	//function to locate the xters at a given index
	void locate(int x);

	//function to search for a xter in a given linked
	bool searchEngine(CharNode* curr, char x);

};

#endif

