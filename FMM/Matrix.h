#pragma once
#include <vector>
#include <ostream>
#include <iostream>

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

	friend std::ostream& operator<< (std::ostream& out, Matrix a) {
		out << "Matrix:\n";
		for (int i(0); i < a.str; i++) {
			int row = i * a.column;
			for (int j(0); j < a.column; j++)
				out << a[row + j] << " ";
			out << "\n";
		}
		out << "\n";
		return out;
	}
};

void PrintM(Matrix& a);
void FillM(Matrix& a);


