// Stack00.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	C_STACK cStack = C_STACK();

	cStack.Init(10);

	cStack.Push(10);
	cStack.Push(20);
	cStack.Push(25);
	
	std::cout << "���� ���� ���� ����� ������ : " << cStack.getCount() << "��" << std::endl;
	std::cout << cStack.Pop() << std::endl; 
	std::cout << "���� ���� ���� ����� ������ : " << cStack.getCount() << "��" << std::endl;
	std::cout << cStack.Pop() << std::endl;
	std::cout << "���� ���� ���� ����� ������ : " << cStack.getCount() << "��" << std::endl;
	std::cout << cStack.Pop() << std::endl;

	std::cout << "�� ������ ũ��� : " << cStack.getSize() << "��" << std::endl;
	std::cout << "���� ���� ���� ����� ������ : " << cStack.getCount() << "��" << std::endl;
	cStack.Clear();
    return 0;
}

