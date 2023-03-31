#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Problema 1
// Se da un vector de numere intregi pozitive de cel putin
// doua cifre fiecare. Sa se scrie cea mai lunga secventa de
// elemente consecutive prime ale caror olgindire sunt tot numere
// prime.

void citireProblema1(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int oglindireProblema1(int n) {
	int o = 0;
	while (n > 0) {
		o = o * 10 + n % 10;
		n /= 10;
	}
	return o;
}

int countDivProblema1(int n) {
	int c = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			c++;
			if (i != sqrt(n)) {
				c++;
			}
		}
	}
	return c;
}

bool estePrimProblema1(int n) {
	if (countDivProblema1(n) == 2) {
		return 1;
	}
	return 0;
}

bool conditieProblema1(int n) {
	int o = oglindireProblema1(n);
	if (estePrimProblema1(n) && estePrimProblema1(o)) {
		return 1;
	}
	return 0;
}

void secventaProblema1(int x[], int n, int& smax, int& dmax) {
	smax = 1, dmax = 0;
	for (int i = 0; i < n; i++) {
		if (conditieProblema1(x[i])) {
			int j = i;
			while (j + 1 < n && conditieProblema1(x[j + 1])) {
				j++;
			}
			if (j - i + 1 > dmax - smax + 1) {
				smax = i, dmax = j;
			}
			i = j;
		}
	}
}

void problema1() {
	int x[100], n, smax, dmax;
	citireProblema1(x, n);
	secventaProblema1(x, n, smax, dmax);
	for (int i = smax; i <= dmax; i++) {
		cout << x[i] << " ";
	}
}