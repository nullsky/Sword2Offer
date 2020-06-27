#include <iostream>
#include <set>
#include <queue>
#include <functional>
using namespace std;

/*
题目：找出数组中最小的k个数
*/

/*方法1：基于快排的思想*/
void FindMinKNum(int* arr, int length, int k);
int Partition(int* arr, int start, int end);

/*方法2：stl set*/
void FindMinKNum2(int* arr, int length, int k);

int main()
{
	int arr[10] = { 10, 2, 5, 6, 2, 3, 2, 0, 6, 4 };
	FindMinKNum2(arr, 10, 10);
	system("pause");
	return 0;
}

void FindMinKNum(int* arr, int length, int k)
{
	if (arr == nullptr || length < 1 || k < 1)
		return;

	if (k > length) k = length;

	int start = 0;
	int end = length - 1;
	int index = Partition(arr, start, end);
	while(index != k - 1)
	{
		if (index > k - 1)
			index = Partition(arr, start, index);
		else
			index = Partition(arr, index + 1, end);
	}
	for (int i = 0; i <= index; i++)
		cout << arr[i] << endl;
}

int Partition(int* arr, int start, int end)
{
	swap(arr[start], arr[end]);

	int index = start;
	for (int i = start; i < end; i++)
	{
		if (arr[i] < arr[end])
		{
			if (i == index)
				index++;
			else
				swap(arr[i], arr[index++]);
		}
	}
	swap(arr[index], arr[end]);
	return index;
}

void FindMinKNum2(int* arr, int length, int k)
{
	if (arr == nullptr || k < 0 || k > length)
		return;

	/*multiset<int> data;
	for (int i = 0; i < length; i++)
		data.insert(arr[i]);

	multiset<int>::const_iterator it = data.begin();
	for (int i = 0; i < k; i++, it++)
	{
		cout << *it << "\t";
	}*/

	// 优先队列
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 0; i < length; i++)
	{
		que.push(arr[i]);
	}

	for (int i = 0; i < k; i++)
	{
		cout << que.top() << "\t";
		que.pop();
	}
}