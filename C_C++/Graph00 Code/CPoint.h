#pragma once

class C_POINT
{
private:
	char * m_strName;
	int m_nId;


public:
	C_POINT();

public:
	void SetName(char * strName);
	const char * GetName();
	void SetId(int nId);
	int GetId();

};