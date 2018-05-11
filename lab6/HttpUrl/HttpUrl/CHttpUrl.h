#pragma once
#include <iostream>
#include "CUrlParsingError.h"
#include <algorithm>
using namespace std;
enum Protocol
{
	HTTP,
	HTTPS
};

class CHttpUrl
{
public:
	CHttpUrl(std::string const& url);
	CHttpUrl(string const& domain, string const& document, Protocol protocol = HTTP);
	CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);
	string GetURL()const;
	string GetDomain()const;
	std::string GetDocument()const;
	Protocol GetProtocol()const;
	unsigned short GetPort()const;
	~CHttpUrl();
private:
	string m_url = "";
	string m_domain = "";
	string m_document = "";
	Protocol m_protocol = HTTP;
	unsigned short m_port;
	void ParseUrl(string const& url);
	bool IsDomain(string const& domain);
	bool IsDocument(string const& document);
	bool IsAJourney(string const nameOfFile);
};

