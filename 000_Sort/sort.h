#pragma once

/*��������*/
void InsertSort(int* arr, int length);

/*ð������*/
void BubbleSort(int* arr, int length);

/*�鲢����*/
void MergeSort(int* arr, int length);
void MergeSortCore(int* arr, int s, int e, int* tmpArr);
void Merge(int* arr, int s0, int s1, int e1, int* tmpArr);