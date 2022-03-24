// -------------------------------------------------------------------------------- //
// Name: CStack
// Abstract: Stack class
// -------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------- //
//								Pre-compiler Directives
// -------------------------------------------------------------------------------- //
#ifndef CSTACK_H
#define CSTACK_H
#pragma once		
#define _CRT_SECURE_NO_WARNINGS
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#include <stdlib.h>
#include <iostream>
#include "CNode.h"
using namespace std;

template <typename GenericDataType>
class CStack
{
	// -------------------------------------------------------------------------------- //
	//									CONSTANTS
	// -------------------------------------------------------------------------------- //



	// -------------------------------------------------------------------------------- //
	//									Properties
	// -------------------------------------------------------------------------------- //

public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:

	
private:

	CNode<GenericDataType>* m_pclsHeadNode;
	// -------------------------------------------------------------------------------- //
	// Methods
	// -------------------------------------------------------------------------------- //
public:

	// Constructors
	CStack();
	CStack(const CStack &clsOriginalToCopy);


	//destructor
	~CStack();

	// assignment operator
	void operator = (const CStack &clsOriginalToCopy);

	// set and get value
	void Push(GenericDataType gdtValue);
	GenericDataType Pop();

	// is empty
	bool IsEmpty() const;

	// print
	void Print() const;
	void Print(const char* strHeading) const;

protected:


private:
	void Initialize();
	void DeepCopy(const CStack& clsOriginalToCopy);
	void CleanUp();


};
// must include source file in header file or define all methods in header file after 
// class declaration.
#include "CStack.cpp"
#endif

