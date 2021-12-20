// -------------------------------------------------------------------------------- //
// Name: CQueue
// Abstract: First in first out
// -------------------------------------------------------------------------------- //

// -------------------------------------------------------------------------------- //
//								Pre-compiler Directives
// -------------------------------------------------------------------------------- //
#ifndef CQUEUE_H
#define CQUEUE_H
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
class CQueue
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

	CNode<GenericDataType>* m_pclsHeadNode;
	CNode<GenericDataType>* m_pclsTailNode;

private:


	// -------------------------------------------------------------------------------- //
	// Methods
	// -------------------------------------------------------------------------------- //
public:

	// Constructors
	CQueue();
	CQueue(const CQueue& clsOriginalToCopy);


	//destructor
	~CQueue();

	// assignment operator
	void operator = (const CQueue &clsOriginalToCopy);

	// set and get value
	void Push(GenericDataType gdtValue);
	GenericDataType Pop();

	// is empty
	bool IsEmpty() const;

	// print
	void Print(const char* pstrCaption) const;

protected:

	void Initialize();
	void DeepCopy(const CQueue &clsOriginalToCopy);
	void CleanUp();

private:

};
// must include source file in header file or define all methods in header file after 
// class declaration.
#include "CQueue.cpp"
#endif