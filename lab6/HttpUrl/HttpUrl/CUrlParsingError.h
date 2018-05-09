#pragma once
#include <string>
using namespace std;

class CUrlParsingError
{
public:
	CUrlParsingError(const string& message);
	string GetMessage()const;
	~CUrlParsingError();
private:
	string m_message;
};

