#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
题目：输出数组组合的最小数字
*/

void PrintMinNum(int* arr, int length);
int main()
{
	int arr[3] = { 3, 32, 321 };
	PrintMinNum(arr, 3);
	system("pause");
	return 0;
}

static bool Camp(const string & s1, const string & s2)
{
	string s1s2 = s1 + s2;
	string s2s1 = s2 + s1;
	return s1s2 < s2s1;
}
void PrintMinNum(int* arr, int length)
{
	if (arr == nullptr || length < 1)
		return;

	vector<string> strNums;
	for (int i = 0; i < length; i++)
		strNums.push_back(to_string(arr[i]));
	
	sort(strNums.begin(), strNums.end(), Camp);
	for(auto s : strNums)
	{
		cout << s;
	}
}