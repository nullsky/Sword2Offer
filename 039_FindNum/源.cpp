#include <iostream>
#include <algorithm>
using namespace std;

/*
题目：找出数组中次数出现大于一半的数字
*/

/*方法1：基于快排的思想，partition为下标n/2的点就是该数字*/
int MoreThanHalfNum(int* arr, int length);
int Partition(int* arr, int start, int end);

/*方法2：时间复杂度O(n)，遍历*/
int MoreThanHalfNum2(int* arr, int length);

int main()
{
	int arr[5] = { 2,3,2,2,3 };
	cout << MoreThanHalfNum2(arr, 5) << endl;
	system("pause");
	return 0;
}

int MoreThanHalfNum(int* arr, int length)
{
	if (arr == nullptr || length < 1)
		return 0;

	int start = 0; 
	int end = length - 1;
	int index = Partition(arr, start, end);
	while (index != length / 2)
	{
		if (index > length / 2)
		{
			end = index - 1;
			index = Partition(arr, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(arr, start, end);
		}
	}
	return arr[index];
}

int Partition(int* arr, int start, int end)
{
	int partity = arr[start];
	swap(arr[start], arr[end]);

	int index = start;
	for (int i = start; i < end; i++)
	{
		if (arr[i] < partity)
		{
			if(i != index)
				swap(arr[i], arr[index]);
			index++;
		}
	}
	swap(arr[index], arr[end]);
	return index;
}

int MoreThanHalfNum2(int* arr, int length)
{
	if (arr == nullptr || length < 1)
		return 0;

	int val = arr[0];
	int num = 1;
	for (int i = 1; i < length; i++)
	{
		if (arr[i] == val)
			num++;
		else
		{
			num--;
			if (num == 0)
			{
				num = 1;
				val = arr[i];
			}
		}
	}
	return val;
}
