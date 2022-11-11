#include "Tasks.h"
#include "Benсhmark.h"%
#include <windows.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int M, N, K, size(2000);
	std::cout << "Set size like \"M N K\" for matrix MxN and NxK\n";
	//std::cin >> M >> N >> K;
	Benсhmark unit;
	Timer timer;
	//std::cout << unit.avTime;
	//Task7_Block(size, size, size, 'S', 4);
	Matrix a(size, size), b(size, size);
	unit.Test(7, size, size, size, 2, 16);

	//Task3();
	//Task2(100, 6);
	
}