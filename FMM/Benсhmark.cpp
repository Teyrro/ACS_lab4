#include "Benñhmark.h"

void Benñhmark::CalculateAvTime() {
	for (int i(0); i < time.size(); i++)
		avTime += time[i];
	avTime /= expCount;
}

//numbFunc 0 - DGEMM_BLAS, 1 - DGEMM_BLAS_1, 2 - DGEMM_BLAS_2
void Benñhmark::Test(int expCount, Matrix const& a, Matrix const& b, int numbFunc, int block = 1, char sizeS, char name) {
	Func2 Func;
	Timer timer(sizeS);

	switch (numbFunc) {
	case 0: {
		Func = Matrix::DGEMM_BLAS;
		break;
	}
	case 1: {
		Func = Matrix::DGEMM_BLAS_1;
		break;
	}
	case 2: {
		Func = Matrix::DGEMM_BLAS_2;
		break;
	}
	}


	for (int i(0); i < expCount; i++) {
		WorkFuncTime1(a, b, Func, timer, block);
		time[i] = timer.Func1();
		avTime += time[i];
	}
	avTime /= expCount;

	std::cout << "AvTime: " << avTime << "\n";
}

//numbFunc 0 - DGEMM_BLAS, 1 - DGEMM_BLAS_1, 2 - DGEMM_BLAS_2
void Benñhmark::Test(int expCount, int M, int N, int K, int numbFunc, int block, char sizeS) {
	Func2 Func;
	Timer timer(sizeS);

	switch (numbFunc) {
	case 0: {
		Func = Matrix::DGEMM_BLAS;
		break;
	}
	case 1: {
		Func = Matrix::DGEMM_BLAS_1;
		break;
	}
	case 2: {
		Func = Matrix::DGEMM_BLAS_2;
		break;
	}
	}

	Matrix a(M, N), b(N, K);
	
	//std::cout << "Mb: " << ((sizeof(double) * M * N + sizeof(Matrix)) * 3) / pow(1024, 2) << " ";
	for (int i(0); i < expCount; i++) {
		WorkFuncTime1(a, b, Func, timer, block);
		time[i] = timer.Func1();
		avTime += time[i];
	}
	avTime /= expCount;
	std::cout << "AvTime: " << avTime << "\n";

}

void Benñhmark::WorkFuncTime1(Matrix const& a, Matrix const& b, Func2 func, Timer& timer, int x, char typeSecond, char name) {
	switch (name) {
	case 'O': {
		std::cout << "Ordinary Multiply Matrix: " << "\n";
		break;
	}
	case 'M': {
		std::cout << "Modified Multiply Matrix: " << "\n";
		break;
	}
	case 'B': {
		std::cout << "Block Modified Multiply Matrix: " << "\n";
		break;
	}
	}

	timer.start();
	Matrix c(func(a, b, x));
	timer.stop();
	switch (typeSecond) {
	case 'S': {
		std::cout << "Elapsed Seconds: " << timer.elapsedSeconds() << "\n\n";
		break;
	}
	case 'M': {
		std::cout << "Elapsed MilliSeconds: " << timer.elapsedMilliseconds() << "\n\n";
		break;
	}
	case 'N': {
		std::cout << "Elapsed NanoSeconds: " << timer.elapsedNanoseconds() << "\n\n";
		break;
	}
	}
}

Matrix Benñhmark::WorkFuncTime(Matrix const& a, Matrix const& b, Func2 func, Timer& timer, int x, char typeSecond, char name) {
	switch (name) {
	case 'O': {
		std::cout << "Ordinary Multiply Matrix: " << "\n";
		break;
	}
	case 'M': {
		std::cout << "Modified Multiply Matrix: " << "\n";
		break;
	}
	case 'B': {
		std::cout << "Block Modified Multiply Matrix: " << "\n";
		break;
	}
	}

	timer.start();
	Matrix c = func(a, b, x);
	timer.stop();
	switch (typeSecond) {
	case 'S': {
		std::cout << "Elapsed Seconds: " << timer.elapsedSeconds() << "\n\n";
		break;
	}
	case 'M': {
		std::cout << "Elapsed MilliSeconds: " << timer.elapsedMilliseconds() << "\n\n";
		break;
	}
	case 'N': {
		std::cout << "Elapsed NanoSeconds: " << timer.elapsedNanoseconds() << "\n\n";
		break;
	}
	}
	return c;
}