#include "stdafx.h"
#include "CStringStack.h"


CStringStack::CStringStack(const CStringStack & strStack)
{
	m_array = strStack.m_array;
}

CStringStack::CStringStack(CStringStack && strStack)
{
	m_array = move(strStack.m_array);
}

CStringStack::CStringStack(initializer_list<string> arr)
{
	m_array = arr;
}

void CStringStack::Push(const std::string & value)
{
	m_array.PushToEnd(value);
}

void CStringStack::Pop()
{
	if (m_array.Size() > 0)
		m_array.Resize(m_array.Size() - 1);
	else
		throw std::underflow_error("stack empty");
}

string CStringStack::Top() const
{
	if (m_array.Size() > 0)
		return m_array.End().GetValue();
	else
		throw std::underflow_error("stack empty");
}

size_t CStringStack::Size() const
{
	return m_array.Size();
}

void CStringStack::Clear()
{
	m_array.Clear();
}

CStringStack & CStringStack::operator=(const CStringStack & strStack)
{
	m_array = strStack.m_array;
	return *this;
}

CStringStack & CStringStack::operator=(CStringStack && strStack)
{
	m_array = move(strStack.m_array);
	return *this;
}


