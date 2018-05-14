// HttpUrl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h";
#include "CUrlParsingError.h";
#include <vector>


void PrintUrl(const CHttpUrl& url);
int main()
{
	string url;

	while (!cin.eof())
	{
		try
		{
			getline(cin, url);
			CHttpUrl url(url);
			PrintUrl(url);
		}
		catch (const CUrlParsingError& error)
		{
			cout << error.GetMessage() << endl;;
		}
	}

    return 0;
}

void PrintUrl(const CHttpUrl& url)
{
	cout << endl;
	int port = url.GetPort();
	cout << "Port: " << port << endl;
	if (url.GetProtocol() == HTTP)
		cout << "Protool: http" << endl;
	else
		cout << "Protool: https" << endl;

	cout << "Domain: " + url.GetDomain() << endl;
	cout << "Document: " + url.GetDocument() << endl;
	cout << "Url: " + url.GetURL() << endl;
}
