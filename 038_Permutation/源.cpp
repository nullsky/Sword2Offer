#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/*
��Ŀ������ַ�����ȫ����,�ظ����ַ��������
˼·��������һ���ַ�
*/
void Permutation(char* pStr);
void PermutationCore(char* pStr, char* pBegin);

/*
��Ŀ������ַ������
˼·��
	1.��ϳ���Ϊk��1<= k <= n��
	2.������һ���ַ�����ʣ�µ���k-1���ַ�������������ʣ�µ���k���ַ�
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

	cout << "#2:����ַ����" << endl;
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