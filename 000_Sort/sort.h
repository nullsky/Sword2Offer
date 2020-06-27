#pragma once

/*≤Â»Î≈≈–Ú*/
void InsertSort(int* arr, int length);

/*√∞≈›≈≈–Ú*/
void BubbleSort(int* arr, int length);

/*πÈ≤¢≈≈–Ú*/
void MergeSort(int* arr, int length);
void MergeSortCore(int* arr, int s, int e, int* tmpArr);
void Merge(int* arr, int s0, int s1, int e1, int* tmpArr);