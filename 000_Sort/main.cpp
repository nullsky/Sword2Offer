#include <iostream>
#include "sort.h"
using namespace std;

int main()
{
	int arr[10] = { 20, 1, 25, 3, 1, 20, 15, 16, 85, 11 };
	//InsertSort(arr, 10);
	//BubbleSort(arr, 10);
	MergeSort(arr, 10);
	for each (int a in arr)
	{
		cout << a << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}