#include <iostream>
#include <string>
using namespace std;

/*
题目：返回第一个只出现一次的字符
*/
char TheFirstSingletonChar(string str);

int main()
{
	string s;
	while (cin >> s)
		cout << TheFirstSingletonChar(s) << endl;
	system("pasue");
	return 0;
}

char TheFirstSingletonChar(string str)
{
	const int tableSize = 256;
	unsigned int table[tableSize] = { 0 };

	for (int i = 0; i < str.size(); i++)
		table[str[i]]++;

	for (int i = 0; i < str.size(); i++)
	{
		if (table[str[i]] == 1)
			return str[i];
	}
	return '\0';
}