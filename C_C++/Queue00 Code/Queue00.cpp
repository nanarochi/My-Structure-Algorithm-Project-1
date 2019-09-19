// Queue00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

	std::cout << "예약한 메모리의 총 개수 : "<<cQueue.getSize() << "개" << std::endl;
	std::cout << "큐에 입력된 자료의 개수 : " << cQueue.getCount() << "개" << std::endl;

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
