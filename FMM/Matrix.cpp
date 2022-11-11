#include "Matrix.h"
#include<math.h>
#include<stdio.h> 
#include <iostream>
#include <cassert>


void Matrix::resize(int str, int column) {
	this->str = str, this->column = column;
	this->massive.resize(str * column);
}

void PrintM(Matrix& a) {
	std::cout << "Matrix:\n";
	for (int i(0); i < a.str; i++) {
		int row = i * a.column;
		for (int j(0); j < a.column; j++)
			std::cout << a[row + j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

void FillM(Matrix* a) {
	
	for (int i(0); i < a->str; i++) {
		int row = i * a->column;
		for (int j(0); j < a->column; j++)
			a->massive[row + j] = rand() % 100;
	}
}
void FillM(Matrix& a) {
	for (int i(0); i < a.str; i++) {
		int row = i * a.column;
		for (int j(0); j < a.column; j++)
			a.massive[row + j] = rand() % 100;
	}
}


Matrix Matrix::DGEMM_BLAS(Matrix const& a, Matrix const& b, const int bSize) {
	assert(a.column == b.str);
		
	Matrix c(a.str, b.column, false);
	for (int i(0); i < a.str; i++) {
		int row(i * a.column);
		for (int j(0); j < b.column; j++) {	
			int j0(i * b.column + j);
			for (int k = 0; k < a.column; ++k)
				c.massive[j0] += a.massive[row + k] * b.massive[k * b.column + j];
				//C[i * N + j] += A[i * K + k] * B[k * N + j];
		}
	}
	return c;
}

Matrix Matrix::DGEMM_BLAS_1(Matrix const & a, Matrix const& b, const int bSize) {
	assert(a.column == b.str);
	Matrix c(a.str, b.column, false);
	for (int i(0); i < a.str; i++) {
		int row(i * b.column);
		for (int k = 0; k < a.column; ++k) {
			int rowB(k * b.column);
			double A = a.massive[i * a.column + k];
			for (int j(0); j < b.column; j++) {
				c.massive[row + j] += A * b.massive[rowB + j];
			}
		}
	}
	return c;
}

//Matrix&& Matrix::DGEMM_BLAS_2(Matrix const& a, Matrix const& b, int BS) {
//	assert(a.column == b.str);
//
//	Matrix c(a.str, b.column);
//	for (int di = 0; di < a.str; di += BS) {
//		for (int dj = 0; dj < b.column; dj += BS) {
//			for (int dk = 0; dk < a.column; dk += BS) {
//				for (int i = di; i < fmin(di + BS, a.str); i++) {
//					int rowC = i * b.column, rowA = i * a.column;
//					for (int k = dk; k < fmin(dk + BS, a.column); k++) {
//						int rowB = k * b.column;
//						for (int j = dj; j < fmin(dj + BS, b.column); j++)
//							c.massive[rowC + j] += a.massive[rowA + k] * b.massive[rowB + j];
//					}
//				}
//			}
//		}
//	}
//	return std::move(c);
//}

Matrix Matrix::DGEMM_BLAS_2(Matrix const& a, Matrix const& b, const int bSize) {
	assert(a.column == b.str);
	assert(a.str % bSize == 0);

	Matrix c(a.str, b.column, false);
	for (int jk = 0; jk < a.str / bSize; jk++)
		for (int ik = 0; ik < a.str / bSize; ik++)
			for (int j = jk * bSize; j < jk * bSize + bSize; j++) {
				int row(j * b.column);
				for (int k = ik * bSize; k < ik * bSize + bSize; k++) {
					int rowK(k * b.column);
					double A(a.massive[row + k]);
					for (int i = 0; i < a.str; i++)
						c.massive[row + i] += A * b.massive[rowK + i];
				}
			}
				

	return c;
}



