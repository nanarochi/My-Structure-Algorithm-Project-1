#include "stdafx.h"


C_STACK::C_STACK() :
	m_nSize(0),
	m_pStack(nullptr),
	m_nStackPtr(0),
	m_nCount(0)
{
}

void C_STACK::Init(const int nSize)
{
	m_nSize = nSize;

	if (!m_pStack)
	{
		m_pStack = new int[m_nSize] {};
	}

	m_nStackPtr = m_nSize - 1;
}

const int C_STACK::getSize()
{
	return m_nSize;
}

const int C_STACK::getCount()
{
	return m_nCount;
}

void C_STACK::Push(const int nData)
{
	m_pStack[m_nStackPtr] = nData;
	m_nStackPtr--;
	m_nCount++;

}

const int C_STACK::Pop()
{
	int nData = 0;

	nData = m_pStack[m_nStackPtr + 1];
	m_nStackPtr++;
	m_nCount--;

	return nData;
}

void C_STACK::Clear()
{
	if (m_pStack)
	{
		delete[] m_pStack;
		m_pStack = nullptr;
	}
}
