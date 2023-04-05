#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

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

// Problema 2
// Determinati secventa maxima palindromica si afisati-o.

void citireProblema2(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void maxSecventaPalindromicaProblema2(int x[], int n, int& start, int& maxLenght) {
	start = 0, maxLenght = 1;
	for (int i = 1; i < n - 1; i++) {
		int lenght = 1;
		int j = i - 1, k = i + 1;
		while (j > -1 && k < n && x[j] == x[k]) {
			j--, k++;
			lenght += 2;
		}
		if (lenght > maxLenght) {
			start = j + 1;
			maxLenght = lenght;
		}
	}
}

void afisareProblema2(int x[], int start, int maxLenght) {
	for (int i = start, k = 0; k < maxLenght; k++) {
		cout << x[i + k] << " ";
	}
	cout << endl;
}

void problema2() {
	int x[100], n;
	citireProblema2(x, n);
	int start, maxLenght;
	maxSecventaPalindromicaProblema2(x, n, start, maxLenght);
	afisareProblema2(x, start, maxLenght);
}

// Problema 3
// Determinati secventa maxima care incepe si se 
// gata cu acelasi element si afisati-o.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void maxSecventaProblema3(int x[], int n, int& start, int& maxLenght) {
	start = 0, maxLenght = 1;
	for (int i = 0; i < n - 1; i++) {
		int j = n - 1;
		while (j > i && x[j] != x[i]) {
			j--;
		}
		int lenght = j - i + 1;
		if (lenght > maxLenght) {
			start = i;
			maxLenght = lenght;
		}
	}
}

void afisareProblema3(int x[], int start, int maxLenght) {
	for (int i = start, k = 0; k < maxLenght; k++) {
		cout << x[i + k] << " ";
	}
	cout << endl;
}

void problema3() {
	int x[100], n;
	citireProblema3(x, n);
	
	int start, maxLenght;
	maxSecventaProblema3(x, n, start, maxLenght);
	afisareProblema3(x, start, maxLenght);
}

// Problema 4
// Sa se determine daca y este subsir al lui x.

// <=> Fisier citire <=>
// Primul rand : doua numere (dimensiunea primului vector, respectiv celui de-al doilea)
// Al doilea rand : elementele primului vector
// Al treilea rand : elementele celui de-al doilea vector

void citireProblema4(int x[], int y[], int& n, int& m) {
	ifstream f("input.txt");
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	for (int i = 0; i < m; i++) {
		f >> y[i];
	}
	f.close();
}

bool esteYSubsirProblema4(int x[], int y[], int n, int m) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (c == m) {
			return 1;
		}
		if (x[i] == y[c]) {
			c++;
		}
		else {
			c = 0;
		}
	}
	return 0;
}

void afisareProblema4(int x[], int y[], int n, int m) {
	string r = "Vectorul y ";
	if (!esteYSubsirProblema4(x, y, n, m)) {
		r += "nu ";
	}
	r += "este subsir al vectorului x.";
	cout << r << endl;
}

void problema4() {
	int x[100], y[100], n, m;
	citireProblema4(x, y, n, m);
	afisareProblema4(x, y, n, m);
}

// Problema 5
// Determinati secventa maxima de numere consecutive (Ex : 1 2 3)
// si afisati-o.

void citireProblema5(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void maxSecventaProblema5(int x[], int n, int& start, int& maxLenght) {
	start = 0, maxLenght = 1;
	int current = 0, lenght = 1;
	for (int i = 0; i < n - 1; i++) {
		if (lenght > maxLenght) {
			maxLenght = lenght;
			start = current;
		}
		if (x[i] + 1 == x[i + 1]) {
			if (lenght == 1) {
				current = i;
			}
			lenght++;
		}
		else {
			lenght = 1;
		}
	}
}

void afisareProblema5(int x[], int start, int maxLenght) {
	for (int i = start, k = 0; k < maxLenght; k++) {
		cout << x[i + k] << " ";
	}
	cout << endl;
}

void problema5() {
	int x[100], n;
	citireProblema5(x, n);

	int start, maxLenght;
	maxSecventaProblema5(x, n, start, maxLenght);
	afisareProblema5(x, start, maxLenght);
}