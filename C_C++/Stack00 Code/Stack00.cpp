// Stack00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	C_STACK cStack = C_STACK();

	cStack.Init(10);

	cStack.Push(10);
	cStack.Push(20);
	cStack.Push(25);
	
	std::cout << "현재 스택 안의 요소의 개수는 : " << cStack.getCount() << "개" << std::endl;
	std::cout << cStack.Pop() << std::endl; 
	std::cout << "현재 스택 안의 요소의 개수는 : " << cStack.getCount() << "개" << std::endl;
	std::cout << cStack.Pop() << std::endl;
	std::cout << "현재 스택 안의 요소의 개수는 : " << cStack.getCount() << "개" << std::endl;
	std::cout << cStack.Pop() << std::endl;

	std::cout << "총 스택의 크기는 : " << cStack.getSize() << "개" << std::endl;
	std::cout << "현재 스택 안의 요소의 개수는 : " << cStack.getCount() << "개" << std::endl;
	cStack.Clear();
    return 0;
}

