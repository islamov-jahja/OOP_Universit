#pragma once

template <typename Type>
class CMyIterator
{
public:
	CMyIterator();
	CMyIterator(Type* iterator);
	bool operator==(const CMyIterator& other) const;
	bool operator!=(const CMyIterator& other) const;
	CMyIterator<Type>& operator=(const CMyIterator& other);
	Type GetValue() const;
	CMyIterator<Type>& operator++();
	CMyIterator<Type>& operator--();
	const CMyIterator<Type> operator++(int);
	const CMyIterator<Type> operator--(int);
	~CMyIterator();
private:
	Type * m_it = nullptr;
};

template <typename Type>
CMyIterator<Type>::CMyIterator()
{
}

template <typename Type>
CMyIterator<Type>::CMyIterator(Type* it)
	:m_it(it)
{
}

template <typename Type>
bool CMyIterator<Type>::operator==(const CMyIterator& other) const
{
	return m_it == other.m_it;
}

template <typename Type>
bool CMyIterator<Type>::operator!=(const CMyIterator& other) const
{
	return m_it != other.m_it;
}

template <typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator=(const CMyIterator& other)
{
	if (addressof(other) != this)
		m_it = other.m_it;

	return *this;
}

template <typename Type>
Type CMyIterator<Type>::GetValue()const
{
	return *m_it;
}

template <typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator++()
{
	m_it++;
	return *this;
}

template <typename Type>
CMyIterator<Type>& CMyIterator<Type>::operator--()
{
	m_it--;
	return *this;
}

template <typename Type>
const CMyIterator<Type> CMyIterator<Type>::operator++(int)
{
	auto it = ++m_it;
	return it;
}

template <typename Type>
const CMyIterator<Type> CMyIterator<Type>::operator--(int)
{
	auto it = --m_it;
	return it;
}



template <typename Type>
CMyIterator<Type>::~CMyIterator()
{
}
