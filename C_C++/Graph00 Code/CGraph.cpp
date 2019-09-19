#include "stdafx.h"
#include "CPoint.h"
#include "CQueue.h"

C_GRAPH::C_GRAPH() :
	m_nSize(0),
	m_pV(nullptr),
	m_ppI(nullptr),
	m_nIter(0),
	m_pQueue(nullptr),
	m_pVisit(nullptr),
	m_nCount(0),
	m_nDoneCount(0),
	m_nNumber(0),
	m_strClassName(nullptr)

{
	
}

int C_GRAPH::F_Find(const char * strName)
{
	int nTarget = 0;
	std::string str1 = std::string();
	std::string str2 = std::string();

	str2 = strName;

	for (int i = 1; i <= m_nCount; i++)
	{
		str1 = m_pV[i].GetName();

		if (str1.compare(str2) == 0 )
		{
			nTarget = m_pV[i].GetId();
			break;
		}
	}

	return nTarget;
}

void C_GRAPH::F_Print(int nId)
{
	std::cout << m_nNumber + 1 << " 번째 "<< m_pV[nId].GetName()<< " 에 방문함." << std::endl << std::endl;
	m_nNumber++;
}

void C_GRAPH::F_RecursionDFS(const char * strNode)
{
	int nTarget = F_Find(strNode);
	
	if (m_pVisit[nTarget] == true)
	{
		return;
	}
	else
	{
		F_Print(nTarget);
		m_pVisit[nTarget] = true;
		m_nDoneCount++;
	}

	if (m_nDoneCount >= m_nCount)
	{
		return;
	}

	for (int i = 1; i <= m_nCount; i++)
	{
		if (m_ppI[nTarget][i] == true && m_pVisit[i] == false)
		{
			F_RecursionDFS(m_pV[i].GetName());
		}
	}
}

void C_GRAPH::F_ClearVisit()
{
	m_pVisit[0] = true;

	for (int i = 1; i < m_nSize; i++)
	{
		m_pVisit[i] = false;
	}

}

void C_GRAPH::C_Init(const int nSize, const char * clsName)
{
	m_nSize = nSize - 1;
	m_nIter = 1;
	m_nCount = 0;
	m_nDoneCount = 0;
	m_nNumber = 0;
	m_strClassName = clsName;

	if (!m_pV)
	{
		m_pV = new C_POINT[nSize]{};
	}
	
	if (!m_ppI)
	{
		m_ppI = new bool*[nSize]{};

		for (int i = 0; i < nSize; i++)
		{
			m_ppI[i] = new bool[nSize]{};

			m_ppI[0][i] = false;
			m_ppI[i][0] = false;
		}

	}

	if (!m_pQueue)
	{
		m_pQueue = new C_QUEUE();
		m_pQueue->Init(nSize);
	}

	if (!m_pVisit)
	{
		m_pVisit = new bool[nSize] {};

		m_pVisit[0] = true;

		for (int i = 1; i < nSize; i++)
		{
			m_pVisit[i] = false;
		}
	}
}

void C_GRAPH::C_InsertVertex(char * strName)
{
	if (m_nIter > m_nSize)
	{
		return;
	}

	m_pV[m_nIter].SetName(strName);
	m_pV[m_nIter].SetId(m_nIter);
	m_nIter++;
	m_nCount++;

}

void C_GRAPH::C_Connecting(char * strName, char * strTarget)
{
	int nUser = 0;
	int nTarget = 0;

	nUser = F_Find(strName);
	nTarget = F_Find(strTarget);

	m_ppI[nUser][nTarget] = true;
	m_ppI[nTarget][nUser] = true;
}

void C_GRAPH::C_Release()
{
	if (m_pV)
	{
		delete[] m_pV;
		m_pV = nullptr;
	}

	if (m_ppI)
	{
		for (int i = 0; i <= m_nSize; i++)
		{
			delete[] m_ppI[i];
			m_ppI[i] = nullptr;
		}

		delete[] m_ppI;
		m_ppI = nullptr;
	}

	if (m_pQueue)
	{
		m_pQueue->Clear();
	}

	if (m_pVisit)
	{
		delete[] m_pVisit;
		m_pVisit = nullptr;
	}
}

void C_GRAPH::C_ShowBFS(char * strStart = nullptr)
{
	int nStart = 0;
	int nTarget = 0;
	bool bLoop = true;

	if (strStart == nullptr || strStart == " " || strStart == "")
	{
		std::cout << "시작점을 설정해주세요!" << std::endl << std::endl;
		return;
	}
	
	nStart = F_Find(strStart);
	

	std::cout << "== " << m_strClassName << " BFS 탐색 ==" << std::endl << std::endl;

	m_pQueue->Enqueue(nStart);
	
	nTarget = m_pQueue->Dequeue();

	F_Print(nTarget);
	m_pVisit[nTarget] = true;

	while (bLoop)
	{
		int nDoneCount = 0;

		for (int i = 1; i <= m_nCount; i++)
		{
			if (m_ppI[nTarget][i] == true && m_pVisit[i] == false)
			{
				m_pQueue->Enqueue(m_pV[i].GetId());				
			}		
		
		}
		
		nTarget = m_pQueue->Dequeue();

		if (m_pVisit[nTarget] == false)
		{
			F_Print(nTarget);
			m_pVisit[nTarget] = true;
		}

		for (int j = 1; j <= m_nCount; j++)
		{
			if (m_pVisit[j] == true)
			{
				nDoneCount++;
			}
		}
		
		if (nDoneCount >= m_nCount)
		{
			bLoop = false;
		}
	}


	std::cout << std::endl;
	
	F_ClearVisit();
	m_nNumber = 0;
}

void C_GRAPH::C_ShowDFS(const char * strStart)
{
	if (strStart == nullptr || strStart == " " || strStart == "")
	{
		std::cout << "시작점을 설정해주세요!" << std::endl << std::endl;
		return;
	}

	std::cout << "== " << m_strClassName << " DFS 탐색 ==" << std::endl << std::endl;

	F_RecursionDFS(strStart);

	std::cout << std::endl;

	F_ClearVisit();
	m_nNumber = 0;
}







