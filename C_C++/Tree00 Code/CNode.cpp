#include "stdafx.h"

C_NODE::C_NODE() :
	m_nData(0),
	m_pLeft(nullptr),
	m_pRight(nullptr)
{

}

int C_NODE::I_getData()
{
	return m_nData;
}

void C_NODE::I_setData(const int nData)
{
	m_nData = nData;
}

C_NODE * C_NODE::I_getLeftChild()
{
	return m_pLeft;
}

void C_NODE::I_setLeftChild(C_NODE * pNode)
{
	m_pLeft = pNode;
}

C_NODE * C_NODE::I_getRightChild()
{
	return m_pRight;
}

void C_NODE::I_setRightChild(C_NODE * pNode)
{
	m_pRight = pNode;
}

C_NODE ** C_NODE::I_getpLeft()
{
	return &m_pLeft;
}

C_NODE ** C_NODE::I_getpRight()
{
	return &m_pRight;
}

