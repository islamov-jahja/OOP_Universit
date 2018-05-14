#include "stdafx.h"
#include "CMyString.h"


CMyString::CMyString()
{
	m_pChars = nullptr;
	m_length = 0;
}

size_t CMyString::GetLength() const
{
	return m_length;;
}

const char * CMyString::GetStringData() const
{
    return m_pChars.get();
}

CMyString::CMyString(const char * pString)
{
	m_length = strlen(pString);
	m_pChars = make_unique<char[]>(m_length+1);
	memcpy(m_pChars.get(), (pString + '\0'), m_length+1);
}

CMyString::CMyString(const char * pString, size_t length)
{
	size_t lengthOfArr = strlen(pString);

	if (length != 0)
	{
		m_pChars = make_unique<char[]>(length+1);
		memcpy(m_pChars.get(), pString, length);
		m_length = length;
		m_pChars[length] = '\0';
	}
	else
		m_pChars = nullptr;
}

CMyString::CMyString(CMyString const & other)
{
	m_length = other.GetLength();

	if (m_length != 0)
	{
		m_pChars = make_unique<char[]>(m_length+1);
		memcpy(m_pChars.get(), other.GetStringData(), m_length+1);
	}
	else
		m_pChars = nullptr;
}

void CMyString::Clear()
{
	m_pChars = nullptr;
	m_length = 0;
}

bool CMyString::operator==(CMyString const & other) const
{
	if (m_length != other.GetLength())
		return false;
	else
	{
		for (size_t i = 0; i < m_length; i++)
			if (m_pChars[i] != *(other.GetStringData() + i))
				return false;

		return true;
	}
}

bool CMyString::operator!=(CMyString const & other) const
{
	if (m_length != other.GetLength())
		return true;
	else
	{
		for (size_t i = 0; i < m_length; i++)
			if (m_pChars[i] != *(other.GetStringData() + i))
				return true;

		return false;
	}
}

CMyString & CMyString::operator=(CMyString const & other)
{
	if (std::addressof(other) != this)
	{
		CMyString tmpCopy(other);
		swap(m_pChars, tmpCopy.m_pChars);
		swap(m_length, tmpCopy.m_length);
	}
	return *this;
}

CMyString & CMyString::operator=(CMyString && other)
{
	if (&other != this)
	{
		m_pChars = move(other.m_pChars);
		m_length = other.m_length;
		other.Clear();
	}
	return *this;

}

const char & CMyString::operator[](size_t index) const
{
	if (index >= 0 && index < m_length)
		return m_pChars[index];
	else
		throw out_of_range("out of range");
}

char & CMyString::operator[](size_t index)
{
	if (index >= 0 && index < m_length)
		return m_pChars[index];
	else
		throw out_of_range("out of range");
}

CMyString & CMyString::operator+=(CMyString const & other)
{
	unique_ptr<char[]> newTmpPtrOfChars = make_unique<char[]>(m_length + other.m_length + 1);
	memcpy(newTmpPtrOfChars.get(), m_pChars.get(), m_length);
	memcpy(newTmpPtrOfChars.get() + m_length, other.m_pChars.get(), other.m_length + 1);
	m_pChars = move(newTmpPtrOfChars);
	m_length = strlen(m_pChars.get());
	return *this;
}

CMyString const CMyString::operator+(CMyString const & other) const
{
	unique_ptr<char[]> pCharsForNewString = make_unique<char[]>(m_length + other.m_length);
	memcpy(pCharsForNewString.get(), m_pChars.get(), m_length);
	memcpy(pCharsForNewString.get()+m_length, other.m_pChars.get(), other.m_length);
	return CMyString(pCharsForNewString.get(), m_length + other.m_length);
}

bool CMyString::operator>(CMyString const & other) const
{
	for (size_t i = 0; i < (min(m_length, other.m_length)); i++)
		if (m_pChars[i] > other.m_pChars[i])
			return true;

	if (m_length > other.m_length)
		return true;
	else
		return false;;
}

bool CMyString::operator<(CMyString const & other) const
{
	for (size_t i = 0; i < (min(m_length, other.m_length)); i++)
		if (m_pChars[i] < other.m_pChars[i])
			return true;

	if (m_length < other.m_length)
		return true;
	else
    	return false;
}

bool CMyString::operator>=(CMyString const & other) const
{
	if (!operator<(other))
		return true;
	else
		return false;
}

bool CMyString::operator<=(CMyString const & other) const
{
	if (!operator>(other))
		return true;
	else
		return false;
}

CMyString::CMyString(CMyString && other)
{
	m_length = other.m_length;

	if (m_length != 0)
	{
		m_pChars = move(other.m_pChars);
		m_length = other.m_length;
		other.Clear();
	}
	else
		m_pChars = nullptr;

}

CMyString::CMyString(std::string const & stlString)
{
	m_length = stlString.length();

	if (m_length != 0)
	{
		m_pChars = make_unique<char[]>(m_length + 1);
		memcpy(m_pChars.get(), stlString.c_str() + '\0', m_length);
	}
	else
		m_pChars = nullptr;
}

CMyString::~CMyString()
{
}



CMyString CMyString::SubString(size_t start, size_t length) const
{
	const char* pChars = m_pChars.get();
	pChars = pChars + (start - 1);
	if (length > m_length - start)
	{
		unique_ptr<char> line(new char[length]);
		memcpy(line.get(), pChars, length);
		return CMyString(line.get(), length);
	}
	else
	{
		unique_ptr<char> line(new char[m_length - start]);
		memcpy(line.get(), pChars, start);
		return CMyString(line.get(), m_length - start);
	}

}

istream & operator>>(istream & stream, CMyString & other)
{
	char buff[2048];
	stream.getline(buff, SIZE_OF_BUFF);
	other = buff;
	return stream;
}

CMyString operator+(const string & stringLine, const CMyString & myStringLine)
{
	unique_ptr<char[]> pCharsForNewString = make_unique<char[]>(stringLine.length() + myStringLine.GetLength());
	memcpy(pCharsForNewString.get(), stringLine.c_str(), stringLine.length());
	memcpy(pCharsForNewString.get() + stringLine.length(), myStringLine.GetStringData(), myStringLine.GetLength());
	return CMyString(pCharsForNewString.get(), stringLine.length() + myStringLine.GetLength());
}

CMyString operator+(const char * pString, const CMyString & myStringLine)
{
	size_t arrayLenght = strlen(pString);
	unique_ptr<char[]> pCharsForNewString = make_unique<char[]>(arrayLenght + myStringLine.GetLength());
	memcpy(pCharsForNewString.get(), pString, arrayLenght);
	memcpy(pCharsForNewString.get() + arrayLenght, myStringLine.GetStringData(), myStringLine.GetLength());
	return CMyString(pCharsForNewString.get(), arrayLenght + myStringLine.GetLength());
}



std::ostream & operator<<(std::ostream & stream, CMyString const & other)
{
	if (other.GetStringData() != nullptr)
			stream << other.GetStringData();

	return stream;
}
