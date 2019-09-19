#pragma once


class C_QUEUE
{
private:
	int m_nSize;
	int * m_pQueue;
	int m_nCount;
	int m_nBack;
	int m_nFront;

private:
	void OverflowMessage(const int nData);
	void UnderflowMessage();
public:
	C_QUEUE();
	void Init(int nSize);
	void Clear();
	void Enqueue(int nData);
	const int  Dequeue();
	const int  getSize();
	const int  getCount();


};
