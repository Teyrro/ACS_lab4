#include "Benñhmark.h"

void Benñhmark::CalculateAvTime() {
	for (int i(0); i < time.size(); i++)
		avTime += time[i];
	avTime /= expCount;
}


Matrix Benñhmark::WorkFuncTime(Matrix const& a, Matrix const& b, Func1 func, Timer& timer, char typeSecond, char name) {
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