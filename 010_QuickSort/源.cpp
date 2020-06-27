#include <iostream>
using namespace std;

void swap(int & a, int & b);
int randomInRange(int start, int end);
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

int main()
{
	int arr[10] = { 0,9,7,3,5,2,2,1,6,4 };
	quickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << "\t";
	system("pause");
	return 0;
}

void swap(int & a, int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int randomInRange(int start, int end)
{
	return rand() % (end - start + 1) + start;
}

int partition(int arr[], int start, int end)
{
	int index = randomInRange(start, end);
	swap(arr[index], arr[end]);

	int small = start - 1;
	for (int i = start; i < end; i++)
	{
		if (arr[i] < arr[end])
		{
			small++;
			if (small != i)
				swap(arr[i], arr[small]);
		}
	}

	small++;
	swap(arr[end], arr[small]);

	return small;
}

void quickSort(int arr[], int start, int end)
{
	if (start == end)
		return;

	int index = partition(arr, start, end);
	if (index > start)
		quickSort(arr, start, index);
	if (index < end)
		quickSort(arr, index + 1, end);

}
