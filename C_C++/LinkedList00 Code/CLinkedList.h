#pragma once

#include "CNode.h"

class C_LINKEDLIST
{
	
	
private:
	S_NODE * m_pBegin;
	S_NODE * m_pEnd;
	S_NODE * m_pCurrent;
	S_NODE * m_pIter;
	int		 m_nCount;

private:
	const int& getCount();
	void increaseCount();
	void decreaseCount();
	void InitCount();
	S_NODE *  prevFind(S_NODE * const pNode);
	void SortID(S_NODE * const pNode);

public:
	S_NODE * const getIter();
	void setIter( S_NODE* const pNode);
	

public:
	C_LINKEDLIST();
	void Init(char * const strname);
	void Add(char * const strname);
	void Sub(char * const strname);
	S_NODE *  Find(char * const strname);
	void Allshow();
	void Clear();
	
};