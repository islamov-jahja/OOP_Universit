#include "stdafx.h"
#include "CHttpUrl.h"


CHttpUrl::CHttpUrl(std::string const & url)
{
	ParseUrl(url);
}

CHttpUrl::CHttpUrl(string const & domain, string const & document, Protocol protocol)
{
	if (protocol == HTTP)
	{
		ParseUrl(string("http://") + domain + document);
	}
	else if (protocol == HTTPS) 
	{
		ParseUrl(string("https://") + domain + document);
	}
}

CHttpUrl::CHttpUrl(string const & domain, string const & document, Protocol protocol, unsigned short port)
{
	if (port == 80 && protocol == HTTPS)
		throw CUrlParsingError("port and protocol mismatch");
	else if (port == 443 && protocol == HTTP)
		throw CUrlParsingError("port and protocol mismatch");

	if (protocol == HTTP)
	{
		ParseUrl(string("http://") + domain + document);
	}
	else if (protocol == HTTPS)
	{
		ParseUrl(string("https://") + domain + document);
	}
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

void CHttpUrl::ParseUrl(const string & url)
{
	string urlCpy = url;
	std::transform(urlCpy.begin(), urlCpy.end(), urlCpy.begin(), ::tolower);
	string urlSubString;
	int position;
	position = urlCpy.find('/');
	urlSubString = urlCpy.substr(0, position+1);

	if (urlSubString == "http:/")
	{
		m_protocol = HTTP;
		m_port = 80;
	}
	else if (urlSubString == "https:/")
	{
		m_protocol = HTTPS;
		m_port = 443;
	}
	else
		throw CUrlParsingError("incorrect protocol");

	urlCpy = urlCpy.substr(position + 2, urlCpy.length());
	position = urlCpy.find('/');
	if (position != -1)
		urlSubString = urlCpy.substr(0, position);
	else
	{
		urlSubString = urlCpy.substr(0, urlCpy.length());
		m_document = "";
		m_url = url;
	}

	if (IsDomain(urlSubString))
		m_domain = urlSubString;
	else
		throw CUrlParsingError("incorrect domain");

	if (position != -1)
	{
		urlCpy = urlCpy.substr(position, urlCpy.length());

		if (IsDocument(urlCpy))
		{
			m_document = urlCpy;
			m_url = url;
		}
		else
			throw CUrlParsingError("incorrect document");
	}
}

bool CHttpUrl::IsDomain(string const & domain)
{
	if (domain == "")
		return false;

	for (size_t i = 0; i < domain.length(); i++)
		if (i != (domain.length() - 1))
			if (domain[i] == '.' && domain[i+1] == '.')
				return false;

	return true;
}

bool CHttpUrl::IsDocument(string const & document)
{
	if (document[0] != '/')
		throw CUrlParsingError("incroccect document");

	string nameOfFile;
	string cpyDocument = document.substr(1, document.length());
	int pos;

	while (true)
	{
		pos = cpyDocument.find('/');

		if (pos != -1)
		{
			nameOfFile = cpyDocument.substr(0, pos);
			cpyDocument = cpyDocument.substr(pos + 1, cpyDocument.length());
			if (IsAJourney(nameOfFile) || nameOfFile == "")
				throw CUrlParsingError("incroccect document");
		}
		else
		{
			nameOfFile = cpyDocument;
			if (IsAJourney(nameOfFile) || nameOfFile == "")
				throw CUrlParsingError("incroccect document");
			break;
		}
	}

	return true;
}

bool CHttpUrl::IsAJourney(string const nameOfFile)
{
	string imprintedSymbols = "\\/*?\"<>|";
	for (size_t i = 0; i < nameOfFile.length(); i++)
		for (size_t j = 0; j < imprintedSymbols.length(); j++)
			if (nameOfFile[i] == imprintedSymbols[j])
				return true;

	return false;
}
