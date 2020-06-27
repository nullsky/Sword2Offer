#include <iostream>
#include <string>
using namespace std;

/*
题目1：打印1到最大的n位数
考点：代码的完整性、规避溢出的情况
转为字符串进行处理
*/

/*方法1：用字符串模拟+1的操作*/
void Print1ToMaxNDigits(int n);
bool Increment(char * number);
void PrintNumber(char * number);

/*方法2：递归*/
void Print1ToMaxNDigits2(int n);
void Print1ToMaxNDigitsRecursion(char* number, int length, int index);

/*
题目2：实现2个整数的加法（大数问题，使用字符串处理）
输入复数的情况
*/
string Add(string number1, string number2);

int main()
{
	string s = "hh";
	int b = s.size();
	Print1ToMaxNDigits(3);
	system("pause");
	return 0;
}

void Print1ToMaxNDigits(int n)
{
	if (n < 1)
		return;
	
	char * number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

bool Increment(char * number)
{
	bool bOverflow = false;
	int nTakeOver = 0;
	int length = strlen(number);
	
	for (int i = length - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == length - 1)
			nSum++;

		if (nSum >= 10)
		{
			if (i == 0)
			{
				bOverflow = true;
				break;
			}

			nSum -= 10;
			nTakeOver = 1;
			number[i] = nSum + '0';
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}

	return bOverflow;
}

void PrintNumber(char * number)
{
	bool bBeginPrint = false;
	int length = strlen(number);

	for (int i = 0; i < length; i++)
	{
		if (!bBeginPrint && number[i] != '0')
			bBeginPrint = true;
		if (bBeginPrint)
			cout << number[i];
	}
	cout << "\t";
}

void Print1ToMaxNDigits2(int n)
{
	if (n < 1)
		return;

	char * number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	Print1ToMaxNDigitsRecursion(number, n, 0);
}

void Print1ToMaxNDigitsRecursion(char* number, int length, int index)
{
	if (length == index)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index] = i + '0';
		Print1ToMaxNDigitsRecursion(number, length, index + 1);
	}
}