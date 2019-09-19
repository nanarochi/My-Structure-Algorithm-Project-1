#include "stdafx.h"
#include "IArray.h"

I_ARRAY::I_ARRAY() :
	m_nSize(0)
{
}

int * I_ARRAY::I_Create1ArrayInt(const int nsize)
{
	int * pArray = nullptr;

	pArray = new int[nsize] {};
	m_nSize = nsize;
	return pArray;
}

int * I_ARRAY::I_Resize1ArrayInt(int * pInt, const int nsize)
{
	int * pNewArray = nullptr;
	int nLength = 0;
	int nTmpSize = 0;

	nTmpSize = m_nSize;

	pNewArray = I_Create1ArrayInt(nsize);

	if (nsize < nTmpSize)
	{
		nLength = nsize;
	}
	else if (nsize >= nTmpSize)
	{
		nLength = nTmpSize;
	}

	for (int i = 0; i < nLength; i++)
	{
		pNewArray[i] = pInt[i];
	}

	

	I_Clear1ArrayInt(pInt);

	return pNewArray;
}

void I_ARRAY::I_Clear1ArrayInt(int * pInt)
{
	if (!pInt)
	{
		return;
	}

	delete[] pInt;
	pInt = nullptr;
}

int I_ARRAY::I_GetLength()
{
	return m_nSize;
}




