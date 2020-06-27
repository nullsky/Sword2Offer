#include <iostream>
#include <vector>
using namespace std;


/*
题目1：求最大不下降子序列的长度
输入：{4， 6， 5， 7， 3}
输出：3（4， 6， 7 或 4， 5， 7）
*/
int	maxIncreaseArray(int arr[], int length);

/*
题目2：	求数字三角形从顶到底的最大路径和，只能走左下或右下
输入：
				7
			3		8
		8		1		0
	2		7		4		4
4		5		2		6		5
输出：30 （7 3 8 7 5）
*/
int maxSum(int arr[], int rows);

/*
题目3：给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个
输入：amount = 5, coins = {1， 2， 5}
输出：4
*/
int change(int amount, vector<int> & coins);

int main()
{
	int arr[5] = { 4, 6, 5, 7, 3 };
	cout << "dp1:\n最大不下降子序列长\n" << maxIncreaseArray(arr, 5) << endl;
	
	int arr2[15] = { 7, 3, 8, 8, 1, 0, 2, 7, 4, 4, 4, 5, 2, 6, 5 };
	cout << "dp2:\n数字三角形最大路径和\n" << maxSum(arr2, 5) << endl;

	int a[3] = { 1, 2, 5 };
	vector<int> v(a, a + 3);
	cout << "dp4:\n硬币组合种类\n" << change(5, v) << endl;

	system("pause");
	
	return 0;
}

int	maxIncreaseArray(int arr[], int length)
{
	if (arr == nullptr || length < 1)
		return 0;

	/*创建一个数组，保存子问题的结果*/
	int * dp = new int[length];
	memset(dp, 0, sizeof(int) * length);

	int res = 0;

	/*求解每一个子问题*/
	for (int i = 0; i < length; i++)
	{
		/*包含当前元素的最大子序列*/
		dp[i] = 0;
		for (int j = 0; j <= i - 1; j++)
		{
			if (arr[j] <= arr[i] && dp[j] > dp[i])
				dp[i] = dp[j];
		}
		dp[i]++;

		/*res最大子序列的大小*/
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
	/*创建数组，保存三角形每一个元素至底的最大路径和*/
	int *dp = new int[length];
	
	/*自底向上求解*/
	// 初始化三角形最底行的值
	for (int i = 0; i < rows; i++)
	{
		int index = length - 1 - i;
		dp[index] = arr[index];
	}
	// 从倒数第二行向上计算
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
		/* 记录每添加一种面额的零钱，总金额j的变化 */
		for (int j = coin; j <= amount; j++)
		{
			/*在上一种零钱状态的基础上增大
			 例如对于总额5，当只有面额为1的零钱时，只有一种可能 5x1
			 当加了面额为2的零钱时，除了原来的那一种可能外
			 还加上了组合了两块钱的情况，而总额为5是在总额为3的基础上加上两块钱来的
			 所以就加上此时总额为3的所有组合情况*/
			dp[j] += dp[j - coin];
		}
	}
	res = dp[amount];
	delete[] dp;
	return res;
}