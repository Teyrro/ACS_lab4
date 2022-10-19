#include "Benñhmark.h"
#include <cmath>

void Test(int expCount, int blockSize) {
	Benñhmark unit(expCount, 'K', blockSize);
	Timer timer;
	Matrix a(blockSize, blockSize), b(blockSize, blockSize);
	for (int i(0); i < expCount; i++) {
		unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, timer, 2);
		unit.time[i] = timer.elapsedNanoseconds();
		unit.avTime += timer.elapsedNanoseconds();;
	}
	unit.avTime /= expCount;
}

void Task3() {
	int i(100);
	Timer timer;
	Benñhmark unit;
	while (true) {
		int sizeB(i);
		int rowA(2 * i), columnA(sizeB);
		Matrix a(rowA, columnA), b(sizeB, sizeB);
		FillM(a);
		FillM(b);
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

void Task7_Block() {
	int i(15), block(2);
	Benñhmark unit;
	double  prevElapsedT;
	Timer timer;
	do  {
		int sizeB(i);
		int rowA(2 * i), columnA(sizeB);
		Matrix a(rowA, columnA), b(sizeB, sizeB);
		FillM(a);
		FillM(b);
		Matrix f = unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, timer, block, 'N', 'B');
		std::cout << f;
		std::cout << "Block: " << block << "\n";
		std::cout << "size: " << i << "\n\n";
		block++;
		prevElapsedT = timer.elapsedNanoseconds();
		f = unit.WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, timer, block, 'N', 'B');
		std::cout << f;
		std::cout << "Block: " << block << "\n";
		std::cout << "size: " << i << "\n";
		std::cout << "(" << timer.elapsedNanoseconds() << " - " << prevElapsedT << ") = " << abs(timer.elapsedNanoseconds() - prevElapsedT) << " <= 0\n";
		std::cout << "--------------------------------------------\n\n";
		block++;
	} while (abs(timer.elapsedNanoseconds() - prevElapsedT) >= 0);
}