#include "Benñhmark.h"
#include <cmath>
#include <fstream>
#include <list>

void Task2(int blockS, int expCount) {
	int i(blockS), j(0);
	std::vector<std::pair<int, double>> BSizeAvTime(expCount);

	Benñhmark unit(1, 'K', blockS);
	while (expCount > j) {
		unit.Test(1, i, i, i, 0, 1, 'S');
		//std::cout << c << d << f;
		BSizeAvTime[j].first = i;
		BSizeAvTime[j].second = unit.time[0];

		std::cout << "size: " << i  << " * " << i << " Time: " << unit.time[0] << '\n';
		std::cout << "--------------------------------------------\n\n";
		i += blockS;
		j++;
	}
	std::string filename("Test.csv");
	std::ofstream file(filename, std::ios::trunc);
	file << "size;";
	for (int i(0); i < BSizeAvTime.size(); i++) {
		file << BSizeAvTime[i].first << ";";
	}

	file << "\nTime (Second);";
	for (int i(0); i < BSizeAvTime.size(); i++) {
		file << BSizeAvTime[i].second << ";\n";
	}

}

void Task3() {
	int i(100), step(10), tmp;
	Benñhmark unit;
	Matrix a, b, c;
	double eps(pow(10, -5));
	double sizeMatr(((sizeof(Matrix) + sizeof(double) * i * i) * 3)), sizeRAM(6 * pow(1024, 3) * 0.5);
	double mb = pow(1024, 2);
	double dif((sizeRAM - sizeMatr) / mb);
	while (dif > 10) {

		std::cout << "Size Matrix(mb): " << sizeMatr / mb  << " <= size RAM (mb): " << sizeRAM / mb << "\n";
		dif = (sizeRAM - sizeMatr) / mb;
		std::cout << "dif: " << dif << "\n";
		std::cout << "size: " << i << "\n";
		std::cout << "--------------------------------------------\n\n";

		if (dif < 5) {
			a.resize(i, i), b.resize(i, i), c.resize(i, i);
			FillM(a), FillM(b), FillM(c);
			std::cin >> tmp;
		}

		i += step;
		sizeMatr = ((sizeof(Matrix) + sizeof(double) * i * i) * 3);
	}
}

void multy(std::list<int>& mas, int size) {
	int mult(2);
	while (size / mult != 0) {
		if (size % mult == 0) {
			size /= mult;
			mas.push_back(mult);
		}
		else {
			mult++;
		}
		
	}
}

void Task7_Block(int M, int N, int K, char sizeS, int expC) {
	Matrix a(M, N), b(N, K);
	std::list<int> multy1;
	multy(multy1, M);

	int size(b.column), betterValue(1), block(1), expCount(expC);
	Benñhmark unit(expCount, 'K', M*K);

	double  prevElapsedT, acceleration;
	unit.Test(expCount, a, b, 0, block);
	double simpleMult = unit.avTime;
	unit.avTime = 0;

	unit.Test(expCount, a, b, 2, block);
	acceleration = simpleMult / unit.avTime;
	prevElapsedT = unit.avTime;
	unit.avTime = 0;

	int i(0);
	while (multy1.empty() != true) {
		block *= multy1.front();
		multy1.pop_front();
		unit.avTime = 0;
		unit.Test(expCount, a, b, 2, block);
		double accel2(simpleMult / unit.avTime);
		
		std::cout << "Block: " << block << "\n";
		std::cout << "Acceleation: " << accel2 << "\n\n";
		//std::cout << "i = " << i << "\n";
		if (accel2 > acceleration) {
			betterValue = block;
			prevElapsedT = unit.avTime;
			acceleration = accel2;
		}
		std::cout << "--------------------------------------------\n\n";
	}

	std::cout << "Better block size: " << betterValue;
}