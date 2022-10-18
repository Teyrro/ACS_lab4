#include "ImportantStuff.h"

void WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix)> func) {
	Timer timer;
	timer.start();
	Matrix c = func(a, b);
	timer.stop();
	std::cout << "ElapsedSeconds: " << timer.elapsedSeconds() << "\n";
}

Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix)> func, bool d, char s, char name) {
	Timer timer;
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
	Matrix c = func(a, b);
	timer.stop();
	switch (s) {
	case 'S': {
		std::cout << "Elapsed Seconds: " << timer.elapsedSeconds() << "\n\n";
		break;
	}
	case 'M': {
		std::cout << "Elapsed MilliSeconds: " << timer.elapsedMilliseconds() << "\n\n";
		break;
	}
	}
	return c;
}

Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix, int)> func, int x, char s, char name) {
	Timer timer;
	switch (name) {
	case 'O': {
		std::cout << "Ordinary Multiply Matrix: " << "\n";
		break;
	}
	case 'M': {
		std::cout << "Modified Multiply Matrix: "  << "\n";
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
	switch (s) {
	case 'S': {
		std::cout << "Elapsed Seconds: " << timer.elapsedSeconds() << "\n\n";
		break;
		}
	case 'M': {
		std::cout << "Elapsed MilliSeconds: " << timer.elapsedMilliseconds() << "\n\n";
		break;
	}
	}
	return c;
}

Matrix WorkFuncTime(Matrix const& a, Matrix const& b, std::function<Matrix(Matrix, Matrix, int)> func, int x, char s, char name, Timer& timer) {
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
	switch (s) {
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