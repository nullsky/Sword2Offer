#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
题目：mxn的棋盘放着礼物，从左上角向右或向下走到右下角，礼物的最大值
方法：动态规划
递推关系式：f(i, j) = max{f(i - 1, j), f(i, j - 1)} + v(i , j)
*/
/*使用一个临时的二维数组保存格子的最大值*/
int MaxValue(const vector<vector<int>>& map);

/*空间优化，f(i, j)与 i-2 行的值无关，使用一维数组保存中间值，长度=cols*/
int MaxValue2(const vector<vector<int>>& map);

int main()
{
	vector<int> n1 = { 1, 10, 3, 8 };
	vector<int> n2 = { 12, 2, 9, 6 };
	vector<int> n3 = { 5,7,4,11 };
	vector<int> n4 = { 3,7,16,5 };
	vector<vector<int>> map;
	map.push_back(n1);
	map.push_back(n2);
	map.push_back(n3);
	map.push_back(n4);
	cout << MaxValue2(map) << endl;
	system("pause");
	return 0;
}

int MaxValue(const vector<vector<int>>& map)
{
	if (map.empty() || map[0].empty())
		return 0;
	int m = map.size();
	int n = map[0].size();
	
	int** value = new int*[m];
	for (int i = 0; i < m; i++)
		value[i] = new int[n];
	
	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int topMaxValue;
			int leftMaxValue;
			topMaxValue = i == 0 ? 0 : value[i - 1][j];
			leftMaxValue = j == 0 ? 0 : value[i][j - 1];
			value[i][j] = max(topMaxValue, leftMaxValue) + map[i][j];
		}

	int res = value[m - 1][n - 1];
	for (int i = 0; i < m; i++)
		delete[] value[i];
	delete[] value;
	return res;
}

int MaxValue2(const vector<vector<int>>& map)
{
	if (map.empty() || map[0].empty())
		return -1;

	int rows = map.size();
	int cols = map[0].size();

	int * value = new int[cols];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int up, left;
			up = i == 0 ? 0 : value[j];
			left = j == 0 ? 0 : value[j - 1];
			value[j] = max(up, left) + map[i][j];
		}
	
	int res = value[cols - 1];
	delete[] value;
	return res;
}