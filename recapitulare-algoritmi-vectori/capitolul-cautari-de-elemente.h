#include <iostream>
#include <fstream>

using namespace std;

// Problema 1
// Cate dintre elementele vectorului x[] sunt numere din sirul
// lui Fibonacci?

void citireProblema1(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool esteFibonacciProblema1(int nr) {
	int x[100];
	x[0] = 1, x[1] = 1;
	int n = 2;
	while (x[n - 1] + x[n - 2] <= nr) {
		if (x[n - 1] + x[n - 2] == nr) {
			return 1;
		}
		x[n] = x[n - 1] + x[n - 2];
		n++;
	}
	return 0;
}

void problema1() {
	int x[100], n;
	citireProblema1(x, n);

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (esteFibonacciProblema1(x[i])) {
			count++;
		}
	}
	cout << count << endl;
}