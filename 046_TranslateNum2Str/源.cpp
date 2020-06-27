#include <iostream>
#include <string>
using namespace std;

/*
题目：将数字翻译成字符串，求多少种不同翻译方法
描述：0-'a',1-'b',...25-'z'
方法：动态规划
*/
int TranslateNum2Str(int number);
int TranslateNum2Str(const string& str);

int main()
{
	cout << TranslateNum2Str(12258) << endl;
	system("pause");
	return 0;
}

int TranslateNum2Str(int number)
{
	if (number < 0)
		return 0;
	string str = to_string(number);
	return TranslateNum2Str(str);
}

int TranslateNum2Str(const string& str)
{
	int length = str.length();

	if (length == 1)
		return 1;

	int cnt_forward_2 = 1, cnt_forward_1 = 1;
	int cnt = 0;
	for (int i = 1; i < length; i++)
	{
		cnt = cnt_forward_1;

		int digit1 = str[i - 1] - '0';
		int digit2 = str[i] - '0';
		int convert = digit1 * 10 + digit2;
		if (convert >= 10 && convert <= 25)
			cnt += cnt_forward_2;

		cnt_forward_2 = cnt_forward_1;
		cnt_forward_1 = cnt;
	}
	return cnt;
}
