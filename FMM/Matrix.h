#pragma once
#include <vector>

class Matrix
{
public:
	int column, str;
	std::vector<double> massive;
	Matrix(int str, int column) : str(str), column(column), massive(str * column) {}



	void resize(int str = 0, int column = 0);
	static Matrix DGEMM_BLAS(Matrix a, Matrix b);
	static Matrix DGEMM_BLAS_1(const Matrix a, const Matrix b);
	static Matrix DGEMM_BLAS_2(Matrix a, Matrix b, int BS);

	double operator[] (int index) {
		return massive[index];
	}
};

void PrintM(Matrix& a);
void FillM(Matrix& a);


