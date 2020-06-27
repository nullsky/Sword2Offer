/*
题目：正则表达式匹配
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 ‘.’ 和 ‘∗’ 的正则表达式匹配。

‘.’ 匹配任意单个字符。
‘∗’ 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:
s 可能为空，且只包含从 a−z 的小写字母。
p 可能为空，且只包含从 a−z 的小写字母，以及字符 . 和 ∗。

示例 1:
输入:s = “aa”
p = “a”
输出: false
解释: “a” 无法匹配 “aa” 整个字符串。

示例 2:
输入:
s = “aa”
p = “a∗”
输出: true
解释: ‘∗’ 代表可匹配零个或多个前面的元素, 即可以匹配 ‘a’ 。因此, 重复 ‘a’ 一次, 字符串可变为 “aaa”。

示例 3:
输入:
s = “ab”
p = “.∗”
输出: true
解释: “.∗” 表示可匹配零个或多个(’∗’)任意字符(’.’)。

示例 4:
输入:
s = “aab”
p = “c∗a∗b”
输出: true
解释: ‘c’ 可以不被重复, ‘a’ 可以被重复一次。因此可以匹配字符串 “aab”。

示例 5:
输入:
s = “mississippi”
p = “mis∗is∗p∗.”
输出: false
*/

#include <iostream>
#include <string>
using namespace std;

/*
递归
*/
bool isMatch(string s, string p);

/*
dp
*/
bool isMatch_DP(string s, string p);

int main()
{
	char * str = "hello";
	char a = *str++;
	char b = *str;
	double d = +1e1;
	cout << isMatch_DP("asd", "w*asd") << endl;
	system("pause");
	return 0;
}

bool isMatch(string s, string p)
{
	if (p.empty())	return s.empty();

	if (p.size() > 1 && p[1] == '*')
		return  isMatch(s, p.substr(2))|| (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
	else
		return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
}

bool isMatch_DP(string s, string p)
{
	int m = s.size() + 1;
	int n = p.size() + 1;

	bool **dp = new bool *[m];
	for (int i = 0; i < m; i++)
		dp[i] = new bool[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = false;

	dp[0][0] = true;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (j > 1 && p[j - 1] == '*')
				dp[i][j] = dp[i][j - 2] || ( i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j] );
			else
				dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
		}
	}
	bool res = dp[m - 1][n - 1];
	for (int i = 0; i < m; i++)
		delete[] dp[i];
	delete[] dp;

	return res;
}