#pragma once

class C_NODE;

class C_TREE
{
public:
	enum E_PRINTTYPE
	{
		E_IN = 0,
		E_PRE,
		E_POST
	};
private:
	C_NODE * m_pRoot;
	C_NODE * m_pFinder;
	C_NODE ** m_ppNext;
	C_NODE * m_pNew;

private:
	C_NODE * F_InsertFind(C_NODE * pStart, const int nData);
	C_NODE * F_DeleteFind(C_NODE * pStart, const int nData);
	C_NODE * F_ParentFind(C_NODE * pChild, C_NODE * pStart, const int nData);
	C_NODE ** F_NullChildFind(C_NODE * pStart, const int nData);
	void	 F_Release(C_NODE * pNode);
	void     F_PrintNode(C_NODE * pNode, C_TREE::E_PRINTTYPE etype);
	void	 F_AllDelete(C_NODE * pNode);

private:
	void	 F_ShowInOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype);
	void	 F_ShowPreOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype);
	void	 F_ShowPostOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype);
public:
	C_TREE();	
	void C_Init(const int nData);
	void C_Insert(const int nData);
	void C_Delete(const int nData);

public:
	void C_SetRootNode(C_NODE * pNode);
    C_NODE * C_GetRootNode();
	C_NODE * C_CreateNode(const int nData);
	C_NODE * C_SearchNode(const int nData);
	void C_DeleteNode(C_NODE * pNode);

public:
	void C_PrintAll(C_TREE::E_PRINTTYPE etype);
	void C_Clear();
};