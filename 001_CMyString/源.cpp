#include <iostream>
using namespace std;

/*¸³Öµ²Ù×÷·ûÖØÔØ*/
class CMyString
{
public:
	CMyString(char * pData = nullptr);
	CMyString(const CMyString & str);
	CMyString & operator = (const CMyString & str);
	~CMyString();

private:
	char * m_pData;
};

CMyString::CMyString(char * pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString & str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString&  CMyString::operator = (const CMyString & str)
{
	if (this == &str)
		return *this;

	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

int main()
{
	char str[10] = "assds";
	CMyString s(str);
	CMyString s1;
	CMyString s2;
	s1 = s2 = s;
	return 0;
}
