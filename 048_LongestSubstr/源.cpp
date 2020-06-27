#include <iostream>
#include <string>
using namespace std;

/*
��Ŀ��������ظ��ַ����Ӵ�����,ֻ����a~z
���꣺���������ַ�������ʱ���鳤��Ϊ256
*/
int longestSubstrWithoutDuplication(const string& str);

int main()
{
	cout << longestSubstrWithoutDuplication("acfsca") << endl;
	system("pause");
	return 0;
}

int longestSubstrWithoutDuplication(const string& str)
{
	if (str.empty())
		return 0;

	int position[26];
	for (int i = 0; i < 26; i++)
		position[i] = -1;

	int maxLen = 0;
	int curLen = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int preIndex = position[str[i] - 'a'];
		if (preIndex < 0 || i - preIndex > curLen)
			curLen++;
		else
			curLen = i - preIndex;

		position[str[i] - 'a'] = i;
		maxLen = curLen > maxLen ? curLen : maxLen;
	}

	return maxLen;
}