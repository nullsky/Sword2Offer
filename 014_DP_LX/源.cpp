#include <iostream>
#include <vector>
using namespace std;


/*
��Ŀ1��������½������еĳ���
���룺{4�� 6�� 5�� 7�� 3}
�����3��4�� 6�� 7 �� 4�� 5�� 7��
*/
int	maxIncreaseArray(int arr[], int length);

/*
��Ŀ2��	�����������δӶ����׵����·���ͣ�ֻ�������»�����
���룺
				7
			3		8
		8		1		0
	2		7		4		4
4		5		2		6		5
�����30 ��7 3 8 7 5��
*/
int maxSum(int arr[], int rows);

/*
��Ŀ3��������ͬ����Ӳ�Һ�һ���ܽ�д��������������Դճ��ܽ���Ӳ�������������ÿһ������Ӳ�������޸�
���룺amount = 5, coins = {1�� 2�� 5}
�����4
*/
int change(int amount, vector<int> & coins);

int main()
{
	int arr[5] = { 4, 6, 5, 7, 3 };
	cout << "dp1:\n����½������г�\n" << maxIncreaseArray(arr, 5) << endl;
	
	int arr2[15] = { 7, 3, 8, 8, 1, 0, 2, 7, 4, 4, 4, 5, 2, 6, 5 };
	cout << "dp2:\n�������������·����\n" << maxSum(arr2, 5) << endl;

	int a[3] = { 1, 2, 5 };
	vector<int> v(a, a + 3);
	cout << "dp4:\nӲ���������\n" << change(5, v) << endl;

	system("pause");
	
	return 0;
}

int	maxIncreaseArray(int arr[], int length)
{
	if (arr == nullptr || length < 1)
		return 0;

	/*����һ�����飬����������Ľ��*/
	int * dp = new int[length];
	memset(dp, 0, sizeof(int) * length);

	int res = 0;

	/*���ÿһ��������*/
	for (int i = 0; i < length; i++)
	{
		/*������ǰԪ�ص����������*/
		dp[i] = 0;
		for (int j = 0; j <= i - 1; j++)
		{
			if (arr[j] <= arr[i] && dp[j] > dp[i])
				dp[i] = dp[j];
		}
		dp[i]++;

		/*res��������еĴ�С*/
		res = res < dp[i] ? dp[i] : res;
	}

	delete[] dp;
	return res;
}

int maxSum(int arr[], int rows)
{
	if (arr == nullptr || rows < 1)
		return 0;

	int length = (1 + rows) * rows / 2;
	/*�������飬����������ÿһ��Ԫ�����׵����·����*/
	int *dp = new int[length];
	
	/*�Ե��������*/
	// ��ʼ������������е�ֵ
	for (int i = 0; i < rows; i++)
	{
		int index = length - 1 - i;
		dp[index] = arr[index];
	}
	// �ӵ����ڶ������ϼ���
	for(int row = rows - 2; row >= 0; row--)
		for (int col = row; col >= 0; col--)
		{
			int cur = (row + 1) * row / 2 + col;
			int leftdown = cur + row + 1;
			int rightdown = leftdown + 1;
			dp[cur] = dp[leftdown] > dp[rightdown] ? dp[leftdown] + arr[cur]: dp[rightdown] + arr[cur];
		}

	return dp[0];
}

int change(int amount, vector<int> & coins)
{
	if (amount < 0 || coins.empty())
		return 0;

	int res;
	int * dp = new int[amount + 1];
	memset(dp, 0, sizeof(int) * (amount + 1));

	dp[0] = 1;
	for (int coin : coins)
	{
		/* ��¼ÿ���һ��������Ǯ���ܽ��j�ı仯 */
		for (int j = coin; j <= amount; j++)
		{
			/*����һ����Ǯ״̬�Ļ���������
			 ��������ܶ�5����ֻ�����Ϊ1����Ǯʱ��ֻ��һ�ֿ��� 5x1
			 ���������Ϊ2����Ǯʱ������ԭ������һ�ֿ�����
			 �����������������Ǯ����������ܶ�Ϊ5�����ܶ�Ϊ3�Ļ����ϼ�������Ǯ����
			 ���Ծͼ��ϴ�ʱ�ܶ�Ϊ3������������*/
			dp[j] += dp[j - coin];
		}
	}
	res = dp[amount];
	delete[] dp;
	return res;
}