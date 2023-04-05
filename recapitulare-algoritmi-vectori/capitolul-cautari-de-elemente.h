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
	if (nr == 1 || nr == 0) {
		return 1;
	}
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

// Problema 2
// Apare numarul "y" in vectorul "x"?

void citireProblema2(int x[], int& n, int& y) {
	ifstream f("input.txt");
	f >> y;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

// a) Orice metoda.

// <=> Fisier citire <=>
// Primul rand : numarul y
// Al doilea rand : elementele vectorului x

int apartineYProblema2a(int x[], int n, int y) {
	for (int i = 0; i < n; i++) {
		if (x[i] == y) {
			return i + 1;
		}
	}
	return -1;
}

void afisareProblema2a(int x[], int n, int y) {
	int k = apartineYProblema2a(x, n, y);
	if (k == -1) {
		cout << y << " nu apartine vectorului." << endl;
	}
	else {
		cout << y << " se gaseste a " << k << "-a pozitie." << endl;
	}
}

void problema2a() {
	int x[100], n, y;
	citireProblema2(x, n, y);
	afisareProblema2a(x, n, y);
}

// b) Se foloseste metoda binary search.

// <=> Fisier citire <=>
// Primul rand : numarul y
// Al doilea rand : elementele vectorului x, in ordine crescatoare

int binarySearchProblema2b(int x[], int s, int d, int y) {
	if (s > d) {
		return -1;
	}
	int m = (s + d) / 2;
	if (x[m] == y) {
		return m + 1;
	}
	else {
		if (x[m] < y) {
			binarySearchProblema2b(x, m + 1, d, y);
		}
		else {
			binarySearchProblema2b(x, s, m - 1, y);
		}
	}
}

void afisareProblema2b(int x[], int n, int y) {
	int k = binarySearchProblema2b(x, 0, n - 1, y);
	if (k == -1) {
		cout << y << " nu apartine vectorului." << endl;
	}
	else {
		cout << y << " se gaseste a " << k << "-a pozitie." << endl;
	}
}

void problema2b(){
	int x[100], n, y;
	citireProblema2(x, n, y);
	afisareProblema2b(x, n, y);
}

// Problema 3
// Apare numarul "y" in vectorul "x" pe pozitie para?
// Sa se afle utilizand binary search si sa se tipareasca pozitia.

// <=> Fisier citire <=>
// Primul rand : numarul y
// Al doilea rand : elementele vectorului x, in ordine crescatoare

void citireProblema3(int x[], int& n, int& y) {
	ifstream f("input.txt");
	f >> y;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int binarySearchProblema3(int x[], int s, int d, int y) {
	if (s > d) {
		return -1;
	}
	int m = (s + d) / 2;
	if (x[m] == y) {
		if (m % 2 == 1) {
			return m + 1;
		}
		else {
			return -1;
		}
	}
	else {
		if (x[m] < y) {
			binarySearchProblema3(x, m + 1, d, y);
		}
		else {
			binarySearchProblema3(x, s, m - 1, y);
		}
	}
}

void afisareProblema3(int x[], int n, int y) {
	int k = binarySearchProblema3(x, 0, n - 1, y);
	if (k == -1) {
		cout << y << " nu se gaseste pe pozitiile pare ale vectorului." << endl;
	}
	else {
		cout << y << " se gaseste a " << k << "-a pozitie." << endl;
	}
}

void problema3() {
	int x[100], n, y;
	citireProblema3(x, n, y);
	afisareProblema3(x, n, y);
}

// Problema 4
// Este vectorul o multime? (Au toate elementele valori diferite?)
// Daca nu, precizati si transformati vectorul in mod corespunzator.

void citireProblema4(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool apartineVectoruluiProblema4(int x[], int n, int y) {
	for (int i = 0; i < n; i++) {
		if (x[i] == y) {
			return 1;
		}
	}
	return 0;
}

void rezolvareProblema4(int x[], int n) {
	int y[100], m = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (!apartineVectoruluiProblema4(y, m, x[i])) {
			y[m] = x[i];
			m++;
		}
		else {
			flag = false;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
	if (flag) {
		cout << "Vectorul este o multime." << endl;
	}
	else {
		cout << "Vectorul nu este o multime.\nForma sa dupa transformare este :\n";
		for (int i = 0; i < m; i++) {
			cout << y[i] << " ";
		}
		cout << endl;
	}
}

void problema4() {
	int x[100], n;
	citireProblema4(x, n);
	rezolvareProblema4(x, n);
}

// Problema 5
// Se regaseste maximul primului vector in cel de-al doilea?
// Sa va tipari astfel : (maxim) - TRUE/FALSE

// <=> Fisier citire <=>
// Primul rand : doua numere (dimensiunea primului vector, respectiv celui de-al doilea)
// Al doilea rand : elementele primului vector
// Al treilea rand : elementele celui de-al doilea vector

void citireProblema5(int x[], int y[], int& n, int& m) {
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

int maximProblema5(int x[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
		}
	}
	return max;
}

bool apartineVectoruluiProblema5(int x[], int n, int y) {
	for (int i = 0; i < n; i++) {
		if (x[i] == y) {
			return 1;
		}
	}
	return 0;
}

void rezolvareProblema5(int x[], int y[], int n, int m) {
	int max = maximProblema5(x, n);
	cout << max << " - ";
	if (apartineVectoruluiProblema5(y, m, max)) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	cout << "\n";
}

void problema5() {
	int x[100], y[100], n, m;
	citireProblema5(x, y, n, m);
	rezolvareProblema5(x, y, n, m);
}