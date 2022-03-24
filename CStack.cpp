// --------------------------------------------------------------------------------
// Name: CStack
// Abstract: 
// --------------------------------------------------------------------------------
#ifndef CSTACK_CPP
#define CSTACK_CPP

// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //

#include "CStack.h";
#define _CRT_SECURE_NO_WARNINGS

// -------------------------------------------------------------------------------- //
// Name: CStack
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CStack<GenericDataType>::CStack()
{
	Initialize();
}



// -------------------------------------------------------------------------------- //
// Name: CQueue
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CStack<GenericDataType>::CStack(const CStack<GenericDataType>& clsOriginalToCopy)
{
	Initialize();
	*this = clsOriginalToCopy;
}



// -------------------------------------------------------------------------------- //
// Name: Initialize
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CStack<GenericDataType>::Initialize()
{
	m_pclsHeadNode = 0;
}



// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CStack<GenericDataType>::operator = (const CStack<GenericDataType>& clsOriginalToCopy)
{
	// need self assignment check
	if (this != &clsOriginalToCopy)
	{
		CleanUp();
		DeepCopy(clsOriginalToCopy);
	}

}



// -------------------------------------------------------------------------------- //
// Name: DeepCopy
// Abstract: 
// -------------------------------------------------------------------------------- //
// because it's a const you cannot call get value and next node cause those are not const
template <typename GenericDataType>
void CStack<GenericDataType>::DeepCopy(const CStack<GenericDataType>& clsOriginalToCopy)
{
	GenericDataType gdtValue;
	CNode<GenericDataType>* pclsNodeToCopy = 0;
	CNode<GenericDataType>* pclsTailNode = 0;
	CNode<GenericDataType>* pclsCurrentNode = 0;
	
	int intValue = 0;

	pclsNodeToCopy = clsOriginalToCopy.m_pclsHeadNode;

	// check if anything to copy
	
	if (pclsNodeToCopy != 0)
	{
		gdtValue = pclsNodeToCopy->GetValue();
		m_pclsHeadNode = new CNode<GenericDataType>(gdtValue);
		pclsTailNode = m_pclsHeadNode;

		// get next
		pclsNodeToCopy = pclsNodeToCopy->GetNextNode();
		
		// loop til end
		while (pclsNodeToCopy != 0)
		{
			// copy node
			gdtValue = pclsNodeToCopy->GetValue();
			pclsCurrentNode = new CNode<GenericDataType>(gdtValue);

			// add to end
			pclsTailNode->SetNextNode(pclsCurrentNode);
			pclsTailNode = pclsCurrentNode;

			// get next
			pclsNodeToCopy = pclsNodeToCopy->GetNextNode();
		}

	}

}



// -------------------------------------------------------------------------------- //
// Name: ~CQueue
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CStack<GenericDataType>::~CStack()
{
	CleanUp();
}



// -------------------------------------------------------------------------------- //
// Name: CleanUp
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CStack<GenericDataType>::CleanUp()
{
	// while not empty pop the values and chuck them
	while (IsEmpty() == false)
	{
		Pop();
	}

}



// -------------------------------------------------------------------------------- //
// Name: Push
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CStack<GenericDataType>::Push(GenericDataType gdtValue)
{
	CNode<GenericDataType>* pclsNewNode = 0;

	// make instance
	pclsNewNode = new CNode<GenericDataType>(gdtValue);

	// add to top 
	pclsNewNode->SetNextNode(m_pclsHeadNode);

	// move to top
	m_pclsHeadNode = pclsNewNode;
}



// -------------------------------------------------------------------------------- //
// Name: Pop
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
GenericDataType CStack<GenericDataType>::Pop()
{
	GenericDataType gdtValue = 0;
	CNode<GenericDataType>* pclsNextNode = 0;

	// empty list?
	if (IsEmpty() == false)
	{
		// no, get value
		gdtValue = m_pclsHeadNode->GetValue();

		// get next value in stack
		pclsNextNode = m_pclsHeadNode->GetNextNode();

		// delete
		delete m_pclsHeadNode;
		m_pclsHeadNode = 0;

		m_pclsHeadNode = pclsNextNode;
	}

	return gdtValue;
}



// -------------------------------------------------------------------------------- //
// Name: IsEmpty
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
bool CStack<GenericDataType>::IsEmpty() const
{
	bool blnIsEmpty = false;

	// check if head node is empty and if so then return true
	if (m_pclsHeadNode == 0)
	{
		blnIsEmpty = true;
	}

	return blnIsEmpty;
}



// -------------------------------------------------------------------------------- //
// Name: Print
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CStack<GenericDataType>::Print(const char* pstrCaption) const
{
	int intIndex = 0;
	CNode<GenericDataType>* pclsCurrentNode = 0;
	CNode<GenericDataType>* pclsNextNode = 0;

	cout << endl;
	cout << pstrCaption << "------------" << endl;

	if (IsEmpty() == false)
	{
		pclsCurrentNode = m_pclsHeadNode;

		//count and print each node
		while (pclsCurrentNode != 0)
		{
			intIndex += 1;
			cout << "Location [" << (intIndex + 1) << "] = "
				<< pclsCurrentNode->GetValue() << endl;

			// next node
			pclsCurrentNode = pclsNextNode;
		}
	}

	else
	{
		cout << "Empty Stack" << endl;
	}

}
#endif