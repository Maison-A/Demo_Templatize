/*
*	Name: Maison C Arroyo
	Abstract: A demonstration of my capacity to implement stacks, queues, and dynamic memory. 
	Initially completed as homework assignment
*/

// --------------------------------------------------------------------------------
//								Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		
#define _CRT_SECURE_NO_WARNINGS
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#include <stdlib.h>
#include <iostream>
#include "CResizableArray.h"
#include "CQueue.h"
using namespace std;


// --------------------------------------------------------------------------- //
//									CONSTANTS
// --------------------------------------------------------------------------- //



// --------------------------------------------------------------------------- //
//								USER DEFINED TYPES
// --------------------------------------------------------------------------- //



// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void ArrayTests();
// char
void ResizableArrayTestsChar();
	void ResizableArrayPassByReferenceChar(CResizableArray<char>& clsValues);
	void ResizableArrayPassByValueChar(CResizableArray<char> clsCopyOfOriginal);

// long
void ResizableArrayTestsLong();
void ResizableArrayPassByReferenceLong(CResizableArray<long>& clsValues);

void StackTests();

void QueueTests();

// --------------------------------------------------------------------------------
//										MAIN
// --------------------------------------------------------------------------------
void main()
{
	cout << "I made it this far" << endl;
	ArrayTests();
	StackTests();
	QueueTests();

	system("pause");
}

// --------------------------------------------------------------------------- //
//	Name:
//  Abstract:
// --------------------------------------------------------------------------- //
void ArrayTests()
{
	ResizableArrayTestsChar();


}



// --------------------------------------------------------------------------- //
//	Name: ResizableArrayTestsChar
//  Abstract:
// --------------------------------------------------------------------------- //
void ResizableArrayTestsChar()
{
	cout << "---------------------------------------------------------" << endl;
	cout << " RESIZABLE ARRAY TEST: LONGS " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << endl;

	// #1 constructor
	CResizableArray<char> clsValues1;
	clsValues1.Print("#1 - DEFAULT CONSTRUCTOR");

	// #2 set size
	clsValues1.SetSize(4);
	clsValues1.Print("#2A - SET SIZE SetSize(4)");
	clsValues1.SetSize(0);
	clsValues1.SetSize(4, 'A');
	clsValues1.Print("#2B - SetSize(4, 'A')");

	// #3 Get size
	cout << "#3 - GetSize: 4? " << clsValues1.GetSize() << endl;

	// #4 populate with subscript operator
	clsValues1[-1] = 'A';
	clsValues1[0] = 'a';
	clsValues1[1] = 'c';
	clsValues1[2] = 'e';
	clsValues1[3] = 'f';
	clsValues1[4] = 'h';

	// place brackets
	{
		// #5 copy constructor
		// the brackets mean copy will go out of scope and call destructor for copy
		// original should be unaffected
		CResizableArray<char> clsValues2(clsValues1);
		clsValues2.Print("#5a - copy constructor, assignment operator, deep copy and const"
			" subscript");
	}
	clsValues1.Print("Original unaffected");
}



// --------------------------------------------------------------------------- //
//	Name:
//  Abstract:
// --------------------------------------------------------------------------- //
void StackTests()
{
	


}



// --------------------------------------------------------------------------- //
//	Name:
//  Abstract:
// --------------------------------------------------------------------------- //
void QueueTests()
{



}