#pragma once

class I_ARRAY
{
private:
	int m_nSize;
public:
	I_ARRAY();

public:
	int* I_Create1ArrayInt(const int nsize);
	int* I_Resize1ArrayInt(int * pInt, const int nsize);
	void I_Clear1ArrayInt(int * pInt);

public:
	int I_GetLength();
};