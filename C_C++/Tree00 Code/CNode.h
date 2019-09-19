#pragma once

class C_NODE
{
private:
	int m_nData;
	C_NODE * m_pLeft;
	C_NODE * m_pRight;

public:
	C_NODE();
	int I_getData();
	void I_setData(const int nData);
	C_NODE * I_getLeftChild();
	void I_setLeftChild(C_NODE * pNode);
	C_NODE * I_getRightChild();
	void I_setRightChild(C_NODE * pNode);

public:
	C_NODE** I_getpLeft();
	C_NODE** I_getpRight();
};




