#include "stdafx.h"
#include "CHttpUrl.h"


CHttpUrl::CHttpUrl(std::string const & url)
{
}

CHttpUrl::CHttpUrl(string const & domain, string const & document, Protocol protocol)
{
}

CHttpUrl::CHttpUrl(string const & domain, string const & document, Protocol protocol, unsigned short port)
{
}

string CHttpUrl::GetURL() const
{
	return m_url;
}

string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

CHttpUrl::~CHttpUrl()
{
}

bool CHttpUrl::IsDomain(const string & domain) const
{
	return false;
}

bool CHttpUrl::IsDocument(const string & document) const
{
	return false;
}
