// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Header file for CResizableArray
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
//								Compiler Directives
// --------------------------------------------------------------------------------
#ifndef CRESIZABLE_ARRAY_H
#define CRESIZABLE_ARRAY_H

// --------------------------------------------------------------------------------
//										Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>

using namespace std;


template <typename GenericDataType>
class CResizableArray
{

	// --------------------------------------------------------------------------------
	//									Constants
	// --------------------------------------------------------------------------------

	// --------------------------------------------------------------------------------
	//									Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:
	
		long m_lngArraySize;
		GenericDataType* m_pagdtValues;
private:
	


	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:
	// constructor
	CResizableArray();

	// constructor paramatised
	CResizableArray(long lngInitialSize);
	CResizableArray(long lngInitialSize, GenericDataType gdtDefaultValue);

	// copy constructor to handle pass by ref
	CResizableArray(const CResizableArray &clsOriginalToCopy);

	// destructor
	~CResizableArray();

	// assignment operator
	void operator = (const CResizableArray &clsOriginalToCopy);

	// subscript operator
	GenericDataType  &operator [] (long lngIndex);// set
	const GenericDataType &operator[] (long lngIndex) const;//get - read only

	//overload +=
	void operator += (const CResizableArray &clsOriginalToAppend);

	// overload add operator
	CResizableArray operator + (const CResizableArray &clsRight) const;

	// Zero value are allowed but not negative values.
	// Two Set size that takes different levels of parameters
	void SetSize(long lngNewSize);
	void SetSize(long lngNewSize, GenericDataType gdtDefaultValue);
	long GetSize() const;

	// set and get value at
	void SetValueAt(GenericDataType gdtValueToAdd, long lngIndex);
	GenericDataType GetValueAt(long lngIndex) const;

	// add values
	void AddValueToFront(GenericDataType gdtValueToAdd);
	void AddValueToEnd(GenericDataType gdtValueToAdd);
	void InsertValueAt(GenericDataType gdtValueToInsert, long lngInsertAtIndex);

	// remove
	void RemoveAt(long lngRemoveIndex);

	void Print() const;
	void Print(const char* strParam) const;
	const void PrintArray();

protected:
	// deep copy to avoid pointer deletion
	void DeepCopy(const CResizableArray &clsOriginalToCopy);
	void Initialize(long lngInitialSize, GenericDataType gdtDefaultValue);
	void CleanUp();

private:



};
// include method definitions so we can have seperate files
// for class declaration and method definitions
#include "CResizableArray.cpp"

#endif 




