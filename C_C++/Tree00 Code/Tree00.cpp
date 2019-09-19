// Tree00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	C_TREE cTree = C_TREE();

	cTree.C_Init(8);
	cTree.C_Insert(3);
	cTree.C_Insert(10);
	cTree.C_Insert(1);
	cTree.C_Insert(6);
	cTree.C_Insert(14);
	cTree.C_Insert(4);
	cTree.C_Insert(7);
	cTree.C_Insert(13);
	cTree.C_Delete(8);
	cTree.C_Insert(8);

	cTree.C_PrintAll(C_TREE::E_PRINTTYPE::E_IN);
	cTree.C_PrintAll(C_TREE::E_PRINTTYPE::E_PRE);
	cTree.C_PrintAll(C_TREE::E_PRINTTYPE::E_POST);
	cTree.C_Clear();
	
    return 0;
}

