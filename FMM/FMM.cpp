#include "Tasks.h"
#include "Benсhmark.h"
#include <windows.h>
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int M, N, K, size(1000);
	std::cout << "Set size like \"M N K\" for matrix MxN and NxK\n";
	//std::cin >> M >> N >> K;
	Benсhmark unit;
	Timer timer;
	//unit.Test(1, size, size, size, 0, 'S');
	//unit.avTime = 0;
	//unit.Test(1, size, size, size, 2, 2, 'S');
	//std::cout << unit.avTime;
	Task_7(size, 7);
	//Matrix a(size, size), b(size, size);
	
	//Task3();
	//Task2(100, 6);
	
}