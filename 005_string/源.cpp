#include <iostream>
using namespace std;

/*题目1：将字符串中空格替换为“%20”*/
void replace(char string[], int length)
{
	if (string == nullptr || length <= 0)
		return;
	
	int oriLen = 0;
	int newLen = 0;
	int num = 0;
	while (string[oriLen] != '\0')
	{
		if (string[oriLen] == ' ')
			num++;
		oriLen++;
	}
	newLen = oriLen + 2 * num;
	if (newLen + 1 > length)
		return;

	int nOri = oriLen;
	int nNew = newLen;
	for (int i = nOri; i >= 0; i--)
	{
		if (string[i] == ' ')
		{
			string[nNew--] = '0';
			string[nNew--] = '2';
			string[nNew--] = '%';
		}
		else
			string[nNew--] = string[i];
	}
}

/*题目二：合并两个有序数组，数组1空间足够容纳所有数，空间复杂度和时间复杂度O(1)*/
void mergeArray(int arr1[], int length1, int arr2[], int length2)
{
	if (arr1 == nullptr || arr2 == nullptr)
		return;

	int m = length1 - 1;
	int n = length2 - 1;
	int k = length1 + length2 - 1;

	while (k >= 0)
	{
		if (arr1[m] > arr2[n])
			arr1[k--] = arr1[m--];
		else
			arr1[k--] = arr2[n--];
	}
}

int main()
{
	cout << "##############题目一##############" << endl;
	char string[20] = "hello world";
	cout << string << endl;
	
	replace(string, 20);
	cout << string << endl;

	cout << "##############题目二##############" << endl;
	int arr1[50] = { };
	int arr2[12] = { 1,3,4,6,8,12,50 };
	mergeArray(arr1, 0, arr2, 7);
	for (int i = 0; i < 7; i++)
		cout << arr1[i] << "\t";
	system("pause");
	return 0;
}
