#include <iostream>
using namespace std;

/*
题目：求数组中的逆序对的个数
思路：参考归并排序，在归并时统计数量
*/

int InversePairs(int* arr, int length);
int InversePairsCore(int* arr, int s, int e, int* tmpArr);
int Merge(int* arr, int s0, int s1, int e1, int* tmpArr);

int main()
{
	int arr[4] = { 7,5,5,4 };
	cout << InversePairs(arr, 4) << endl;
	system("pause");
	return 0;
}

int InversePairs(int * arr, int length)
{
	if(arr == nullptr || length < 1)
		return 0;

	int* tmpArr = new int[length];
	int res = InversePairsCore(arr, 0, length - 1, tmpArr);
	delete[] tmpArr;
	return res;
}

int InversePairsCore(int * arr, int s, int e, int * tmpArr)
{
	if (s >= e)
		return 0;
	
	int mid = (s + e) / 2;
	int left = InversePairsCore(arr, s, mid, tmpArr);
	int right = InversePairsCore(arr, mid + 1, e, tmpArr);
	return left + right + Merge(arr, s, mid + 1, e, tmpArr);
}

int Merge(int* arr, int s0, int s1, int e1, int* tmpArr)
{
	int num = 0;
	int s = s0;
	int e = e1;

	int e0 = s1 - 1;
	int index = e1;
	while (e0 >= s0 && e1 >= s1)
	{
		if (arr[e0] > arr[e1])
		{
			num += e1 - s1 + 1;
			tmpArr[index--] = arr[e0--];
		}
		else
		{
			tmpArr[index--] = arr[e1--];
		}
	}
	while(e0 >= s0)
		tmpArr[index--] = arr[e0--];
	while(e1 >= s1)
		tmpArr[index--] = arr[e1--];

	for (int i = s; i <= e; i++)
		arr[i] = tmpArr[i];

	return num;
	
}

