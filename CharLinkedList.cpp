/*  Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  CharLinkedList.cpp
 *  Complete CharLinkedList Class Implementation
 *  Modified By (UTLN):odayok01
 *           On       :02/07/2017
 *
 */

#include <iostream>
#include "CharLinkedList.h"
#include <stdexcept>

using namespace std;
/*CharLinkedList()
 *purpose:declares and initializes an empty linked list
 *with an initial capacity of zero.
 *parameters: none
 *return: nothing
 */ 
CharLinkedList::CharLinkedList(){
	index = 0;
	head = NULL;
	tail = head;
}

/*CharLinkedList(char element)
 *purpose:declares and initializes a one element
 *linked list with an initial capacity of 1
 *parameters: a character variable
 *return: nothing
 */
CharLinkedList::CharLinkedList(char element){
	index = 0;
	firstNode(element);
}

/*CharSequence(char array[], int y)
 *purpose: declares and initializes a linked list with a given set of characters
 *and capacity that is the length of the array
 *parameters: a character array and an integer length of the array
 *return: nothing
 */
CharLinkedList::CharLinkedList(char x[], int y){
	head = new CharNode;
	if (y > 1){
		tail = new CharNode;
		head -> item = x[0];
		head -> previous = NULL;
		head -> next = tail;
		tail -> item = x[1];
		tail -> previous = head;
		index = 2;
		for (int i = 2; i < y; i++){
			char curr = x[i];
			pushAtBack(curr);
			}
	}
	else {
		//tail = head;
		//head -> next = head -> previous = NULL;
		//index = 1;
		firstNode(x[0]);
	}
}

/*`CharLinkedList
 *purpose: deletes allocated memory on the heap used by the program
 *parameters: nothing
 *returns: nothing
 */
CharLinkedList::~CharLinkedList(){
	clear();
}


/*isEmpty()
 *purpose: checks whether a linked list is empty or not
 *parameters: none
 *return: a boolean value
 */
bool CharLinkedList::isEmpty(){
	if (head == NULL){
		return true;
	}
	else
		return false;
}

/*firstNode()
 *purpose: initializes the first node of a linked list
 *parameters: a character element
 *return: none
 */
void CharLinkedList::firstNode(char element){
	head = new CharNode;
	head -> item = element;
	head -> next = NULL;
	head -> previous = NULL;
	tail = head;
	index += 1;
}

/*removeAt(int x)
 *purpose: removes the character at a given index
 *parameters: an integer value of the index
 *return: none
 */
void CharLinkedList::removeAt(int x){
	if (x > index || x < 0){
		throwexception("range");
	}
	if (isEmpty() == true){
		throwexception("empty");
	}
	traverse = head;

	if (x == 0 && index == 1){
		delete head;
		head = NULL;
		tail = NULL;
		index -= 1;
		return;
	}
	else if (x == (index)){
		traverse = tail;
		tail = traverse -> previous;	
		index -= 1;
		delete tail;
	}
	else if(x == 0){
		traverse = head;
		(head -> next) -> previous = NULL;
		head = traverse -> next;
		index -= 1;
		delete traverse;
		return;
	}
	else{
		locate(x);
		(traverse -> previous) -> next = (traverse -> next);
		delete traverse;
		index -= 1;
	}
}

/*throwexception(string exceptiontype)
 *purpose: throws exceptions for given errors
 *parameters: a string that lets it know what exception to throw
 *return: nothing
 */
void CharLinkedList::throwexception(string exceptiontype){
	if (exceptiontype == "range"){
		throw range_error("index_out_of_range");
		return;
	}
	if (exceptiontype == "empty"){
		throw runtime_error("sequence_is_empty");
		return;
	}
}

/*popFromBack()
 *purpose:removes the last character in a linked list
 *parameters: none
 *return: none
 */
void CharLinkedList::popFromBack(){
	removeAt(index - 1);
}


/*locate()
 *purpose:finds a node at a given index
 *parameters: an integer that is the index wanted
 *return: none
 */
void CharLinkedList::locate(int x){
	if (x > index || x < 0){
		throwexception("range");
	}
	if (isEmpty() == true){
		throwexception("empty");
	}
	int find = 0;
	traverse = head;
	while(find != x){
		traverse = (traverse -> next);
		find += 1;
	}	
}

/*popFromFront()
 *purpose: removes the first character in a linked list
 *parameters: none
 *return: none
 */
void CharLinkedList::popFromFront(){
	removeAt(0);
}



/*insertAt(char x, int y)
 *purpose: inserts a given character at a given index
 *parameters: a character and an integer
 *return: none
 */
void CharLinkedList::insertAt(char x, int y){
	locate(y);
	if( y == 0)
	{
		traverse = new CharNode;
		traverse -> item = x;
		traverse -> next = head;
		head -> previous = traverse;
		traverse -> previous = NULL;
		head = traverse;
		index += 1;
	}
	else if(y == index){
		newTail = new CharNode;
		newTail -> item = x;
		tail -> next = newTail;
		newTail -> previous = tail;
		tail = newTail;
		index += 1;
	}

	else{
		CharNode *newNode;
		newNode = new CharNode;
		newNode -> item = x;
		newNode -> next = traverse;
		newNode -> previous = traverse -> previous;
		(traverse -> previous) -> next = newNode;
		traverse -> previous = newNode;
		index += 1;
	}
}

/*pushAtFront(char x)
 *purpose: insert a character before the head in a linked list
 *parameters: a character
 *return: none
 */
void CharLinkedList::pushAtFront(char x){
	if (isEmpty() == true){
		firstNode(x);
	}
	else
		insertAt(x, 0);
}

/*size()
 *purpose: returns an integer value that is the 
 *number of characters in a linked list
 *in a given sequence
 *parameters: none
 *return: nothing
 */
int CharLinkedList::size(){
	return index;
}

/*clear()
 *purpose: converts a given linked list into an empty one
 *parameters: nothing
 */
void CharLinkedList::clear(){
	traverse = head;
	while(head != NULL){
		popFromFront();
	}	
}

/*first()
 *purpose: To return the first element in a given linked list
 *parameters: none
 *return: character that is the first in the given linked list
 */
char CharLinkedList::first(){
	if (head == NULL){
		throwexception("empty");
	}
	return head -> item;
}


/*last()
 *purpose: To return the last linked list in a sequence
 *parameters: none
 *return: character that is at the last position in the linked list
 */
char CharLinkedList::last(){
	if (head == NULL){
		throwexception("empty");
	}
	return tail -> item;
}

/*print()
 *purpose: to print out the characters in a given linked list
 *parameters: none
 *return: none
 */
void CharLinkedList::print(){
	traverse = head;
	
	cout << "[CharLinkedList of size " << index <<" <<";
	if(isEmpty() == true){
		cout << ">>]" << endl;
	}
	else {
		for(int i = 0; i < index; i++){
			cout << (traverse -> item);
			traverse = traverse -> next;
		}
		cout << ">>]" << endl;
	}

}


/*elementAt()
 *purpose: to return the character at a given index
 *parameters: an integer that is the index of the desired character
 *return: the character at the given index
 */
char CharLinkedList::elementAt(int x){
	if (x > index || x < 0){
		throwexception("range");
	}
	locate(x);
	return traverse -> item;
}


/*insertInOrder(char x)
 *purpose: inserts a given character in the linked lsit in alphabetical order
 *parameters: a character
 *return: none
 */
void CharLinkedList::insertInOrder(char x){
	traverse = tail;
	int count = index;

	if(traverse -> next == NULL){
		pushAtFront(x);
	}

	else if((traverse -> item) < x ){
		pushAtBack(x);
	}

	else if(traverse != head){
		for(int i = index; i > 0; i--){
			traverse = traverse -> previous;
			count -= 1;
			if((traverse -> item) > x){
				insertAt(x, count-1);
			} 
		}
	}
}

/*replaceAt()
 *purpose: replaces the character at a given index with a given character
 *parameters: an integer value of an index and a character
 *return: none
 */
void CharLinkedList::replaceAt(char x, int y){
	if (y > index){
		throwexception("range");
	}
	locate(y);
	traverse -> item = x;
}


/*pushAtBack(char x)
 *purpose: insert a character after the last character in a linked list
 *parameters: a character
 *return: none
 */
void CharLinkedList::pushAtBack(char x){
	if (isEmpty() == true){
		firstNode(x);
	}
	else{
		insertAt(x, index);
	}
} 

/*concatenate(CharSequence* ptr)
 *purpose: concatenate a given linked list to another one
 *parameters: a pointer to a linked list
 *return: none
 */
void CharLinkedList::concatenate(CharLinkedList *ptr){
	int concatSize = ptr -> size();
		for(int i = 0; i < concatSize; i++){
			pushAtBack(ptr -> elementAt(i));
		}	
}

/*shrink()
 *purpose: remove all unused nodes
 *parameters: none
 *return: none
 */
void CharLinkedList::shrink(){
	//linked list only use the minimum amount of nodes required
	return;
}

/*searchEngine(CharNode *curr, char x)
 *purpose: base case to find an item in a node
 *parameters: a pointer to a linked list and a xter to search for
 *return: none
 */
bool CharLinkedList::searchEngine(CharNode *curr, char x){
	if ( curr == NULL){
		return false;
	}
	else if( curr -> item == x){
		return true;
	}
	else {
		return searchEngine(curr -> next, x);
	}
}

/*find(char x)
 *purpose: find a xter in a linked list
 *parameters: a xter to search for
 *return: none
 */
bool CharLinkedList::find(char x){
	return searchEngine(head, x);
}

