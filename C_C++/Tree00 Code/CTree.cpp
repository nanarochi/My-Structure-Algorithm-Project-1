#include "stdafx.h"

C_NODE * C_TREE::F_InsertFind(C_NODE * pStart, const int nData)
{
	C_NODE * pFinder = nullptr;

	if (nData == pStart->I_getData())
	{
		return nullptr;
	}

	if (nData > pStart->I_getData())
	{
		if (!(pStart->I_getRightChild()))
		{
			pFinder = pStart;
		}
		else if ((pStart->I_getRightChild()))
		{
			pFinder = F_InsertFind(pStart->I_getRightChild(), nData);
		}
	}
	else if (nData < pStart->I_getData())
	{
		if (!(pStart->I_getLeftChild()))
		{
			pFinder = pStart;
		}
		else if ((pStart->I_getLeftChild()))
		{
			pFinder = F_InsertFind(pStart->I_getLeftChild(), nData);
		}
	}

	return pFinder;
}

C_NODE * C_TREE::F_DeleteFind(C_NODE * pStart, const int nData)
{
	C_NODE * pFinder = nullptr;

	if (!pStart)
	{
		return nullptr;
	}

	if (nData == pStart->I_getData())
	{
		pFinder = pStart;
	}
	else if (nData > pStart->I_getData())
	{
		 if ((pStart->I_getRightChild()))
		{
			pFinder = F_DeleteFind(pStart->I_getRightChild(), nData);
		}
	}
	else if (nData < pStart->I_getData())
	{
		if ((pStart->I_getLeftChild()))
		{
			pFinder = F_DeleteFind(pStart->I_getLeftChild(), nData);
		}
	}

	return pFinder;
}

C_NODE * C_TREE::F_ParentFind(C_NODE * pChild, C_NODE * pStart, const int nData)
{
	C_NODE * pParent = nullptr;

	if (nData > pStart->I_getData())
	{
		if (pChild == pStart->I_getRightChild())
		{
			pParent = pStart;
		}
		else if (pChild != pStart->I_getRightChild())
		{
			pParent = F_ParentFind(pChild, pStart->I_getRightChild(), nData);
		}
	}
	else if (nData < pStart->I_getData())
	{
		if (pChild == pStart->I_getLeftChild())
		{
			pParent = pStart;
		}
		else if (pChild != pStart->I_getLeftChild())
		{
			pParent = F_ParentFind(pChild, pStart->I_getLeftChild(), nData);
		}
	}

	return pParent;
}

C_NODE ** C_TREE::F_NullChildFind(C_NODE * pStart, const int nData)
{
	C_NODE * pNode = nullptr;
	C_NODE ** ppChildDir = nullptr;

	pNode = F_InsertFind(pStart, nData);

	ppChildDir = pNode->I_getpLeft();

	return ppChildDir;
}

C_TREE::C_TREE() :
	m_pRoot(nullptr),
	m_pFinder(nullptr),
	m_ppNext(nullptr),
	m_pNew(nullptr)
{
	
}

void C_TREE::C_SetRootNode(C_NODE * pNode)
{
	m_pRoot = pNode;
}

C_NODE * C_TREE::C_GetRootNode()
{
	return m_pRoot;
}

C_NODE * C_TREE::C_CreateNode(const int nData)
{
	C_NODE * pNode = new C_NODE();

	m_pNew = nullptr;

	pNode->I_setData(nData);
	pNode->I_setLeftChild(nullptr);
	pNode->I_setRightChild(nullptr);

	m_pNew = pNode;
	pNode = nullptr;

	return m_pNew;
}

void C_TREE::C_DeleteNode(C_NODE * pNode)
{
	F_Release(pNode);
}

C_NODE * C_TREE::C_SearchNode(const int nData)
{
	C_NODE * pRoot = nullptr;
	C_NODE * pNode = nullptr;

	pRoot = C_GetRootNode();

	pNode = F_DeleteFind(pRoot, nData);

	return pNode;
}

void C_TREE::C_Init(const int nData)
{
	C_NODE * pNode = new C_NODE();

	pNode->I_setData(nData);

	m_pRoot = pNode;

	pNode = nullptr;
	m_pFinder = nullptr;
	m_ppNext = nullptr;
	m_pNew = nullptr;
}

void C_TREE::C_Insert(const int nData)
{
	m_pFinder = nullptr;
	m_ppNext = nullptr;

	m_pFinder = F_InsertFind(m_pRoot, nData);

	if (!m_pFinder)
	{
		return;
	}

	if (nData > m_pFinder->I_getData())
	{
		m_ppNext = m_pFinder->I_getpRight();
	}
	else if (nData < m_pFinder->I_getData())
	{
		m_ppNext =m_pFinder->I_getpLeft();
	}

	(*m_ppNext) = new C_NODE();

	(*m_ppNext)->I_setData(nData);


}

void C_TREE::C_Delete(const int nData)
{

	C_NODE * pParent = nullptr;
	C_NODE * pDelete = nullptr;
	C_NODE * pLeft = nullptr;
	C_NODE * pRight = nullptr;
	C_NODE ** ppChild = nullptr;

	pDelete = F_DeleteFind(m_pRoot, nData);

	pLeft = pDelete->I_getLeftChild();
	pRight = pDelete->I_getRightChild();

	if (nData == C_GetRootNode()->I_getData())
	{
		ppChild = &m_pRoot;	
	}
	else 
	{
		pParent = F_ParentFind(pDelete, m_pRoot, nData);

		if (nData > pParent->I_getData())
		{
			ppChild = pParent->I_getpRight();
		}
		else if (nData < pParent->I_getData())
		{
			ppChild = pParent->I_getpLeft();
		}
	}

	F_Release(pDelete);
	(*ppChild) = nullptr;
	
	if (pRight)
	{
		(*ppChild) = pRight;

		if (pLeft)
		{
			C_NODE ** ppNode = nullptr;
			ppNode = F_NullChildFind(C_GetRootNode(), pLeft->I_getData());
			(*ppNode) = pLeft;
		}
	}
	else if (!pRight && pLeft)
	{
		(*ppChild) = pLeft;
	}
}

void C_TREE::C_PrintAll(C_TREE::E_PRINTTYPE etype)
{
	if (!C_GetRootNode())
	{
		std::cout << "데이터가 없습니다!" << std::endl;
		return;
	}

	if (etype == C_TREE::E_PRINTTYPE::E_IN)
	{
		std::cout << "In Order : ";
	}
	else if (etype == C_TREE::E_PRINTTYPE::E_PRE)
	{
		std::cout << "Pre Order : ";
	}
	else if (etype == C_TREE::E_PRINTTYPE::E_POST)
	{
		std::cout << "Post Order : ";
	}

	F_PrintNode(C_GetRootNode(), etype);
	std::cout << std::endl;
	std::cout << std::endl;
}

void C_TREE::C_Clear()
{
	if (!C_GetRootNode())
	{
		std::cout << "데이터가 없습니다!" << std::endl;
		return;
	}
	F_AllDelete(C_GetRootNode());
	C_SetRootNode(nullptr);
	m_pFinder = nullptr;
	m_pNew = nullptr;
	m_ppNext = nullptr;
}

void C_TREE::F_Release(C_NODE * pNode)
{
	if (pNode)
	{
		delete pNode;
		pNode = nullptr;
	}
}

void C_TREE::F_PrintNode(C_NODE * pNode, C_TREE::E_PRINTTYPE etype)
{
	if (!pNode)
	{
		return;
	}

	if (etype == C_TREE::E_PRINTTYPE::E_IN)
	{
		F_ShowInOrder(pNode, etype);
	}
	else if (etype == C_TREE::E_PRINTTYPE::E_PRE)
	{
		F_ShowPreOrder(pNode, etype);
	}
	else if (etype == C_TREE::E_PRINTTYPE::E_POST)
	{
		F_ShowPostOrder(pNode, etype);
	}
	
}

void C_TREE::F_AllDelete(C_NODE * pNode)
{
	if (!pNode)
	{
		return;
	}

	F_AllDelete(pNode->I_getLeftChild());
	F_AllDelete(pNode->I_getRightChild());
	C_DeleteNode(pNode);
}

void C_TREE::F_ShowInOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype)
{
	F_PrintNode(pNode->I_getLeftChild(), etype);
	std::cout << pNode->I_getData() << " ";
	F_PrintNode(pNode->I_getRightChild(), etype);
}

void C_TREE::F_ShowPreOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype)
{
	std::cout << pNode->I_getData() << " ";
	F_PrintNode(pNode->I_getLeftChild(), etype);
	F_PrintNode(pNode->I_getRightChild(), etype);
}

void C_TREE::F_ShowPostOrder(C_NODE * pNode, C_TREE::E_PRINTTYPE etype)
{
	F_PrintNode(pNode->I_getLeftChild(), etype);
	F_PrintNode(pNode->I_getRightChild(), etype);
	std::cout << pNode->I_getData() << " ";
}
