#include <iostream>
using namespace std;

/*
��Ŀ����������˳��ʹ����λ��ż��ǰ��
*/
void changeOrder(int * arr, int length);

/*
���֣���������˳��ʹ����λ��ż��ǰ�棬���ı����˳��
*/
void changeOrder2(int * arr, int length);

int main()
{
	int arr[10] = { 9, 12, 8, 5, 16, 20, 5, 3, 4, 1 };
	changeOrder2(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\t";
	}
	system("pause");
	return 0;
}

void changeOrder(int * arr, int length)
{
	if (arr == nullptr || length < 1)
		return;

	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 == 1)
		{
			int tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
			index++;
		}
	}

}

void changeOrder2(int * arr, int length)
{
	if (arr == nullptr || length < 1)
		return;

	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 == 0)
			continue;
		else
		{
			int tmp = arr[i];
			for (int j = i; j >= index && j - 1>= 0; j--)
				arr[j] = arr[j - 1];
			
			arr[index++] = tmp;
		}
	}
}