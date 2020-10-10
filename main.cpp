// IntroductionToAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "src/Algorithms/sort_algorithms/insert_sort.h"
#include "src/Algorithms/sort_algorithms/selection_sort.h"
//#include "src/Algorithms/sort_algorithms/merge_sort.h"
#include "src/Algorithms/Divide_and_Conquer_Algorithm/maximum_subarray.h"
#include "src/Algorithms/Divide_and_Conquer_Algorithm/Strassen.h"
#include <ctime>
using namespace std;




int main()
{
	vector< vector<int> > A = { {1,3},{7,5} };
	vector< vector<int> > B = { {6,8},{4,2} };
	Strassen m;
	m.A = A;
	m.B = B;
	m.C = A;
	//m.squary_matrix_multiply(A, B, m.C);
	//for (int i = 0; i < m.C.size(); ++i) {
	//	for (int j = 0; j < m.C[0].size(); ++j) {
	//		cout << m.C[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
	m.C = vector< vector<int> >(A.size(), vector<int>(A.size()));
	m.squary_matrix_multiply_recursive(A, B, m.C);
	for (int i = 0; i < m.C.size(); ++i) {
		for (int j = 0; j < m.C[0].size(); ++j) {
			cout << m.C[i][j] << "  ";
		}
		cout << endl;
	}




}

