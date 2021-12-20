// --------------------------------------------------------------------------------
// Name: CQueue
// Abstract: 
// --------------------------------------------------------------------------------
// -------------------------------------------------------------------------------- //
//										Includes
// -------------------------------------------------------------------------------- //
#ifndef CQUEUE_CPP
#define CQUEUE_CPP
#include "CQueue.h";
#define _CRT_SECURE_NO_WARNINGS

// -------------------------------------------------------------------------------- //
// Name: CQueue
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CQueue<GenericDataType>::CQueue()
{
	Initialize();
}



// -------------------------------------------------------------------------------- //
// Name: CQueue
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CQueue<GenericDataType>::CQueue(const CQueue<GenericDataType>&clsOriginalToCopy)
{
	Initialize();
	*this = clsOriginalToCopy;
}



	// -------------------------------------------------------------------------------- //
	// Name: Initialize
	// Abstract: 
	// -------------------------------------------------------------------------------- //
	template <typename GenericDataType>
	void CQueue<GenericDataType>::Initialize()
	{
		m_pclsHeadNode = 0;
		m_pclsTailNode = 0;
	}



// -------------------------------------------------------------------------------- //
// Name: operator = 
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CQueue<GenericDataType>::operator = (const CQueue<GenericDataType> &clsOriginalToCopy)
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
			void CQueue<GenericDataType>::DeepCopy(const CQueue<GenericDataType>&clsOriginalToCopy)
			{
				CNode* pclsCurrentOriginal = 0;
				CNode* pclsNextNode = 0;
				CNode* pclsNewNode = 0;
				CNode* pclsTailNodeOfCopy = 0;
				CNode* pclsTailNode = 0;
				int intValue = 0;

				// get top of the original to copy - because the original is an instance of a node we can 
				// access the value within tocopy
				pclsCurrentOriginal = clsOriginalToCopy.m_pclsHeadNode;

				while (pclsCurrentOriginal != 0)
				{
					// get the value
					intValue = pclsCurrentOriginal->GetValue();

					// push
					Push(intValue);
		
					// empty list?
					if (m_pclsTailNode == 0)
					{
						m_pclsTailNode = new CNode(intValue, 0);
					}
					else
					{
						pclsNewNode = new CNode(intValue, 0);

						// linkg tail to new node
						pclsTailNode->SetNextNode(pclsNewNode);

						// move to tail
						pclsTailNode = pclsNewNode;
					}

					// get next
					pclsNextNode = pclsCurrentOriginal->GetNextNode();

					// move to next
					pclsCurrentOriginal = pclsCurrentOriginal->GetNextNode(); // <-- this all makes a copy in reverse order
				}


			}



// -------------------------------------------------------------------------------- //
// Name: ~CQueue
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
CQueue<GenericDataType>::~CQueue()
{
	CleanUp();
}



// -------------------------------------------------------------------------------- //
// Name: CleanUp
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
void CQueue<GenericDataType>::CleanUp()
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
void CQueue<GenericDataType>::Push(GenericDataType gdtValue)
{
	CNode<GenericDataType>* pclsNewNode = new CNode <GenericDataType>(gdtValue);

	// empty list?
	if (IsEmpty() == true)
	{
		m_pclsHeadNode = pclsNewNode;
		m_pclsTailNode = pclsNewNode;
	}
	else
	{
		m_pclsTailNode->SetNextNode(pclsNewNode);
		m_pclsTailNode = pclsNewNode;
	}
	
}



// -------------------------------------------------------------------------------- //
// Name: Pop
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
GenericDataType CQueue<GenericDataType>::Pop()
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
		
		// was that the last node in the list
		if (IsEmpty() == true)
		{
			m_pclsTailNode = 0;
		}	
	}

	return gdtValue;
}



// -------------------------------------------------------------------------------- //
// Name: IsEmpty
// Abstract: 
// -------------------------------------------------------------------------------- //
template <typename GenericDataType>
bool CQueue<GenericDataType>::IsEmpty() const
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
void CQueue<GenericDataType>::Print(const char* pstrCaption) const
{
	int intIndex = 0;
	CNode* pclsCurrentNode = 0;

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
			pclsCurrentNode = pclsCurrentNode->GetNextNode();
		}
	}

	else
	{
		cout << "Empty Stack" << endl;
	}

}
#endif