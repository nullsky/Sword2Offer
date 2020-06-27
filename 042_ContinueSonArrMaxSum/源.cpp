#include <iostream>
using namespace std;

/*
题目：求数组中连续子数组最大的和
思路：
	1.动态规划
*/

/*创建临时数组，保存前一步的状态*/
int MaxSumOfSonArr(int* arr, int length);

/*优化空间*/
int MaxSumOfSonArr2(int* arr, int length);

int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << MaxSumOfSonArr2(arr, 8) << endl;
	system("pause");
	return 0;
}

int MaxSumOfSonArr(int* arr, int length)
{
	if (arr == nullptr || length < 1)
		return -1;

	int* sum = new int[length];
	sum[0] = arr[0];

	for (int i = 1; i < length; i++)
	{
		if (sum[i - 1] > 0)
			sum[i] = sum[i - 1] + arr[i];
		else
			sum[i] = arr[i];
	}

	int maxSum = sum[0];
	for (int i = 1; i < length; i++)
	{
		maxSum = maxSum < sum[i] ? sum[i] : maxSum;
		cout << sum[i] << "\t";
	}
	delete[] sum;
	return maxSum;
}

int MaxSumOfSonArr2(int* arr, int length)
{
	if (arr == nullptr || length < 1)
		return 0;

	int tmpSum = 0;
	int maxSum = 0x80000000;
	for (int i = 0; i < length; i++)
	{
		if (tmpSum < 0)
			tmpSum = arr[i];
		else
			tmpSum += arr[i];

		maxSum = maxSum < tmpSum ? tmpSum : maxSum;
	}
	return maxSum;
}
