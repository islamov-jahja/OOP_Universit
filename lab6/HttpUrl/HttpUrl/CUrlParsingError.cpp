#include "stdafx.h"
#include "CUrlParsingError.h"


CUrlParsingError::CUrlParsingError(const string& message)
	:m_message(message)
{
}

string CUrlParsingError::GetMessage() const
{
	return m_message;
}


CUrlParsingError::~CUrlParsingError()
{
}
