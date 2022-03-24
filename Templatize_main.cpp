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
#include "CStack.h"
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
	void ResizableArrayPassByReferenceChar(CResizableArray<char> &clsValues);
	void ResizableArrayPassByValueChar(CResizableArray<char> clsCopyOfOriginal);

// long
void ResizableArrayTestsLong();
	void ResizableArrayPassByReferenceLong(CResizableArray<long> &clsValues);
	void ResizableArrayPassByValueLong(CResizableArray<long> clsCopyOfOriginal);

// double
void ResizableArrayTestsDouble();
	void ResizableArrayPassByReferenceDouble(CResizableArray<double> &clsValues);
	void ResizableArrayPassByValueDouble(CResizableArray<double> clsCopyOfOriginal);

// CStack
void StackTests();
	void StackTestsChar();
		void StackPassByReferenceChar(CStack<char> &clsValues);
		void StackPassByValueChar(CStack<char> clsCopyOfOriginal);
	
	void StackTestsLong();
		void StackPassByReferenceLong(CStack<long> &clsValues);
		void StackPassByValueLong(CStack<long> clsCopyOfOriginal);
	
	void StackTestsDouble();
		void StackPassByReferenceDouble(CStack<double>& clsValues);
		void StackPassByValueDouble(CStack<double> clsCopyOfOriginal);

// CQueue
void QueueTests();
	void QueueTestsChar();
		void QueuePassByReferenceChar(CQueue<char> &clsValues);
		void QueuePassByValueChar(CQueue<char> clsCopyOfOriginal);
	
	void QueueTestsLong();
		void QueuePassByReferenceLong(CQueue<long> &clsValues);
		void QueuePassByValueLong(CQueue<long> clsCopyOfOriginal);
	
	void QueueTestsDouble();
		void QueuePassByReferenceDouble(CQueue<double>& clsValues);
		void QueuePassByValueDouble(CQueue<double> clsCopyOfOriginal);

// --------------------------------------------------------------------------------
//										MAIN
// --------------------------------------------------------------------------------
void main()
{
	// cout << "I made it this far" << endl;
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
//	Name: StackTests
//  Abstract: run tests of the stack
// --------------------------------------------------------------------------- //
void StackTests()
{
	StackTestsChar();
	StackTestsLong();
	StackTestsDouble();

}

	// --------------------------------------------------------------------------- //
	//	Name: StackTestsChar
	//  Abstract: test char stack
	// --------------------------------------------------------------------------- //
	void StackTestsChar()
	{
		cout << "----------------------------" << endl;
		cout << "Stack tests: Char" << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		CStack<char> clsValues1;
		clsValues1.Print("Default constructor");

		clsValues1.Push('a');
		clsValues1.Push('b');
		clsValues1.Push('c');
		clsValues1.Print("Push a, b, and c");

	}


// --------------------------------------------------------------------------- //
//	Name:
//  Abstract:
// --------------------------------------------------------------------------- //
void QueueTests()
{



}