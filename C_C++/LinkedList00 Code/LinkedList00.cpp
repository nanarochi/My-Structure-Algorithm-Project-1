// LinkedList00.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"



int main()
{
	C_LINKEDLIST clist = C_LINKEDLIST();
	std::string	 str = std::string();
	const S_NODE * pElement = nullptr;

	clist.Init("�ݰ�����");
	clist.Add("�ݹ���");
	clist.Add("���̻�");
	clist.Add("����ź");
	clist.Add("���ӱ�");
	clist.Add("�ݿ���");
	str = clist.Find("���̻�")->s_pName;
	std::cout << str << std::endl << std::endl;
	pElement = clist.Find("����ź");
	
	std::cout << "ID : " << pElement->s_nId << " Name : " << pElement->s_pName << std::endl << std::endl;
	clist.Allshow();
	clist.setIter(clist.Find("�ݹ���"));
	clist.getIter()->s_pName = "�ݹ���2";//�̼��� ����� ���� ���ٵ��� ���ƾ� �� ��� ������ ���ٰ����� ���.
								        //��带 ����ü�� �ƴ� Ŭ������ �����ؾ� ��.
	std::cout << "ID : " << clist.getIter()->s_nId<< " Name : " << clist.getIter()->s_pName << std::endl << std::endl;
	clist.Sub("�ݰ�����");
	clist.Allshow();
	clist.Sub("����ź");
	clist.Allshow();
	clist.Sub("�ݿ���");
	clist.Allshow();
	clist.Clear();


    return 0;
}

