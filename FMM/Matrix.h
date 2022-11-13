#pragma once
#include <vector>
#include <ostream>
#include <iostream>




class Matrix
{
public:
	int column, str;
	std::vector<double> massive;
	Matrix(int str, int column, bool Fill = true) : str(str), column(column), massive(str * column) {
		if (Fill)
			FillM(this);
	}

	Matrix(int&& str, int&& column, std::vector<double>&& m) 
		: str(std::move(str)), column(std::move(column)), massive(std::move(m)) {}

	Matrix(Matrix&& a) noexcept
		: str(std::move(a.str)), column(std::move(a.column)), massive(std::move(a.massive)) {}

	Matrix() {

	}

	void resize(int str = 0, int column = 0);
	static Matrix DGEMM_BLAS(Matrix const& a, Matrix const& b, const int bSize);
	static Matrix DGEMM_BLAS_1(Matrix const& a, Matrix const& b, const int bSize);
	static Matrix DGEMM_BLAS_2(Matrix const& a, Matrix const& b, const int bSize);
	friend void FillM(Matrix* a);
	double operator[] (int index) {
		return massive[index];
	}



	friend std::ostream& operator<< (std::ostream& out, Matrix const& a) {
		out << "Matrix:\n";
		for (int i(0); i < a.str; i++) {
			int row = i * a.column;
			for (int j(0); j < a.column; j++)
				out << a.massive[row + j] << " ";
			out << "\n";
		}
		out << "\n";
		return out;
	}
};

void PrintM(Matrix& a);
void FillM(Matrix& a);
void FillM(Matrix* a);