// LinkedList00.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"



int main()
{
	C_LINKEDLIST clist = C_LINKEDLIST();
	std::string	 str = std::string();
	const S_NODE * pElement = nullptr;

	clist.Init("금가락지");
	clist.Add("금반지");
	clist.Add("금이빨");
	clist.Add("핵폭탄");
	clist.Add("게임기");
	clist.Add("금요일");
	str = clist.Find("금이빨")->s_pName;
	std::cout << str << std::endl << std::endl;
	pElement = clist.Find("핵폭탄");
	
	std::cout << "ID : " << pElement->s_nId << " Name : " << pElement->s_pName << std::endl << std::endl;
	clist.Allshow();
	clist.setIter(clist.Find("금반지"));
	clist.getIter()->s_pName = "금반지2";//미숙한 설계로 인한 접근되지 말아야 할 멤버 변수에 접근가능한 경우.
								        //노드를 구조체가 아닌 클래스로 조립해야 됨.
	std::cout << "ID : " << clist.getIter()->s_nId<< " Name : " << clist.getIter()->s_pName << std::endl << std::endl;
	clist.Sub("금가락지");
	clist.Allshow();
	clist.Sub("핵폭탄");
	clist.Allshow();
	clist.Sub("금요일");
	clist.Allshow();
	clist.Clear();


    return 0;
}

