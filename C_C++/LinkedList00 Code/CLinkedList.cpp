#include "stdafx.h"

const int & C_LINKEDLIST::getCount()
{
	return m_nCount;
}

void C_LINKEDLIST::increaseCount()
{
	m_nCount++;
}

void C_LINKEDLIST::decreaseCount()
{
	m_nCount--;
}

void C_LINKEDLIST::InitCount()
{
	m_nCount = 0;
}

S_NODE * C_LINKEDLIST::prevFind(S_NODE * const pNode)
{
	S_NODE * pPrevNode = nullptr;
	setIter(m_pBegin);

	while (getIter()->s_pNext != pNode)
	{
		setIter(getIter()->s_pNext);
	}
	pPrevNode = getIter();
	setIter(nullptr);

	return pPrevNode;
}

void C_LINKEDLIST::SortID(S_NODE * const pNode)
{
	setIter(pNode);


	while (getIter() != m_pEnd)
	{
		getIter()->s_nId--;
		setIter(getIter()->s_pNext);
	}

	setIter(nullptr);
}


C_LINKEDLIST::C_LINKEDLIST() :
	m_pBegin(nullptr),
	m_pEnd(nullptr),
	m_pIter(nullptr),
	m_pCurrent(nullptr),
	m_nCount(0)
{
}

void C_LINKEDLIST::Init(char * const strname)
{
	S_NODE * pNode = nullptr;

	InitCount();
	setIter(nullptr);

	pNode = new S_NODE{};
    
	pNode->s_nId = getCount();
	pNode->s_pName = strname;
	pNode->s_pNext = m_pEnd;
	
	increaseCount();

	m_pBegin = pNode;
	m_pCurrent = m_pBegin;

}

void C_LINKEDLIST::Add(char * const strname)
{
	S_NODE * pNode = nullptr;

	pNode = new S_NODE{};

	pNode->s_nId = getCount();
	pNode->s_pName = strname;
	pNode->s_pNext = m_pEnd;

	increaseCount();

	setIter(m_pCurrent);

	getIter()->s_pNext = pNode;
	m_pCurrent = pNode;
	setIter(nullptr);
}

void C_LINKEDLIST::Sub(char * const strname)
{
	S_NODE * pNode = Find(strname);
	S_NODE * pPrevNode = nullptr;

	if (pNode == m_pBegin)
	{
		SortID(m_pBegin->s_pNext);

		m_pBegin = pNode->s_pNext;

		delete pNode;
		pNode = nullptr;
	}
	else if (pNode->s_pNext == m_pEnd)
	{
		
		pPrevNode = nullptr;
		
		pPrevNode = prevFind(pNode);

		pPrevNode->s_pNext = m_pEnd;

		delete pNode;
		pNode = nullptr;
	}
	else
	{
		SortID(pNode->s_pNext);

		pPrevNode = nullptr;

		pPrevNode = prevFind(pNode);

		pPrevNode->s_pNext = pNode->s_pNext;

		delete pNode;
		pNode = nullptr;
	}
}

S_NODE * C_LINKEDLIST::Find(char * const strname) 
{
	std::string cstrwhat = std::string(strname);
	std::string cstrwhere = std::string();
	S_NODE * pNode = nullptr;

	setIter(m_pBegin);

	while (getIter() != m_pEnd)
	{
		cstrwhere = getIter()->s_pName;

		if (cstrwhat == cstrwhere)
		{
			pNode = getIter();
			break;
		}

		setIter(getIter()->s_pNext);
	}
	setIter(nullptr);

	return pNode;
}

void C_LINKEDLIST::Allshow()
{
	S_NODE * pPrint = nullptr;

	setIter(m_pBegin);

	std::cout << " < 보유목록 >" << std::endl << std::endl;

	while (getIter() != m_pEnd)
	{
		pPrint = getIter();

		
		std::cout << pPrint->s_nId + 1 << ". " << pPrint->s_pName << std::endl;

		setIter(getIter()->s_pNext);
	}
	std::cout << std::endl;

	setIter(nullptr);
}

void C_LINKEDLIST::Clear()
{
	S_NODE * pDelete = nullptr;

	setIter(m_pBegin);


	while (getIter() != m_pEnd)
	{
		pDelete = getIter();
		setIter(getIter()->s_pNext);

		delete pDelete;
		pDelete = nullptr;
	}
	setIter(nullptr);
}

S_NODE* const C_LINKEDLIST::getIter()
{
	return m_pIter;
}



void C_LINKEDLIST::setIter(S_NODE * const pNode)
{
	m_pIter = pNode;
}
