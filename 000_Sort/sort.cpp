#include "sort.h"

/*保证之前的是已经排序好的，将当前值插入对应的位置*/
void InsertSort(int * arr, int length)
{
	if (arr == nullptr || length < 1)
		return;

	int i, j;
	for (i = 1; i < length; i++)
	{
		int tmp = arr[i];
		for (j = i; j > 0 && arr[j - 1] > tmp; j--)
			arr[j] = arr[j - 1];

		arr[j] = tmp;
	}
}

/*通过与前一个数比较，每一次将当前数组最大值放入最后的位置*/
void BubbleSort(int * arr, int length)
{
	if (arr == nullptr || length < 1)
		return;

	for (int i = 0; i < length; i++)
	{
		for (int j = 1; j < length - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

/*对半分，并将排序好的合并*/
void MergeSort(int * arr, int length)
{
	if (arr == nullptr || length < 1)
		return; 
	
	int* tmpArr = new int[length];
	MergeSortCore(arr, 0, length - 1, tmpArr);
	delete[] tmpArr;
}

void MergeSortCore(int * arr, int s, int e, int * tmpArr)
{
	if (s >= e)
		return;

	int mid = (s + e) / 2;
	MergeSortCore(arr, s, mid, tmpArr);
	MergeSortCore(arr, mid + 1, e, tmpArr);
	Merge(arr, s, mid + 1, e, tmpArr);
}

void Merge(int * arr, int s0, int s1, int e1, int * tmpArr)
{
	int s = s0;
	int e = e1;

	int e0 = s1 - 1;
	int index = s0;
	while (s0 <= e0 && s1 <= e1)
	{
		if (arr[s0] <= arr[s1])
			tmpArr[index++] = arr[s0++];
		else
			tmpArr[index++] = arr[s1++];
	}
	while (s0 <= e0)
		tmpArr[index++] = arr[s0++];
	while (s1 <= e1)
		tmpArr[index++] = arr[s1++];

	for (int i = s; i <= e; i++)
		arr[i] = tmpArr[i];
}
