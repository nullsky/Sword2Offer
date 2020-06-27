#include <iostream>
using namespace std;

/*
��Ŀ����Ϊn�����ӣ�����m�Σ�ʹÿ�γ��ĳ˻�������Ž����⣩
����1����̬�滮 ���� f(n) = max{f(i) * f(n - i)}, 0 < i < n 
����2��̰����
*/
int maxProductAfterCutting_solution(int length);
int maxProductAfterCutting_solution2(int length);

int main()
{
	cout << "DP: " << maxProductAfterCutting_solution(18) << endl;
	cout << "̰����: " << maxProductAfterCutting_solution2(18) << endl;
	system("pause");
	return 0;
}

int maxProductAfterCutting_solution(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int * products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max_value;
	for (int i = 4; i <= length; i++)
	{
		int max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			products[i] = products[j] * products[i - j];
			max = products[i] > max ? products[i] : max;
		}
		products[i] = max;
	}
	max_value = products[length];

	delete[] products;
	return max_value;
}

int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int numOf3 = length / 3;
	numOf3 = length % 3 == 1 ? numOf3 - 1 : numOf3;

	int numOf2 = (length - numOf3 * 3) / 2;
	return pow(3, numOf3) * pow(2, numOf2);
}