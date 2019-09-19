#include "stdafx.h"
#include "CPoint.h"

C_POINT::C_POINT() :
	m_nId(0),
	m_strName(nullptr)

{
}

void C_POINT::SetName(char * strName)
{
	m_strName = strName;
}

const char * C_POINT::GetName()
{
	return m_strName;
}

void C_POINT::SetId(int nId)
{
	m_nId = nId;
}

int C_POINT::GetId()
{
	return m_nId;
}



