#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

/*
机器人的运动范围
方法：回溯
*/
int robotMotion(int rows, int cols, int k);
void robotMotionCore(int rows, int cols, int row, int col, int k, int & num, bool * visited);
bool isOk(int row, int col, int k);
Mat showTrack;

int main()
{
	cout << robotMotion(35, 35, -15) << endl;
	system("pause");
	return 0;
}

int robotMotion(int rows, int cols, int k)
{
	if (rows < 1 || cols < 1 || k < 0)
		return -1;

	showTrack.create(512, 640, CV_8UC3);
	showTrack.setTo(255);
	for (int i = 1; i < rows; i++)
		line(showTrack, Point2f(0, 1.0 * showTrack.rows / rows * i), Point2f(showTrack.cols, 1.0 * showTrack.rows / rows * i), Scalar(0, 0, 0));
	for(int i = 1; i < cols; i++)
		line(showTrack, Point2f(1.0 * showTrack.cols / cols * i, 0), Point2f(1.0 * showTrack.cols / cols * i, showTrack.rows), Scalar(0, 0, 0));

	bool * visited = new bool[rows * cols];
	memset(visited, 0, sizeof(bool) * rows * cols);

	int num = 0;
	robotMotionCore(rows, cols, 0, 0, k, num, visited);
	delete[] visited;

	imshow("show", showTrack);
	waitKey(1);

	return num;
}

void robotMotionCore(int rows, int cols, int row, int col, int k, int & num, bool * visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		isOk(row, col, k) && !visited[row * cols + col])
	{
		num++;
		visited[row * cols + col] = true;

		circle(showTrack, Point2f(1.0 * col * showTrack.cols / cols + 1.0 * showTrack.cols / cols / 2,
			1.0 * row * showTrack.rows / rows + 1.0 * showTrack.rows / rows / 2), 5, Scalar(0, 0, 255), -1);

		robotMotionCore(rows, cols, row - 1, col, k, num, visited);
		robotMotionCore(rows, cols, row, col - 1, k, num, visited);
		robotMotionCore(rows, cols, row, col + 1, k, num, visited);
		robotMotionCore(rows, cols, row + 1, col, k, num, visited);
	}
}

bool isOk(int row, int col, int k)
{
	int sum = 0;
	while (row > 0)
	{
		sum += row % 10;
		row /= 10;
	}
	while (col > 0)
	{
		sum += col % 10;
		col /= 10;
	}
	if (sum > k)
		return false;
	else
		return true;
}