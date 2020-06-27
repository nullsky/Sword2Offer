#include <iostream>
using namespace std;

/*
题目：给定一个整数数组，判断是否是一个二叉搜索树的后序遍历
思路：后序遍历的特点，递归
类比于题目007重建二叉树
*/
bool IsBinSearchTree(int* arr, int length);
bool IsBinSearchTreeCore(int* arr, int start, int end);

int main()
{
	int arr[4] = { 7, 4, 6, 5 };
	int length = 4;

	if (IsBinSearchTree(arr, length))
		cout << "Y" << endl;
	else
		cout << "N" << endl;

	system("pause");
	return 0;
}
bool IsBinSearchTree(int* arr, int length)
{
	if (arr == nullptr || length < 0)
		return false;

	return IsBinSearchTreeCore(arr, 0, length - 1);
}

bool IsBinSearchTreeCore(int* arr, int start, int end)
{
	if (start >= end)
		return true;

	bool res = true;
	int partition;
	for (int i = start; i < end; i++)
	{
		if (arr[i] > arr[end])
		{
			partition = i;
			break;
		}
	}
	for (int i = partition; i < end; i++)
	{
		if (arr[i] < arr[end])
		{
			res = false;
			break;
		}
	}
	
	return res && IsBinSearchTreeCore(arr, start, partition - 1) &&
		IsBinSearchTreeCore(arr, partition, end - 1);
}
