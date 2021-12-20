// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: 
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
//								Pre-compiler Directives
// --------------------------------------------------------------------------------
#ifndef CNODE_H
#define CNODE_H

#pragma once		
#define _CRT_SECURE_NO_WARNINGS
// --------------------------------------------------------------------------------
//										Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename GenericDataType>
class CNode
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

		GenericDataType m_gdtValue;
		CNode* m_pclsNextNode;

	private:


		// --------------------------------------------------------------------------------
		// Methods
		// --------------------------------------------------------------------------------
	public:

		// Constructors
		CNode();
		CNode(GenericDataType gdtValue);
		CNode(GenericDataType gdtValue, CNode* pclsNextNode);
		CNode(const CNode &clsOriginalToCopy);//copy constructor with shallow copy

		//destructor
		~CNode();

		// assignment operator
		void operator = (const CNode &clsOriginalToCopy);

		// set and get value
		void SetValue(GenericDataType gdtNewValue);
		GenericDataType GetValue();

		// set and get node
		void SetNextNode(CNode* pclsNextNode);
		CNode* GetNextNode();

	protected:

		void Initialize(GenericDataType gdtValue, CNode* pclsNextNode);
		void ShallowCopy(const CNode &clsOriginalToCopy);
		void CleanUp();

	private:

};
// must include source file in header file or define all methods in header
// after class declaration
#include "CNode.cpp"
#endif