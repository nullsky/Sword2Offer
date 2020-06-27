#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/*
题目：输出字符串的全排列,重复的字符串不输出
思路：交换第一个字符
*/
void Permutation(char* pStr);
void PermutationCore(char* pStr, char* pBegin);

/*
题目：输出字符的组合
思路：
	1.组合长度为k（1<= k <= n）
	2.包含第一个字符，在剩下的找k-1个字符；不包含，在剩下的找k个字符
*/
void Combination(string str);
void CombinationCore(string str, int len, int start, int end, string& res);

int main()
{
	// #1
	char* aa = "121";
	char* str = new char[4];
	strcpy(str, aa);
	Permutation(str);
	cout << endl;

	cout << "#2:输出字符组合" << endl;
	Combination("qeer");
	system("pause");
	return 0;
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
		return;
	PermutationCore(pStr, pStr);
}

void PermutationCore(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
		return;
	}

	unordered_set<char> record;
	for (char* pCh = pBegin; *pCh != '\0'; pCh++)
	{
		if (record.count(*pCh))
			continue;

		record.insert(*pCh);
		char tmp = *pCh;
		*pCh = *pBegin;
		*pBegin = tmp;

		PermutationCore(pStr, pBegin + 1);

		tmp = *pCh;
		*pCh = *pBegin;
		*pBegin = tmp;
	}
}

void Combination(string str)
{
	if (str.empty())
		return;
	
	string res;
	for (int i = 1; i <= str.size(); i++)
		CombinationCore(str, i, 0, str.size() - 1, res);
}

void CombinationCore(string str, int len, int start, int end, string& res)
{
	if (len == 0)
	{
		cout << res << endl;
		return;
	}

	if (start > end)
		return;
	else
	{
		res.push_back(str[start]);
		CombinationCore(str, len - 1, start + 1, end, res);
		res.pop_back();
		CombinationCore(str, len, start + 1, end, res);
	}
}