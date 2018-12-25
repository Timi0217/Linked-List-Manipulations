/*  Oluwatimilehin Dayo-Kayode
 *
 *  COMP 15 HW 2 Cheshire ConCATenation - Time to linked up in hur
 *
 *  testCharLinkedList.cpp
 *  Testing File for your sequence CharLinkedList class
 *
 *  Written by:
 *        UTLN:odayok01
 *          on:02/09/2017
 */

#include <iostream>

#include <CharLinkedList.h>

using namespace std;
int main()
{
    /*std::cout << "Hey Congrats on finishing HW1, \n"
              << "but now its time to move on to HW2!\n\n"
              << "Are you loving COMP15 yet?  Well if not you will!\n\n"
              << "Hello World.\n\n";
	*/


	//tests all the functions with the third constructor
	char test[] = "fifteen";

	CharLinkedList linkedlist(test, 7);
	
	//tests all functions with 2nd constructor
	//CharLinkedList linkedlist("p");
	linkedlist.print();
	
	//tests the clear function
	//works and the print after this throws exception
	linkedlist.clear();

	//works too. prints out 'fiftee'
	linkedlist.popFromBack();

	//this works...finally!
	linkedlist.popFromFront();

	//linkedlist.print();

	//fosho works cause print is dependent on it, but doesn't hurt to check
	int x = linkedlist.size();
	cout << x << endl;

	//works 
	char firsttest = linkedlist.first();
	cout << firsttest <<"first"<< endl;
	
	//works...thanks to tail
	char y = linkedlist.last();
	cout << y <<"last" << endl;

	//works exceedingly well too(v.happy rn)
	char elementAtTest = linkedlist.elementAt(1);
	cout << elementAtTest <<"element at"<< endl;

	//works :)
	linkedlist.pushAtBack('x');


	//just had to get insertAt to work to get this. This works
	linkedlist.pushAtFront('x');

	linkedlist.print();

	//this was a tough nut to crack, but it works :)
	linkedlist.insertAt('x', 3);	

	//linkedlist.print();
		
	//this works too...great!
	linkedlist.popFromFront();

	//this works...after so many bugs!!!
	linkedlist.insertInOrder('u');
	
	//works..had a bug. 'Twas an easy fix. Wish every other bug was this nice.
	linkedlist.popFromBack();

	//works too. also tried removing the head and tail, and they worked too
	linkedlist.removeAt(2);
	

	linkedlist.replaceAt('b', 1);

	
	/*char* two = new char[3];
	two[0] = 'c';
	two[1] = 'a';
	two[2] = 't';

	CharLinkedList concat(two, 3);

	linkedlist.concatenate(&concat);


	
	linkedlist.print();

	delete [] two;
	*/
	
	


	
return 0;
}
