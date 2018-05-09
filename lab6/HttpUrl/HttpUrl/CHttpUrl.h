#pragma once
#include <iostream>
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
	string m_url;
	string m_domain;
	string m_document;
	Protocol m_protocol;
	unsigned short m_port;
	bool IsDomain(const string& domain)const;
	bool IsDocument(const string& document)const;
};

