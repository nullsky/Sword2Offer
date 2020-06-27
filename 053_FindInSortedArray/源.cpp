#include <iostream>
using namespace std;

/*
题目1：数字在排序数组中出现的次数
*/
int FreqInSortedArr(const int* arr, int length, int k);
int GetFirstK(const int* arr, int k, int start, int end);
int GetLastK(const int* arr, int k, int start, int end);

int main()
{
	int a;
	cin >> a;
	int * arr = new int[a];
	for (int i = 0; i < a; i++)
		cin >> arr[i];
	int b;
	cin >> b;

	cout << FreqInSortedArr(arr, a, b) << endl;
	system("pause");
	return 0;
}

int FreqInSortedArr(const int * arr, int length, int k)
{
	int start = GetFirstK(arr, k, 0, length - 1);
	int end = GetLastK(arr, k, 0, length - 1);
	if (start == -1 || end == -1)
		return 0;
	
	return end - start + 1;
}

int GetFirstK(const int * arr, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (arr[mid] == k)
	{
		if (mid > 0 && arr[mid - 1] == k)
			end = mid - 1;
		else
			return mid;
	}
	else if (arr[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;
	return GetFirstK(arr, k, start, end);
}

int GetLastK(const int * arr, int k, int start, int end)
{
	if (start > end)
		return -1;

	int mid = (start + end) / 2;
	if (arr[mid] == k)
	{
		if (mid < end && arr[mid + 1] == k)
			start = mid + 1;
		else
			return mid;
	}
	else if (arr[mid] > k)
		end = mid - 1;
	else
		start = mid + 1;
	return GetLastK(arr, k, start, end);
}