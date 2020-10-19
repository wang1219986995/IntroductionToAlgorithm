// IntroductionToAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "src/Algorithms/sort_algorithms/insert_sort.h"
#include "src/Algorithms/sort_algorithms/selection_sort.h"
//#include "src/Algorithms/sort_algorithms/merge_sort.h"
#include "src/Algorithms/Divide_and_Conquer_Algorithm/maximum_subarray.h"
#include "src/Algorithms/Divide_and_Conquer_Algorithm/Strassen.h"
#include "src/Algorithms/sort_algorithms/heap_sort.h"
#include <ctime>
#include <iterator>
#include "src/Algorithms/sort_algorithms/quick_sort.h"
#include "src/Algorithms/sort_algorithms/counting_sort.h"
#include "src/Algorithms/sort_algorithms/sequential_statistics.h"
using namespace std;

template <class T>
struct test {
	bool operator() (const T& x,const T& y) {
		return x < y;
	}
};


int main()
{
	vector<int> a = { 8,1,34,66,72,2 };
	IntroductionToAlgorihtms::SortAlgotithms::Sequential q;
	q.nums = a;


	int res = q.randomized_select_iteration(2);
	cout << res << endl;

	
}

