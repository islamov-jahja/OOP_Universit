#pragma once
#include "../../../lab7/CMyArray/CMyArray/CMyArray.h" 

class CStringStack
{
public:
	CStringStack() = default;
	CStringStack(const CStringStack& strStack);
	CStringStack(CStringStack&& strStack);
	CStringStack(initializer_list<string> arr);
	void Push(const std::string& value);
	void Pop();
	string Top() const;
	size_t Size() const;
	void Clear();
	CStringStack& operator=(const CStringStack& strStack);
	CStringStack& operator=(CStringStack&& strStack);
	~CStringStack() = default;
private:
	CMyArray<string> m_array;
};

