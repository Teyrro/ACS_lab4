#include <iostream>
#include "Matrix.h"

void main() {
	int sizeB(4);
	int rowA(8), columnA(sizeB);
	Matrix a(rowA, columnA), b(sizeB, sizeB);
	FillM(a);
	FillM(b);
	PrintM(a);
	PrintM(b);
	Matrix c = a.DGEMM_BLAS(a, b);
	Matrix d = a.DGEMM_BLAS_1(a, b);
	Matrix f = a.DGEMM_BLAS_2(a, b, 2);

	PrintM(c);
	PrintM(d);
	PrintM(f);
}