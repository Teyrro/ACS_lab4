#include "Benñhmark.h"
#include <cmath>
#include <fstream>
#include <list>
#include <string>

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

void Task7(int sizeMatr, int expCount, int expAv) {

	std::string filename("Test7.csv");
	std::ofstream file(filename, std::ios::app);

	std::string nameFunc("block multiolication");

	file << "1_test - ordinary algorytm, n_test - " + nameFunc << "; \n";
	file << "size; " << "avTime(Second); " << "Acceleration(1_test / n_Test); \n";

	int betterValue(1), block(1);
	Benñhmark unit(expAv, 'K', sizeMatr * sizeMatr);
	double acceleration(1);

	int size = sizeMatr;



	for (int i(0); i < expCount; i++) {
		unit.avTime = 0;
		unit.Test(expAv, Matrix(size, size), Matrix(size, size), 0, block);
		double simpleMult = unit.avTime;
		file << size << ";" << simpleMult << ";" << acceleration << ";\n";
		unit.avTime = 0;
		unit.Test(expAv, Matrix(size, size), Matrix(size, size), 1, block);
		acceleration = simpleMult / unit.avTime;
		file << size << ";" << unit.avTime << ";" << acceleration << ";\n";
		size += sizeMatr;
		std::cout << "Acceleation: " << acceleration << "\n\n";
		std::cout << "--------------------------------------------\n\n";

	}
	file << "\n";
	file.close();

}

void Task7_Block(int M, int N, int K, char sizeS, int expCount) {
	Matrix a(M, N), b(N, K);
	std::list<int> multy1;
	multy(multy1, M);

	std::string filename("Test7.csv");
	std::ofstream file(filename, std::ios::app);
	file << "size; " << M << "; \n";

	std::string nameFunc("block multiolication");

	file << "1_test - ordinary algorytm, n_test - " + nameFunc << "; \n";
	file << "avTime(Second); " << "Acceleration(1_test / n_Test); \n";

	int size(b.column), betterValue(1), block(1);
	Benñhmark unit(expCount, 'K', M * K);
	double acceleration(1);

	unit.Test(expCount, a, b, 0, block);
	double simpleMult = unit.avTime;
	unit.avTime = 0;
	file << unit.avTime << ";" << acceleration << ";\n";


	unit.Test(expCount, a, b, 2, block);
	acceleration = simpleMult / unit.avTime;
	file << unit.avTime << ";" << acceleration << ";\n";
	unit.avTime = 0;

	int i(0);
	while (multy1.empty() != true) {
		block *= multy1.front();
		multy1.pop_front();

		unit.avTime = 0;
		unit.Test(expCount, a, b, 2, block);
		double accel2(simpleMult / unit.avTime);
		file << unit.avTime << ";" << accel2 << ";\n";
		
		std::cout << "Block: " << block << "\n";
		std::cout << "Acceleation: " << accel2 << "\n\n";
		//std::cout << "i = " << i << "\n";
		if (accel2 > acceleration) {
			betterValue = block;
			acceleration = accel2;
		}
		std::cout << "--------------------------------------------\n\n";
	}
	file.close();
	std::cout << "Better block size: " << betterValue << "\n";
}

void Task_7(int sizeMatr, short expCount) {
	std::string filename("Test7.csv");
	std::ofstream file(filename, std::ios::trunc);
	file.close();

	Task7(sizeMatr, 5, 7);
	//Task7(sizeMatr * 2, sizeMatr * 2, sizeMatr * 2, 'S', expCount, 1);
	//Task7(sizeMatr * 5, sizeMatr * 5, sizeMatr * 5, 'S', expCount, 1);
	Task7_Block(sizeMatr, sizeMatr, sizeMatr, 'S', expCount);

}