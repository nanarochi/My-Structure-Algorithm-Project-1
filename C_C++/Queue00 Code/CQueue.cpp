#include "stdafx.h"

void C_QUEUE::OverflowMessage(const int nData)
{
	std::cout << "!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "  오버플로우 발생!" << std::endl;
	std::cout << "  손실된 데이터 : " << nData << std::endl;
	std::cout << "!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

void C_QUEUE::UnderflowMessage()
{
	std::cout << "!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "  언더플로우 발생!" << std::endl;
	std::cout << "!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

C_QUEUE::C_QUEUE() :
	m_nSize(0),
	m_pQueue(nullptr),
	m_nCount(0),
	m_nBack(0),
	m_nFront(0)
{
}

void C_QUEUE::Init(int nSize)
{
	m_nCount = 0;
	m_nSize = nSize;

	if (!m_pQueue)
	{
		m_pQueue = new int[m_nSize] {};
	}
	m_nBack = 0;
	m_nFront = -1;
}

void C_QUEUE::Clear()
{
	if (m_pQueue)
	{
		delete[] m_pQueue;
		m_pQueue = nullptr;
	}
}

void C_QUEUE::Enqueue(int nData)
{
	if (getCount() == getSize())
	{
		int num = 0;
		num = Dequeue();
		OverflowMessage(num);
		
	}

	for(int i = getCount() - 1; i >= 0; i--)
	{
		m_pQueue[i + 1] = m_pQueue[i];
	}

	m_pQueue[m_nBack] = nData;
	m_nFront++;
	m_nCount++;
}

const int C_QUEUE::Dequeue()
{
	int num = 0;

	if (m_nCount < 1)
	{
		m_nFront++;
		UnderflowMessage();
		return -1;
	}
	else
	{
		num = m_pQueue[m_nFront];
		m_nFront--;
		m_nCount--;
		return num;
	}
}

const int C_QUEUE::getSize()
{
	return m_nSize;
}

const int C_QUEUE::getCount()
{
	return m_nCount;
}
