#ifndef INC_04_INSERTION_SORT_ADVANCE_SORTTESTHELPER_H
#define INC_04_INSERTION_SORT_ADVANCE_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {
	/*产生随机数*/
	int* generateRandomArray(int n,int rangeL,int rangeR) {
		assert(rangeL <= rangeR);

		int *arr = new int[n];
		srand(time(NULL));// 以系统时间设置随机种子
		for (int i = 0; i < n;i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;//取余加偏移
		return arr;
	}
	/*打印*/
	template<typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	/*是否有序*/
	template<typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}
	/*拷贝int数组*/
	int *copyIntArray(int a[], int n) {
		int *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}
	/*传入函数指针和测试用例*/
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		// 硬件滴答数 / 频率 = 时间
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		assert(isSorted(arr, n));
		return;
	}
}
#endif //INC_04_INSERTION_SORT_ADVANCE_SORTTESTHELPER_H