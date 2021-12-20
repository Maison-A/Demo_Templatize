// --------------------------------------------------------------------------------
//								COMPILER DIRECTIVES
// --------------------------------------------------------------------------------
#ifndef CRESIZABLE_ARRAY_CPP
#define CRESIZABLE_ARRAY_CPP

// --------------------------------------------------------------------------------
//								COMPILER DIRECTIVES
// --------------------------------------------------------------------------------
#include "CResizableArray.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
using namespace std;

#pragma region "Initialize"
// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Set array size and array pointer to 0
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray()
{

	Initialize(0, 0);

}



// --------------------------------------------------------------------------------
// Name: 
// Abstract: Set array size and array pointer to 0
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray(long lngInitialSize)
{
	Initialize(lngInitialSize, 0);
}



// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Set array size and array pointer to 0
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType> ::CResizableArray(long lngInitialSize, GenericDataType gdtDefaultValue)
{
	Initialize(lngInitialSize, gdtDefaultValue);
}



// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: the Copy constructor to handle pass by val
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray(const CResizableArray<GenericDataType> &clsOriginalToCopy)
{
	Initialize(0, 0);
	*this = clsOriginalToCopy;
	
}



	// --------------------------------------------------------------------------------
	// Name: Initialize
	// Abstract: Set array size and array pointer to 0
	// --------------------------------------------------------------------------------
	template <typename GenericDataType>
	void CResizableArray<GenericDataType>::Initialize(long lngInitialSize, GenericDataType gdtDefaultValue)
	{

		m_lngArraySize = 0;
		m_pagdtValues = 0;

		SetSize(lngInitialSize, gdtDefaultValue);

	}


// --------------------------------------------------------------------------------
// Name: ~CResizableArray
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::~CResizableArray()
{
	CleanUp();
}


#pragma endregion

#pragma region "Size"
// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Zero value are allowed but not negative values.
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize)
{
	SetSize(lngNewSize, 0);

}



// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Zero value are allowed but not negative values.
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize, GenericDataType gdtDefaultValue)
{
	GenericDataType* pagdtNewValues = 0;
	long lngIndex = 0;
	long lngStop = 0;


	// bound check
	if (lngNewSize < 0) lngNewSize = 0;
	if (lngNewSize > 10000) lngNewSize = 10000;

	// check if size changed
	if (lngNewSize != m_lngArraySize)
	{
		//is new size larger than zero?
		if (lngNewSize > 0)
		{
			pagdtNewValues = new GenericDataType[lngNewSize];
		}
		// initiallize new memory
		for (lngIndex = 0; lngIndex < lngNewSize; lngIndex += 1)
		{
			// base pointer + offset <--don't forget it. we MUST use pointer arithmatic in this class
			*(pagdtNewValues + lngIndex) = gdtDefaultValue;
		}

		//how many values can we preserve?
		if (lngNewSize < m_lngArraySize) lngStop = lngNewSize;
		else lngStop = m_lngArraySize;

		// copy values from old array to new array, again, using pointer arithmatic
		for (lngIndex = 0; lngIndex < lngStop; lngIndex += 1)
		{
			*(pagdtNewValues + lngIndex) = *(m_pagdtValues + lngIndex);
		}

		// delete old array
		if (m_pagdtValues != 0)
		{
			delete[] m_pagdtValues;
			m_pagdtValues = 0;
		}

		// assign new array
		m_pagdtValues = pagdtNewValues;

		// assign new size
		m_lngArraySize = lngNewSize;

	}
}




// --------------------------------------------------------------------------------
// Name: GetSize
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
long CResizableArray<GenericDataType>::GetSize() const
{

	return m_lngArraySize;

}

#pragma endregion

#pragma region "Value Manipulation"
// 
// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetValueAt(GenericDataType gdtValueToAdd, long lngIndex)
{

	if (m_lngArraySize > 0)
	{
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;
		*(m_pagdtValues + lngIndex) = gdtValueToAdd;
	}
}



// --------------------------------------------------------------------------------
// Name: GetValueAt
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
GenericDataType CResizableArray<GenericDataType>::GetValueAt(long lngIndex) const
{

	GenericDataType gdtValue = 0;

	if (m_lngArraySize > 0)
	{
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		gdtValue = *(m_pagdtValues + lngIndex);
	}

	return gdtValue;
}



// --------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToFront(GenericDataType gdtValueToAdd)
{

	InsertValueAt(gdtValueToAdd, 0);

}



// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToEnd(GenericDataType gdtValueToAdd)
{

	InsertValueAt(gdtValueToAdd, GetSize());

}



// --------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::InsertValueAt(GenericDataType gdtValueToInsert, long lngInsertAtIndex)
{


	GenericDataType* pagdtNewValues = 0;
	long lngIndex = 0;
	
	// bound check
	if (lngInsertAtIndex < 0) lngIndex = 0;
	if (lngInsertAtIndex > m_lngArraySize) lngInsertAtIndex = m_lngArraySize;

	// make a new array of size one larger
	pagdtNewValues = new GenericDataType[GetSize() + 1];

	// copy first half from old to new
	for (lngIndex = 0; lngIndex < lngInsertAtIndex; lngIndex += 1)
	{
		*(pagdtNewValues + lngIndex) = *(m_pagdtValues + lngIndex);

	}

	// Insert
	*(pagdtNewValues + lngInsertAtIndex) = gdtValueToInsert;

	// copy second half
	for (lngIndex = lngInsertAtIndex; lngIndex < GetSize(); lngIndex += 1)
	{
		*(pagdtNewValues + lngIndex + 1) = *(m_pagdtValues + lngIndex);
	}

	// delete old array
	delete[]m_pagdtValues;
	m_pagdtValues = 0;

	// Assign new array
	m_pagdtValues = pagdtNewValues;

	// Assign size
	m_lngArraySize += 1;
}



// --------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::RemoveAt(long lngRemoveIndex)
{
	int intCurrentIndex = 0;
	long lngIndex = 0;
	GenericDataType* pagdtNewValues = 0;
	
	// allocate new block of mem size + 1
	long* palngNewValues = 0;
	long lngNewSize = 0;

	// check if there is anything to remove
	if (GetSize() > 0)
	{
		// bound check
		if (lngRemoveIndex < 0) lngRemoveIndex = 0;
		if (lngRemoveIndex > m_lngArraySize - 1) lngRemoveIndex = m_lngArraySize - 1;

		pagdtNewValues = new GenericDataType[GetSize() - 1];

		// copy old array up to index to remove
		for (lngIndex = 0; lngIndex < lngRemoveIndex; lngIndex += 1)
		{

			*(pagdtNewValues + lngIndex) = *(m_pagdtValues + lngIndex);
		}

		// continue to insert values after index
		for (lngIndex = lngRemoveIndex + 1; lngIndex < GetSize(); lngIndex += 1)
		{
			// itereate source array by one ahead to input proper value
			*(pagdtNewValues + lngIndex - 1) = *(m_pagdtValues + lngIndex);
		}

		// delete old array - dereference once to get to the bloc of mem
		delete[] m_pagdtValues;
		m_pagdtValues = 0;

		// assign new array
		m_pagdtValues = pagdtNewValues;

		// make array smaller since, well, it's smaller
		m_lngArraySize -= 1;
	}
}

#pragma endregion

#pragma region "Operators"
// --------------------------------------------------------------------------------
// Name: operator =
// Abstract: assignment opporator 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::operator = (const CResizableArray<GenericDataType> &clsOriginalToCopy)
{
	// take the current instance "this" and compare against address of original
	if (this != &clsOriginalToCopy)
	{
		// if not the same/share mem then clean up to avoid mem leaks
		CleanUp();
		DeepCopy(clsOriginalToCopy);
	}
}




// --------------------------------------------------------------------------------
// Name: subscript operator [] - set
// Abstract: subscript operator  - return pointer to long
// --------------------------------------------------------------------------------
template <typename GenericDataType>
GenericDataType &CResizableArray<GenericDataType>::operator [] (long lngIndex)
{

	GenericDataType* pgdtValue = 0;

	if (m_lngArraySize > 0)
	{
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		pgdtValue = m_pagdtValues + lngIndex;
	}

	return *pgdtValue;
	
}



// --------------------------------------------------------------------------------
// Name: operator []
// Abstract: subscript operator overloaded to be const
// --------------------------------------------------------------------------------
template <typename GenericDataType>
const GenericDataType &CResizableArray<GenericDataType>::operator [] (long lngIndex) const
{
	// still can't figure it out
	GenericDataType* pgdtValue = 0;

	if (m_lngArraySize > 0)
	{
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		pgdtValue = m_pagdtValues + lngIndex;
	}

	return *pgdtValue;
}




// --------------------------------------------------------------------------------
// Name: Plus Equal
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::operator += (const CResizableArray<GenericDataType> &clsOriginalToAppend)
{
	
	long lngNewSize = 0;
	GenericDataType* pagdtNewValues = 0;
	long lngSourceIndex = 0;
	long lngDestinationIndex = 0;

	//new size?
	lngNewSize = GetSize() + clsOriginalToAppend.GetSize();

	// do not call set size because could be appending self

	//allocate space
	pagdtNewValues = new GenericDataType[lngNewSize];//not a string so no +1 for terminator

	// copy 1st half
	for (lngSourceIndex = 0; lngSourceIndex < GetSize(); lngSourceIndex += 1)
	{
		pagdtNewValues[lngDestinationIndex] = (*this)[lngSourceIndex];
		lngDestinationIndex += 1;
	}
	//copy 2nd half
	for (lngSourceIndex = 0; lngSourceIndex < clsOriginalToAppend.GetSize(); lngSourceIndex += 1)
	{
		pagdtNewValues[lngDestinationIndex] = clsOriginalToAppend[lngSourceIndex];
		lngDestinationIndex += 1;
	}

	//delete old mem
	CleanUp();

	//assign new array
	m_pagdtValues = pagdtNewValues;
	m_lngArraySize = lngNewSize;
}



// --------------------------------------------------------------------------------
// Name: plus
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType> CResizableArray<GenericDataType>::operator + (const CResizableArray<GenericDataType> &clsRight) const
{
	CResizableArray clsLeftAndRight;
	clsLeftAndRight = *this;//left
	clsLeftAndRight += clsRight;

	return clsLeftAndRight;
}

#pragma endregion

#pragma region "Tools"
// --------------------------------------------------------------------------------
// Name: DeepCopy
// Abstract: subroutine to execute a deep copy of array 
// Manually allocate duplicate bloacks and copyuu all the values in the original
// blacks of mem to the copy instance. aka deep copy
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::DeepCopy(const CResizableArray<GenericDataType> &clsOriginalToCopy)
{
	int intIndex = 0;
	long lngSize = 0;
	long lngIndex = 0;

	// determine size
	lngSize = clsOriginalToCopy.GetSize();
	SetSize(lngSize);
	// palngValues = new long[lngArraySize + 1];

	// copy the values
	for (intIndex = 0; intIndex < lngSize; intIndex += 1)
	{
		//deref to get instance
		(*this)[intIndex] = clsOriginalToCopy[intIndex];
	}

}



// --------------------------------------------------------------------------------
// Name: PrintArray
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
const void CResizableArray<GenericDataType>::PrintArray()
{
	int intIndex = 0;

	for (intIndex = 0; intIndex < m_lngArraySize; intIndex += 1)
	{
		cout << *(m_pagdtValues + intIndex);
		cout << endl;
	}
}


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::Print() const
{
	Print("Print Array");

}
//pagdtValues


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::Print(const char* strParam) const
{
	int intIndex = 0;

	for (intIndex = 0; intIndex < m_lngArraySize; intIndex += 1)
	{
		cout << *(m_pagdtValues + intIndex);
		cout << endl;
	}
}



// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: 
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::CleanUp()
{
	SetSize(0, 0);

}
#pragma endregion

#endif