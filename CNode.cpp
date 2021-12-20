// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: 
// --------------------------------------------------------------------------------
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#ifndef CNODE_CPP
#define CNODE_CPP
#include "CNode.h";
#define _CRT_SECURE_NO_WARNINGS

// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CNode<GenericDataType>::CNode()
{
	Initialize(0, 0);
}



// -------------------------------------------------------------------------------- //
// Name: Constructor
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CNode<GenericDataType>::CNode(GenericDataType gdtValue)
{
	Initialize(gdtValue, 0);
}



// -------------------------------------------------------------------------------- //
// Name: Constructor
// Abstract: paramaterized constructor - gdtValue & pclsNextNode
// -------------------------------------------------------------------------------- //
 template <typename GenericDataType>
CNode<GenericDataType>::CNode(GenericDataType gdtValue, CNode<GenericDataType>* pclsNextNode)
{
	Initialize(gdtValue, pclsNextNode);
}





// -------------------------------------------------------------------------------- //
// Name: Constructor
// Abstract: paramaterized constructor - clsOriginalToCopy
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CNode<GenericDataType>::CNode(const CNode<GenericDataType> &clsOriginalToCopy)

{
	Initialize(0,0);
	*this = clsOriginalToCopy;
}



	// -------------------------------------------------------------------------------- //
	// Name: Initialize
	// Abstract: set class properties to zero
	// -------------------------------------------------------------------------------- //
	// even though we have a pointer in the params there is no dynamic memory allocation
	// so no need to assign to zero before calling set next node
	template <typename GenericDataType>
	void CNode<GenericDataType>::Initialize(GenericDataType gdtValue, CNode<GenericDataType>* pclsNextNode)
	{
		SetValue(gdtValue);
		SetNextNode(pclsNextNode);
	}



// -------------------------------------------------------------------------------- //
// Name: Assignment operator
// Abstract:  perform an explicit shallow copy
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CNode<GenericDataType>::operator = (const CNode<GenericDataType> &clsOriginalToCopy)
{
	ShallowCopy(clsOriginalToCopy);
}



	// -------------------------------------------------------------------------------- //
	// Name: ShallowCopy
	// Abstract: property-wise copy of values. No mem allocation
	// -------------------------------------------------------------------------------- //
	// because it's a const you cannot call get value and next node cause those are not const
	template <typename GenericDataType>
	void CNode<GenericDataType>::ShallowCopy (const CNode<GenericDataType> &clsOriginalToCopy)
	{
		// can either access properties directly or make the gets const
		// value
		m_gdtValue = clsOriginalToCopy.m_gdtValue;

		// next node
		m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
	}



// -------------------------------------------------------------------------------- //
// Name: Destructor
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CNode<GenericDataType>::~CNode()
{
	CleanUp();
}



	// -------------------------------------------------------------------------------- //
	// Name: CleanUp
	// Abstract: 
	// -------------------------------------------------------------------------------- //
	template <typename GenericDataType>
	void CNode<GenericDataType>::CleanUp()
	{
		// nothing to do
	}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CNode<GenericDataType>::SetValue(GenericDataType gdtValue)
{
	m_gdtValue = gdtValue;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
GenericDataType CNode<GenericDataType>::GetValue()
{
	return m_gdtValue;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CNode<GenericDataType>::SetNextNode(CNode<GenericDataType>* pclsNextNode)
{
	m_pclsNextNode = pclsNextNode;
}



// -------------------------------------------------------------------------------- //
// Name: 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CNode<GenericDataType>* CNode<GenericDataType>::GetNextNode()
{
	return m_pclsNextNode;
}
#endif