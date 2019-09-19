#pragma once

class C_POINT;
class C_QUEUE;

class C_GRAPH
{
private:
	int m_nSize;
	int m_nCount;
	int m_nIter;
	C_POINT * m_pV;
	bool ** m_ppI;
	C_QUEUE * m_pQueue;
	bool * m_pVisit;
	int m_nDoneCount;
	int m_nNumber;
	const char * m_strClassName;

public:
	C_GRAPH();

private:
	int F_Find(const char * strName);
	void F_Print(int nId);
	void F_RecursionDFS(const char *strNode);
	void F_ClearVisit();
public:
	void C_Init(const int nSize, const char * clsName);
	void C_InsertVertex(char * strName);
	void C_Connecting(char * strName, char * strTarget);
	void C_Release();
public:
	void C_ShowBFS(char * strStart);
	void C_ShowDFS(const char * strStart);

};