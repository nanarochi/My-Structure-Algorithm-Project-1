// Queue00.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	C_QUEUE cQueue = C_QUEUE();

	cQueue.Init(10);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);
	cQueue.Enqueue(20);
	cQueue.Enqueue(34);

	std::cout << "������ �޸��� �� ���� : "<<cQueue.getSize() << "��" << std::endl;
	std::cout << "ť�� �Էµ� �ڷ��� ���� : " << cQueue.getCount() << "��" << std::endl;

 	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;
	std::cout << cQueue.Dequeue() << std::endl;

	cQueue.Clear();
	return 0;
}
