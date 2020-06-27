#include <iostream>
#include <cmath>
using namespace std;

/*
题目：实现base的exponent次方函数，不考虑大数，不得使用库函数
考点：
	1.代码的完整性
	2.优化的方法
*/
bool g_bInputValuable = true;
double Power(double base, int exponent);
double powerWithUnsignedExponent(double base, unsigned int exponent);

int main()
{
	cout << pow(0, -10) << endl;
	cout << g_bInputValuable << "\t" << Power(0, 0) << endl;
	system("pause");
	return 0;
}

double Power(double base, int exponent)
{
	if (abs(base - 0.0) < 1e-6 && exponent < 0)
	{
		g_bInputValuable = false;
		return 0;
	}

	unsigned int uintExponent = (unsigned int)(exponent);
	if (exponent < 0)
		uintExponent = (unsigned int)(-exponent);
	
	double result = powerWithUnsignedExponent(base, uintExponent);
	if (exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}

double powerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = powerWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;
	return result;
}