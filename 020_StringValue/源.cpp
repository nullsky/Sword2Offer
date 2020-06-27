#include <iostream>
using namespace std;

/*
��Ŀ����ʾ��ֵ���ַ���
��ʽ��A[.[B]][e|EC] �� .[B][e|EC]
ָ�����������������ȼ�
*/
bool isNumberic(const char * str);
bool scanInt(const char ** str);
bool scanUnsignedInt(const char ** str);

int main()
{
	char numberic[10];
	cin >> numberic;
	cout << isNumberic(numberic) << endl;
	system("pause");
	return 0;
}

bool isNumberic(const char * str)
{
	if (nullptr == str) return false;

	bool bNumberic = scanInt(&str);

	if (*str == '.')
	{
		str++;
		bNumberic = scanUnsignedInt(&str) || bNumberic;
	}

	if (*str == 'e' || *str == 'E')
	{
		str++;
		bNumberic = bNumberic && scanInt(&str);
	}

	return bNumberic && *str == '\0';
}

bool scanInt(const char ** str)
{
	if (**str == '-' || **str == '+')
		(*str)++;

	return scanUnsignedInt(str);
}

bool scanUnsignedInt(const char ** str)
{
	const char * before = *str;
	while (**str >= '0' && **str <= '9')
	{
		(*str)++;
	}

	return *str > before;
}