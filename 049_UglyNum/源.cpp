#include <iostream>
using namespace std;

/*
题目：丑数（因子只包含2，3，5的数）
1是第一个丑数，返回第index个丑数
*/
int GetUglyNumber(int index);
int Min(int a, int b, int c);

int main()
{
	int index;
	while (cin >> index)
	{
		cout << GetUglyNumber(index) << endl;
	}
	system("pause");
	return 0;
}

int GetUglyNumber(int index)
{
	if (index <= 0)
		return 0;

	int * nums = new int[index];
	nums[0] = 1;

	// 队列的指针
	int* pMultiply2 = nums;
	int* pMultiply3 = nums;
	int* pMultiply5 = nums;

	int i = 1;
	while (i < index)
	{
		nums[i] = Min(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
		while (*pMultiply2 * 2 <= nums[i])
			pMultiply2++;
		while (*pMultiply3 * 3 <= nums[i])
			pMultiply3++;
		while (*pMultiply5 * 5 <= nums[i])
			pMultiply5++;
		i++;
	}
	int res = nums[index - 1];
	delete[] nums;
	return res;
}

int Min(int a, int b, int c)
{
	int tmp = a > b ? b : a;
	return tmp > c ? c : tmp;
}