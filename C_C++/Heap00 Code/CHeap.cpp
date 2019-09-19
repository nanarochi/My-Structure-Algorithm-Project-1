#include "stdafx.h"
#include "IArray.h"


C_HEAP::C_HEAP() :
	m_pArray(nullptr),
	m_nLast(0),
	m_IArray()
{
	
}

void C_HEAP::C_CreateHeap(const int nSize)
{
	
	m_pArray = m_IArray.I_Create1ArrayInt(nSize);

	if (nSize > 1)
	{
		m_nLast = 1;
	}

}

void C_HEAP::C_ResizeHeap(const int nSize)
{


	m_pArray = m_IArray.I_Resize1ArrayInt(m_pArray, nSize);

	
}

void C_HEAP::C_ReleaseHeap()
{
	m_IArray.I_Clear1ArrayInt(m_pArray);
	m_pArray = nullptr;
	m_nLast = 0;
}

void C_HEAP::F_Swap(int * pData1, int * pData2)
{
	int nData = 0;

	nData = (*pData1);

	(*pData1) = (*pData2);
	(*pData2) = nData;
}

void C_HEAP::C_Insert_Max(const int nData)
{
	int nPivot = 0;

	m_pArray[m_nLast] = nData;

	if (m_nLast < 2)
	{
		m_nLast++;
		return;
	}
	else if (m_nLast > m_IArray.I_GetLength() - 1)
	{
		m_nLast--;
		return;
	}

	nPivot = m_nLast;

	while (nPivot > (int)C_HEAP::E_ARRAY::E_ROOT)
	{

		if (m_pArray[nPivot] < m_pArray[(int)(nPivot >> 1)])
		{
			break;
		}
		
		F_Swap(&m_pArray[nPivot], &m_pArray[(int)(nPivot >> 1)]);

		nPivot = nPivot >> 1;
	}

	m_nLast++;
}

void C_HEAP::C_Insert_Min(const int nData)
{
	int nPivot = 0;

	m_pArray[m_nLast] = nData;

	if (m_nLast < 2)
	{
		m_nLast++;
		return;
	}
	else if (m_nLast > m_IArray.I_GetLength() - 1)
	{
		m_nLast--;
		return;
	}

	nPivot = m_nLast;

	while (nPivot >(int)C_HEAP::E_ARRAY::E_ROOT)
	{

		if (m_pArray[nPivot] > m_pArray[(int)(nPivot >> 1)])
		{
			break;
		}

		F_Swap(&m_pArray[nPivot], &m_pArray[(int)(nPivot >> 1)]);

		nPivot = nPivot >> 1;
	}
	m_nLast++;
}

void C_HEAP::C_Remove_Max()
{
	int nPivot = 0;
	int nRoot = 0;
	int nDir = 0;
	int nLimit = 0;

	nRoot = (int)C_HEAP::E_ARRAY::E_ROOT;
	nPivot = m_nLast - 1;

	if (!nPivot)
	{
		return;
	}

	m_pArray[nRoot] = m_pArray[nPivot];

	m_pArray[nPivot] = 0;

	m_nLast--;

	nLimit = m_nLast - 1;
	nDir = nRoot;

	while (nDir <= nLimit)
	{
		int nLeft = nDir << 1;
		int nRight = (nDir << 1) + 1;

		if (nLeft > nLimit)
		{
			break;
		}

		if (nRight > nLimit)
		{
			break;
		}

		if (m_pArray[nDir] > m_pArray[nLeft] && m_pArray[nDir] > m_pArray[nRight])
		{
			break;
		}
		else if (m_pArray[nDir] < m_pArray[nLeft])
		{
			F_Swap(&m_pArray[nDir], &m_pArray[nLeft]);

			nDir = nLeft;
		}
		else if (m_pArray[nDir] < m_pArray[nRight])
		{
			F_Swap(&m_pArray[nDir], &m_pArray[nRight]);

			nDir = nRight;
		}
		else if (m_pArray[nDir] < m_pArray[nLeft] && m_pArray[nDir] < m_pArray[nRight])
		{
			int nMax = nLeft;

			if (m_pArray[nMax] < m_pArray[nRight])
			{
				nMax = nRight;
			}

			F_Swap(&m_pArray[nDir], &m_pArray[nMax]);

			nDir = nMax;
		}
	}

}

void C_HEAP::C_Remove_Min()
{
	int nPivot = 0;
	int nRoot = 0;
	int nDir = 0;
	int nLimit = 0;

	nRoot = (int)C_HEAP::E_ARRAY::E_ROOT;
	nPivot = m_nLast - 1;

	if (!nPivot)
	{
		return;
	}

	m_pArray[nRoot] = m_pArray[nPivot];

	m_pArray[nPivot] = 0;

	m_nLast--;

	nLimit = m_nLast - 1;
	nDir = nRoot;

	while (nDir <= nLimit)
	{
		int nLeft = nDir << 1;
		int nRight = (nDir << 1) + 1;

		if (nLeft > nLimit)
		{
			break;
		}

		if( nRight > nLimit)
		{
			break;
		}

		if (m_pArray[nDir] < m_pArray[nLeft] && m_pArray[nDir] < m_pArray[nRight])
		{
			break;
		}
		else if (m_pArray[nDir] > m_pArray[nLeft])
		{
			F_Swap(&m_pArray[nDir], &m_pArray[nLeft]);

			nDir = nLeft;
		}
		else if (m_pArray[nDir] > m_pArray[nRight])
		{
			F_Swap(&m_pArray[nDir], &m_pArray[nRight]);

			nDir = nRight;
		}
		else if (m_pArray[nDir] > m_pArray[nLeft] && m_pArray[nDir] > m_pArray[nRight])
		{
			int nMin = nLeft;

			if (m_pArray[nMin] > m_pArray[nRight])
			{
				nMin = nRight;
			}

			F_Swap(&m_pArray[nDir], &m_pArray[nMin]);

			nDir = nMin;
		}
	}
}

void C_HEAP::C_PrintAll(C_HEAP::E_PRINTTYPE eType)
{
	int nData = 1;
	int nLevel = 1;


	if (eType == C_HEAP::E_PRINTTYPE::E_MAX)
	{
		std::cout << "< M A X  H E A P >" << std::endl;
	}
	else if (eType == C_HEAP::E_PRINTTYPE::E_MIN)
	{
		std::cout << "< M I N  H E A P >" << std::endl;
	}


	for (int i = 1; i < m_nLast; i++)
	{
		if (nData == 1)
		{
			std::cout << "Level " << nLevel << ":";
			nLevel++;
		}

		std::cout <<"  "<< m_pArray[i]<<"  ";

		if (i == nData)
		{
			nData = (nData << 1) + 1;
			std::cout << std::endl;
			std::cout << "Level " << nLevel << ":";
			nLevel++;
		}
		
	}
	std::cout << std::endl;
	std::cout << std::endl;
}
