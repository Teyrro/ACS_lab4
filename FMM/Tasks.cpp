#include "ImportantStuff.h"
#include <cmath>

void Task3() {
	int i(100);
	Timer timer;
	while (true) {
		int sizeB(i);
		int rowA(2 * i), columnA(sizeB);
		Matrix a(rowA, columnA), b(sizeB, sizeB);
		FillM(a);
		FillM(b);
		//std::cout << a << b;
		Matrix c = WorkFuncTime(a, b, Matrix::DGEMM_BLAS, true, 'M', 'O');
		Matrix d = WorkFuncTime(a, b, Matrix::DGEMM_BLAS_1, true, 'M', 'M');
		Matrix f = WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, 2, 'M', 'B');
		//Matrix c = a.DGEMM_BLAS(a, b);
		//Matrix d = a.DGEMM_BLAS_1(a, b);
		//Matrix f = a.DGEMM_BLAS_2(a, b, 2);
		//std::cout << c << d << f;
		std::cout << "size: " << i << "\n";
		std::cout << "--------------------------------------------\n\n";
		i *= 10;
	}
}

void Task7_Block() {
	int i(15), block(2);
	double  prevElapsedT;
	Timer timer;
	do  {
		int sizeB(i);
		int rowA(2 * i), columnA(sizeB);
		Matrix a(rowA, columnA), b(sizeB, sizeB);
		FillM(a);
		FillM(b);
		Matrix f = WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, block, 'N', 'B', timer);
		std::cout << f;
		std::cout << "Block: " << block << "\n";
		std::cout << "size: " << i << "\n\n";
		block++;
		prevElapsedT = timer.elapsedNanoseconds();
		f = WorkFuncTime(a, b, Matrix::DGEMM_BLAS_2, block, 'N', 'B', timer);
		std::cout << f;
		std::cout << "Block: " << block << "\n";
		std::cout << "size: " << i << "\n";
		std::cout << "(" << timer.elapsedNanoseconds() << " - " << prevElapsedT << ") = " << abs(timer.elapsedNanoseconds() - prevElapsedT) << " <= 0\n";
		std::cout << "--------------------------------------------\n\n";
		block++;
	} while (abs(timer.elapsedNanoseconds() - prevElapsedT) >= 0);
}