#pragma once

class C_STACK
{
private:
	int   m_nSize;
	int * m_pStack;
	int	  m_nStackPtr;
	int   m_nCount;
public:
	C_STACK();
	void  Init(const int nSize);
	const int getSize();
	const int getCount();
	void  Push(const int nData);
	const int Pop();
	void  Clear();
};