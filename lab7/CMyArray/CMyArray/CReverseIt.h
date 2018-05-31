#pragma once

template <typename Type>
class CReverseIt
{
public:
	CReverseIt();
	CReverseIt(Type* iterator);
	bool operator==(const CReverseIt& other) const;
	bool operator!=(const CReverseIt& other) const;
	CReverseIt<Type>& operator=(const CReverseIt& other);
	Type GetValue() const;
	CReverseIt<Type>& operator++();
	CReverseIt<Type>& operator--();
	const CReverseIt<Type> operator++(int);
	const CReverseIt<Type> operator--(int);
	~CReverseIt();
private:
	Type * m_it = nullptr;
};

template<typename Type>
inline CReverseIt<Type>::CReverseIt()
{
}

template<typename Type>
inline CReverseIt<Type>::CReverseIt(Type * iterator)
	:m_it(iterator)
{
}

template<typename Type>
inline bool CReverseIt<Type>::operator==(const CReverseIt & other) const
{
	return m_it == other.m_it;
}

template<typename Type>
inline bool CReverseIt<Type>::operator!=(const CReverseIt & other) const
{
	return m_it != other.m_it;
}

template<typename Type>
inline CReverseIt<Type>& CReverseIt<Type>::operator=(const CReverseIt & other)
{
	if (addressof(other) != this)
		m_it = other.m_it;

	return *this;
}

template<typename Type>
inline Type CReverseIt<Type>::GetValue() const
{
	return *m_it;
}

template<typename Type>
inline CReverseIt<Type>& CReverseIt<Type>::operator++()
{
	m_it--;
	return *this;
}

template<typename Type>
inline CReverseIt<Type>& CReverseIt<Type>::operator--()
{
	m_it++;
	return *this;
}

template<typename Type>
inline const CReverseIt<Type> CReverseIt<Type>::operator++(int)
{
	auto it = --m_it;
	return it;
}

template<typename Type>
inline const CReverseIt<Type> CReverseIt<Type>::operator--(int)
{
	auto it = ++m_it;
	return it;
}

template<typename Type>
inline CReverseIt<Type>::~CReverseIt()
{
}
