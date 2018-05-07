#pragma once
#include <iostream>
#include <memory>
#include <iostream>
#include <algorithm>
const size_t SIZE_OF_BUFF = 2048;

using namespace std;

class CMyString
{
public:
	CMyString();
	size_t GetLength()const;
	const char* GetStringData()const;
	CMyString(const char * pString);
	CMyString(const char * pString, size_t length);
	CMyString(CMyString const& other);
	CMyString(CMyString && other);
    CMyString(std::string const& stlString);
	CMyString SubString(size_t start, size_t length)const;
	void Clear();
	bool CMyString::operator ==(CMyString const& other) const;
	bool CMyString::operator !=(CMyString const& other) const;
	CMyString& CMyString::operator =(CMyString const& other);
	CMyString& operator=(CMyString && other);
	const char & operator[](size_t index)const;
	char & operator[](size_t index);
	CMyString& CMyString::operator +=(CMyString const& other);
	CMyString const CMyString::operator +(CMyString const& other) const;
	bool CMyString::operator >(CMyString const& other) const;
	bool CMyString::operator <(CMyString const& other) const;
	bool CMyString::operator >=(CMyString const& other) const;
	bool CMyString::operator <=(CMyString const& other) const;
	friend istream& operator >>(istream& stream, CMyString& other);
	~CMyString();
private:
	unique_ptr<char[]> m_pChars = nullptr;
	size_t m_length = 0;
};

CMyString operator +(const string &stringLine, const CMyString &myStringLine);
CMyString operator +(const char* pString, const CMyString &myStringLine);
ostream& operator <<(ostream& stream, CMyString const& other);