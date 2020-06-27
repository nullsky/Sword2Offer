#include <iostream>
using namespace std;

/*找出旋转数组的最小值*/
int findMin(int arr[], int length);	/*二分法：注意特殊输入*/

int main()
{
	//int arr[10] = { 0,1,2,3,5,6,8,9,10,15 };
	int arr[5] = { 2,2,2,0,1 };
	cout << findMin(arr, 5) << endl;
	system("pause");
	return 0;
}

int findMin(int arr[], int length)
{
	if (arr == nullptr || length < 1)
		return -1;

	int start = 0;
	int end = length - 1;
	while (arr[start] >= arr[end])
	{
		int mid = start + (end - start + 1) / 2;
		if (arr[mid] < arr[start])
			end = mid;
		else if(arr[mid] > arr[start])
			start = mid;
		else
		{
			int result = arr[start];
			for (int i = start + 1; i <= end; i++)
				result = arr[i] > result ? result : arr[i];
				return result;
		}
	}
	return arr[start];
}
