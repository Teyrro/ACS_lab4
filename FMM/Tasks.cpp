#include "Benñhmark.h"
#include <cmath>


void Task2(int blockS, int expCount) {
	int i(blockS), j(0);
	std::vector<std::pair<int, double>> BSizeAvTime(expCount);
	Timer timer;
	Benñhmark unit;
	while (expCount > j) {
		unit.Test(10, i, i, i, 0, 1, 'N');
		//std::cout << c << d << f;
		std::cout << "size: " << i*i << "\n";
		std::cout << "--------------------------------------------\n\n";
		BSizeAvTime[j].first = i;
		BSizeAvTime[j].second = unit.avTime;
		i += blockS;
		j++;
	}
}

void Task3() {
	int i(100);
	Timer timer;
	Benñhmark unit;
	while (true) {
		int sizeB(i);
		int rowA(2 * i), columnA(sizeB);
		Matrix a(rowA, columnA), b(sizeB, sizeB);
		//std::cout << a << b;
		Matrix c = unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS, timer, 'M', 'O');
		Matrix d = unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS_1, timer, 'M', 'M');
		Matrix f = unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, timer, 2, 'M', 'B');
		//std::cout << c << d << f;
		std::cout << "size: " << i << "\n";
		std::cout << "--------------------------------------------\n\n";
		i *= 10;
	}
}

void Task7_Block(int M, int N, int K, char sizeS) {
	Matrix a(M, N), b(N, K);
	int size(a.str * b.column), betterValue(1), block(2), expCount(1000);
	Benñhmark unit(expCount, 'K', M*K);
	Timer timer;

	double  prevElapsedT;
	unit.Test(1000, a, b, 2, block);
	prevElapsedT = unit.avTime;

	while (size / block != 0) {
		std::cout << "Block: " << block << "\n";
		//std::cout << "size: " << i << "\n\n";
		//std::cout << "i = " << i << "\n";
		unit.Test(expCount, a, b, 2, block, sizeS);

		if (prevElapsedT > unit.avTime) {
			betterValue = block;
			prevElapsedT = unit.avTime;
		}
		std::cout << "--------------------------------------------\n\n";
		block *= 2;
	}

	std::cout << "Better block size: " << betterValue;
}