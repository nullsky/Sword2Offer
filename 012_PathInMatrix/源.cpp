#include <iostream>
using namespace std;

/*
题目：矩阵中的路径
方法：回溯法-类似dfs
*/
bool findPath(const char * matrix, int rows, int cols, const char * str);
/*递归函数*/
bool findPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int & pathLen, bool * visited);

int main()
{
	char matrix[12] = { 'a', 'b', 't', 'g',
	'c', 'f', 'c', 's',
	'j', 'd', 'e', 'h' };

	if (findPath(matrix, 3, 4, "abfc"))
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	
	system("pause");
	return 0;
}

bool findPath(const char * matrix, int rows, int cols, const char * str)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
		return false;

	bool * visited = new bool[rows * cols];
	memset(visited, 0, rows * cols * sizeof(bool));

	int strLen = 0;
	for(int row = 0; row < rows; row++)
		for (int col = 0; col < cols; col++)
		{
			if (findPathCore(matrix, rows, cols, row, col, str, strLen, visited))
			{
				delete[] visited;
				return true;
			}
		}

	delete[] visited;
	return false;
}

bool findPathCore(const char * matrix, int rows, int cols, int row, int col, const char * str, int & pathLen, bool * visited)
{
	if (str[pathLen] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		matrix[row * cols + col] == str[pathLen] &&
		!visited[row * cols + col])
	{
		pathLen++;
		visited[row * cols + col] = true;

		hasPath = findPathCore(matrix, rows, cols, row - 1, col, str, pathLen, visited) ||
				  findPathCore(matrix, rows, cols, row, col - 1, str, pathLen, visited) ||
				  findPathCore(matrix, rows, cols, row, col + 1, str, pathLen, visited) ||
				  findPathCore(matrix, rows, cols, row + 1, col, str, pathLen, visited);
	
		if (!hasPath)
		{
			pathLen--;
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}
