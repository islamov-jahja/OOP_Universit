#pragma once
#include "CMyIterator.h"
#include "CReverseIt.h"
#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include <sstream>
using namespace std;

template <typename Type>
class CMyArray
{
public:
	CMyArray() = default;
	size_t Size() const;
	CMyArray(initializer_list<Type> arr);
	const Type& operator[](size_t index) const;
	Type& operator[](size_t index);
	CMyArray(const CMyArray& arr);
	CMyIterator<Type> Begin() const;
	CMyIterator<Type> End() const;
	CMyArray(CMyArray&& arr);
	void PushToEnd(const Type& value);
	CReverseIt<Type> RBegin() const;
	CReverseIt<Type> REnd() const;
	void Clear();
	CMyArray<Type>& operator=(const CMyArray& other);
	CMyArray<Type>& operator=(CMyArray && other);
	void Resize(const size_t newSize);
	~CMyArray();
private:
	Type * m_end = nullptr;
	Type * m_begin = nullptr;
	size_t m_length = 0;
};

template <typename Type>
CMyArray<Type>::CMyArray(CMyArray&& arr)
{
	m_begin = arr.m_begin;
	arr.m_begin = nullptr;
	m_end = arr.m_end;
	arr.m_end = nullptr;
	m_length = arr.m_length;
	arr.m_length = 0;
}

template<typename Type>
inline void CMyArray<Type>::PushToEnd(const Type & value)
{
	m_length++;
	Type * tmpArr = new Type[m_length];

	if (!tmpArr)
	{
		throw std::bad_alloc();
	}

	for (size_t i = 0; i < m_length - 1; i++)
		*(tmpArr + i) = *(m_begin + i);

	*(tmpArr + (m_length - 1)) = value;
	delete[] m_begin;
	m_begin = tmpArr;
	tmpArr = nullptr;
	m_end = m_begin + (m_length - 1);
}

template<typename Type>
inline CReverseIt<Type> CMyArray<Type>::RBegin() const
{
	return m_end;
}

template<typename Type>
inline CReverseIt<Type> CMyArray<Type>::REnd() const
{
	return m_begin;
}

template<typename Type>
inline void CMyArray<Type>::Clear()
{
	delete[] m_begin;
	m_begin = nullptr;
	m_end = nullptr;
	m_length = 0;
}

template<typename Type>
inline CMyArray<Type>& CMyArray<Type>::operator=(const CMyArray & other)
{
	Clear();
	Type * tmpArr = new Type[other.Size()];

	if (!tmpArr)
		throw std::bad_alloc();

	if (std::addressof(other) != this)
		for (size_t i = 0; i < other.Size(); i++)
			*(tmpArr + i) = other[i];

	m_begin = tmpArr;

	m_end = m_begin + (other.Size() - 1);
	m_length = other.Size();
	return *this;
}

template<typename Type>
inline CMyArray<Type>& CMyArray<Type>::operator=(CMyArray && other)
{
	m_begin = other.m_begin;
	other.m_begin = nullptr;
	m_end = other.m_end;
	other.m_end = nullptr;
	m_length = other.m_length;
	other.m_length = 0;
	return *this;
}

template<typename Type>
inline void CMyArray<Type>::Resize(const size_t newSize)
{
	if (m_length == newSize)
		return;
	else if (m_length > newSize)
	{
		Type * tmpArr = new Type[newSize];

		if (!tmpArr)
		{
			throw std::bad_alloc();
		}

		for (size_t i = 0; i < newSize; i++)
			*(tmpArr + i) = *(m_begin + i);

		delete[] m_begin;
		m_begin = tmpArr;
		m_end = m_begin + (newSize - 1);
		m_length = newSize;
	}
	else if (m_length < newSize)
	{
		Type * tmpArr = new Type[newSize];
		
		if (!tmpArr)
		{
			throw std::bad_alloc();
		}
        
		for (size_t i = 0; i < newSize; i++)
			*(tmpArr + i) = Type();

		for (size_t i = 0; i < m_length; i++)
			*(tmpArr + i) = *(m_begin + i);

		delete[] m_begin;
		m_begin = tmpArr;
		m_end = m_begin + (newSize - 1);
		m_length = newSize;
	}
}

template <typename Type>
CMyIterator<Type> CMyArray<Type>::End() const
{
	return m_end;
}

template <typename Type>
CMyIterator<Type> CMyArray<Type>::Begin() const
{
	return m_begin;
}

template <typename Type>
CMyArray<Type>::CMyArray(const CMyArray& arr)
{
	m_begin = new Type[arr.Size()];

	if (!m_begin)
	{
		throw std::bad_alloc();
	}

	for (size_t i = 0; i < arr.Size(); i++)
		*(m_begin + i) = arr[i];

	m_end = m_begin + (arr.Size() - 1);
	m_length = arr.Size();
}

template <typename Type>
CMyArray<Type>::CMyArray(initializer_list<Type> arr)
{
	m_begin = new Type[arr.size()];

	if (!m_begin)
	{
		throw std::bad_alloc();
	}

	int i = 0;
	for (auto x : arr)
	{
		*(m_begin + i) = x;
		i++;
	}

	m_end = m_begin + (arr.size() - 1);
	m_length = arr.size();
}

template <typename Type>
size_t CMyArray<Type>::Size() const
{
	return m_length;
}

template<typename Type>
inline const Type & CMyArray<Type>::operator[](size_t index) const
{
	if (index >= 0 && index < m_length)
		return *(m_begin + index);
	else
		throw out_of_range("out of range");
}

template<typename Type>
inline Type & CMyArray<Type>::operator[](size_t index)
{
	if (index >= 0 && index < m_length)
		return *(m_begin + index);
	else
		throw out_of_range("out of range");
}

template <typename Type>
CMyArray<Type>::~CMyArray()
{
	delete[] m_begin;
}
