// Heap00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	C_HEAP cHeap = C_HEAP();

	cHeap.C_CreateHeap(12);
	cHeap.C_Insert_Max(1);
	cHeap.C_Insert_Max(10);
	cHeap.C_Insert_Max(11);
	cHeap.C_Insert_Max(5);
	cHeap.C_Insert_Max(7);
	std::cout << ":: Remove before ::" << std::endl;
	cHeap.C_PrintAll(C_HEAP::E_PRINTTYPE::E_MAX);
	cHeap.C_Remove_Max();
	std::cout << ":: Remove after ::" << std::endl;
	cHeap.C_PrintAll(C_HEAP::E_PRINTTYPE::E_MAX);	
	cHeap.C_ResizeHeap(20);
	cHeap.C_Insert_Max(12);
	cHeap.C_Insert_Max(14);
	cHeap.C_Insert_Max(3);
	cHeap.C_Insert_Max(8);
	cHeap.C_Insert_Max(50);
	cHeap.C_Insert_Max(100);
	cHeap.C_PrintAll(C_HEAP::E_PRINTTYPE::E_MAX);

	cHeap.C_ReleaseHeap();

	cHeap.C_CreateHeap(12);
	cHeap.C_Insert_Min(1);
	cHeap.C_Insert_Min(10);
	cHeap.C_Insert_Min(11);
	cHeap.C_Insert_Min(5);
	cHeap.C_Insert_Min(7);
	std::cout << ":: Remove before ::" << std::endl;
	cHeap.C_PrintAll(C_HEAP::E_PRINTTYPE::E_MIN);
	cHeap.C_Remove_Min();
	std::cout << ":: Remove after ::" << std::endl;
	cHeap.C_PrintAll(C_HEAP::E_PRINTTYPE::E_MIN);
	cHeap.C_ReleaseHeap();
    return 0;
}

