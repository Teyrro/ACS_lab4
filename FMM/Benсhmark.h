#pragma once
#include <vector>
#include <string>
#include "Matrix.h"
#include "Timer.h"
using Func2 = std::function<Matrix (Matrix const &, Matrix const &, const int)>;

class Benñhmark
{
	int expCount;
public:
	int blockSize, origUnitSize;
	std::string nameAlg;
	std::vector<double> time;
	double avTime;
	std::vector<double> err;
	double avErr;
	std::vector<double> absErr;
	std::vector<double> relErr;

	Benñhmark() : expCount(10), blockSize(100), origUnitSize(1024), time(10), avTime(0), avErr(0) {}

	Benñhmark(int expCount1, char nameUnitS, int blockSize1) : expCount(expCount1), blockSize(blockSize1), time(expCount1),
	err(expCount1), absErr(expCount1), relErr(expCount1), avTime(0), avErr(0) {
		switch (nameUnitS) {
		case 'K': {
			origUnitSize = 1024;
			break;
		}
		case 'M': {
			origUnitSize = 1024 * 1024;
			break;
		}
		}
	}

	void CalculateAvTime();

	//numbFunc 0 - DGEMM_BLAS, 1 - DGEMM_BLAS_1, 2 - DGEMM_BLAS_2
	void Test(int expCount, int M, int N, int K, int numbFunc, int block, char sizeS = 'S');

	//numbFunc 0 - DGEMM_BLAS, 1 - DGEMM_BLAS_1, 2 - DGEMM_BLAS_2
	void Test(int expCount, Matrix const& a, Matrix const& b, int numbFunc, int block, char sizeS = 'S', char name = '.');
	void WorkFuncTime1(Matrix const& a, Matrix const& b, Func2 func, Timer& timer, int x = 1, char typeSecond = '.', char name = '.');
	Matrix WorkFuncTime(Matrix const& a, Matrix const& b, Func2 func, Timer& timer, int x = 1, char typeSecond = '.', char name = '.');


};

