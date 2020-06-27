#include <iostream>
using namespace std;

/*
题目：数字序列的某一位数字，012345678910111213...索引从0开始
*/
int DigitAtIndex(int index);

int main()
{
	int index;
	while(cin >> index)
		cout << DigitAtIndex(index) << endl;
	system("pause");
	return 0;
}

int DigitAtIndex(int index)
{
	if (index == 0)
		return 0;

	int digit = 0;
	int maxIndex = 0;
	while (index > maxIndex)
	{
		digit++;
		maxIndex += 9 * digit * pow(10, digit - 1);
	}

	int delta = index - maxIndex + 9 * digit * pow(10, digit - 1);
	int num = pow(10, digit - 1) + delta / digit - 1;
	int res;
	if (delta % digit == 0)
		res = num % 10;
	else
	{
		num++;
		for (int i = 0; i < digit - delta % digit + 1; i++)
		{
			res = num % 10;
			num /= 10;
		}
	}
	return res;
}