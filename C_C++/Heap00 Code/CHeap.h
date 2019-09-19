#pragma once

#include "IArray.h"

class C_HEAP
{
public:
	enum E_ARRAY
	{
		E_NONE = 0,
		E_ROOT = 1,
	};
	enum E_LINE
	{
		E_LINEMAX = 10,
	};
	enum E_PRINTTYPE
	{
		E_MAX = 0,
		E_MIN
	};
private:
	I_ARRAY m_IArray;
	int * m_pArray;
	int m_nLast;

public:
	C_HEAP();

public:
	void C_CreateHeap(const int nSize);
	void C_ResizeHeap(const int nSize);
	void C_ReleaseHeap();

private:
	void F_Swap(int * pData1, int * pData2);
public:
	void C_Insert_Max(const int nData);
	void C_Insert_Min(const int nData);

public:
	void C_Remove_Max();
	void C_Remove_Min();
public:
	void C_PrintAll(C_HEAP::E_PRINTTYPE eType);
};