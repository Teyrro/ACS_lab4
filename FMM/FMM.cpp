#include "Tasks.h"
#include "Benсhmark.h"
void main() {
	Benсhmark unit;
	Timer timer;
	Matrix a(8, 8), b(8, 8);
	FillM(a), FillM(b);
	int i(2), size(a.str * b.column);
	while (size / i != 0) {
		std::cout << "i = " << i << "\n";
		Matrix c = unit.WorkFuncTime(a, b, a.DGEMM_BLAS_2, timer, i, 'N', 'B');
		std::cout << c;
		i *= 2;
	}
	//Task3();
	//Task7_Block();
	
}