#include "sort.h"

/*��֤֮ǰ�����Ѿ�����õģ�����ǰֵ�����Ӧ��λ��*/
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

/*ͨ����ǰһ�����Ƚϣ�ÿһ�ν���ǰ�������ֵ��������λ��*/
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

/*�԰�֣���������õĺϲ�*/
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
