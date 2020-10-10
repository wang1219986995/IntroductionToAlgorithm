#ifndef STRASSEN
#define STRASSEN
#include <vector>
#include <iostream>
using namespace std;


class Strassen {
	typedef vector< vector<int> >   Matrix;
public:
	Matrix A;
	Matrix B;
	Matrix C;


public:
	// P43 算法实现：
	void squary_matrix_multiply(Matrix& A, Matrix& B, Matrix& C);

	//P44 递归版本算法实现：
	void squary_matrix_multiply_recursive(Matrix& A, Matrix& B, Matrix& C);

private:
	void matrix_multiply_recursive(Matrix& A,	Matrix& B,	Matrix& C, 
								int rowStart_A, int rowEnd_A, int columnStart_A, int columnEnd_A,
								int rowStart_B, int rowEnd_B, int columnStart_B, int columnEnd_B,
								int rowStart_C, int rowEnd_C, int columnStart_C, int columnEnd_C  );

	bool checkSizeIsPowerOf2(Matrix& A, Matrix& B, Matrix& C);
};

void Strassen::squary_matrix_multiply(Matrix& A, Matrix& B, Matrix& C) {
	int n = A.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int temp = 0;
			for (int k = 0; k < n; ++k) {
				temp += A[i][k] * B[k][j];
			}
			C[i][j] = temp;
		}
	}
}

void Strassen::squary_matrix_multiply_recursive(Matrix& A, Matrix& B, Matrix& C) {
	int n = A.size();
	bool ok = checkSizeIsPowerOf2(A, B, C);
	if (ok) {
		matrix_multiply_recursive(A, B, C,
			0, n - 1, 0, n - 1,
			0, n - 1, 0, n - 1,
			0, n - 1, 0, n - 1);
	}
	else
		cout << "无法处理该长度的矩阵！";

}



void Strassen::matrix_multiply_recursive(Matrix & A, Matrix & B, Matrix & C, 
				int rowStart_A, int rowEnd_A, int columnStart_A, int columnEnd_A, 
				int rowStart_B, int rowEnd_B, int columnStart_B, int columnEnd_B, 
				int rowStart_C, int rowEnd_C, int columnStart_C, int columnEnd_C){
	if (rowStart_A == rowEnd_A) {
		C[rowStart_C][columnStart_C] += A[rowStart_A][columnStart_A] * B[rowStart_B][columnStart_B];
	}
	else {
		int rowMid_A = rowStart_A + (rowEnd_A - rowStart_A) / 2;
		int rowMid_B = rowStart_B + (rowEnd_B - rowStart_B) / 2;
		int rowMid_C = rowStart_C + (rowEnd_C - rowStart_C) / 2;

		int columnMid_A = columnStart_A + (columnEnd_A - columnStart_A) / 2;
		int columnMid_B = columnStart_B + (columnEnd_B - columnStart_B) / 2;
		int columnMid_C = columnStart_C + (columnEnd_C - columnStart_C) / 2;

		// 计算 C00
		// A00 * B00
		matrix_multiply_recursive(A, B, C,
			rowStart_A, rowMid_A, columnStart_A, columnMid_A,
			rowStart_B, rowMid_B, columnStart_B, columnMid_B,
			rowStart_C, rowMid_C, columnStart_C, columnMid_C );
		// A01 * B10
		matrix_multiply_recursive(A, B, C,
			rowStart_A, rowMid_A, columnMid_A+1, columnEnd_A,
			rowMid_B+1, rowEnd_B, columnStart_B , columnMid_B,
			rowStart_C, rowMid_C, columnStart_C, columnMid_C);



		//计算 C01
		// A00 * B01
		matrix_multiply_recursive(A, B, C,
			rowStart_A, rowMid_A, columnStart_A, columnMid_A,
			rowStart_B, rowMid_B, columnMid_B + 1, columnEnd_B,
			rowStart_C, rowMid_C, columnMid_C+1, columnEnd_C);
		// A01 * B11
		matrix_multiply_recursive(A, B, C,
			rowStart_A, rowMid_A, columnMid_A + 1, columnEnd_A,
			rowMid_B + 1, rowEnd_B, columnMid_B + 1, columnEnd_B,
			rowStart_C, rowMid_C, columnMid_C + 1, columnEnd_C);



		// 计算C10
		// A10 * B00
		matrix_multiply_recursive(A, B, C,
			rowMid_A + 1, rowEnd_A, columnStart_A, columnMid_A,
			rowStart_B, rowMid_B, columnStart_B, columnMid_B,
			rowMid_C + 1, rowEnd_C, columnStart_C, columnMid_C);
		// A11 * B10
		matrix_multiply_recursive(A, B, C,
			rowMid_A + 1, rowEnd_A, columnMid_A + 1, columnEnd_A,
			rowMid_B + 1, rowEnd_B, columnStart_B, columnMid_B,
			rowMid_C + 1, rowEnd_C, columnStart_C, columnMid_C);



		//计算C11
		// A10 * B01
		matrix_multiply_recursive(A, B, C,
			rowMid_A + 1, rowEnd_A, columnStart_A, columnMid_A,
			rowStart_B, rowMid_B, columnMid_B + 1, columnEnd_B,
			rowMid_C + 1, rowEnd_C, columnMid_C + 1, columnEnd_C);
		// A11 * B11
		matrix_multiply_recursive(A, B, C,
			rowMid_A + 1, rowEnd_A, columnMid_A + 1, columnEnd_A,
			rowMid_B + 1, rowEnd_B, columnMid_B + 1, columnEnd_B,
			rowMid_C + 1, rowEnd_C, columnMid_C + 1, columnEnd_C);
	}
}

inline bool Strassen::checkSizeIsPowerOf2(Matrix& A, Matrix& B, Matrix& C)
{
	bool res = true;
	int size = A.size();
	if (B.size() != size || C.size() != size)  return false;
	if (A[0].size() != size || B[0].size() != size || C[0].size() != size) return false;
	while (size > 1) {
		if (size % 2 != 0)  return false;
		size = size / 2;
	}
	return true;
}





#endif // !STRASSEN
