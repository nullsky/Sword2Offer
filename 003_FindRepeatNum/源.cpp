#include <iostream>
using namespace std;

/*��Ŀһ�����������ظ����� ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)*/
bool duplicate(int arr[], int length, int * duplication)
{
	if (arr == nullptr || length <= 0)
		return false;
	
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= length)
			return false;
	}

	for (int i = 0; i < length; i++)
	{
		while (arr[i] != i)
		{
			int tmp = arr[i];
			if (arr[tmp] == arr[i])
			{
				*duplication = arr[i];
				return true;
			}

			arr[i] = arr[tmp];
			arr[tmp] = tmp;
		}
	}

	return false;
}

/*��Ŀ���������ظ�����*/
int GetCnt(const int * arr, int length, int start, int end);
int dulicate2(const int * arr, int length)
{
	if (arr == nullptr || length <= 0)
		return -1;

#if 0
	/*O(n)�Ķ���ռ�*/
	int * num = new int[length];
	memset(num, 0, sizeof(int)*length);
	for (int i = 0; i < length; i++)
	{
		num[arr[i]]++;
	}
	for (int i = 0; i < length; i++)
	{
		if (num[i] < 2)
			continue;
		else
			return i;
	}
	return -1;
#endif

#if 1
	/*O(1)�Ŀռ临�Ӷ�*/
	int start = 1;
	int end = length - 1;
	while (start <= end)
	{
		int middle = ((end - start) >> 1) + start;
		int cnt = GetCnt(arr, length, start, middle);
		if (start == end)
		{
			if (cnt > 1)
				return start;
			else
				break;
		}
		if (cnt > middle - start + 1)
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
#endif
}

int GetCnt(const int * arr, int length, int start, int end)
{
	int cnt = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= start && arr[i] <= end)
			cnt++;
	}
	return cnt;
}

int main()
{
	int a[] = { 6,5,5,2,1,6, 4};
	int * duplication = new int;
	duplicate(a, 7, duplication) ? cout << *duplication << endl : cout << "not find" << endl;
	cout << dulicate2(a, 7) << endl;
	system("pause");
	return 0;
}