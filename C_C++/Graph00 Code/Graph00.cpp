// Graph00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	C_GRAPH cGraph = C_GRAPH();
	C_GRAPH cGraph2 = C_GRAPH();

	cGraph.C_Init(20, "Graph1");

	cGraph.C_InsertVertex("1");
	cGraph.C_InsertVertex("2");
	cGraph.C_InsertVertex("3");
	cGraph.C_InsertVertex("4");
	cGraph.C_InsertVertex("5");
	cGraph.C_InsertVertex("6");
	cGraph.C_InsertVertex("7");
	cGraph.C_InsertVertex("8");
	cGraph.C_InsertVertex("9");

	cGraph.C_Connecting("1", "2");
	cGraph.C_Connecting("1", "4");
	cGraph.C_Connecting("1", "8");
	cGraph.C_Connecting("2", "3");
	cGraph.C_Connecting("4", "5");
	cGraph.C_Connecting("4", "7");
	cGraph.C_Connecting("5", "6");
	cGraph.C_Connecting("8", "9");

	cGraph.C_ShowDFS("1");

	cGraph.C_Release();

	cGraph2.C_Init(20,"Graph2");
	
	cGraph2.C_InsertVertex("1");
	cGraph2.C_InsertVertex("2");
	cGraph2.C_InsertVertex("3");
	cGraph2.C_InsertVertex("4");
	cGraph2.C_InsertVertex("5");
	cGraph2.C_InsertVertex("6");
	cGraph2.C_InsertVertex("7");
	cGraph2.C_InsertVertex("8");
	cGraph2.C_InsertVertex("9");

	cGraph2.C_Connecting("1", "2");
	cGraph2.C_Connecting("1", "3");
	cGraph2.C_Connecting("1", "4");
	cGraph2.C_Connecting("2", "5");
	cGraph2.C_Connecting("3", "6");
	cGraph2.C_Connecting("3", "7");
	cGraph2.C_Connecting("4", "8");
	cGraph2.C_Connecting("6", "9");

	cGraph2.C_ShowBFS("1");

	cGraph2.C_Release();
    return 0;
}

