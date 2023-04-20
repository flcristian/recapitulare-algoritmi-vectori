#include <iostream>
#include <fstream>

using namespace std;

// Sa se determine catul si restul impartirii polinomului P(x)
// cu N(x). Unde N(x) = X - a.

// <=> Fisier Citire <=>
// Prima linie : numarul a
// Urmatoarea linie : coeficientii polinomului P(x)

// Polinomul P(x) si N(x).

int c[100]; // Coeficientii polinomului.
int n; // Numarul coeficientilor polinomului.
int a; // Numarul a. Unde N(x) = X - a.

// Catul si restul.

int cCat[100]; // Coeficientii catului impartirii.
int nCat = 0; // Numarul coeficientilor catului impartirii.
int rest = -1; // Restul impartirii.

void citire() {
	ifstream f("input.txt");
	f >> a;
	n = 0;
	while (!f.eof()) {
		f >> c[n];
		n++;
	}
	f.close();
}

void aplicareHorner() {
	cCat[0] = c[0];
	nCat++;
	while (nCat < n - 1) {
		cCat[nCat] = a * cCat[nCat - 1] + c[nCat];
		nCat++;
	}
	rest = a * cCat[nCat - 1] + c[nCat];
}

void afisareCat() {
	cout << "Catul este : " << endl;
	for (int i = 0; i < nCat - 1; i++) {
		cout << cCat[i] << "X^" << nCat - i - 1;
		if (cCat[i + 1] < 0) {
			cout << " ";
		}
		else {
			cout << " +";
		}
	}
	cout << cCat[nCat - 1] << endl;
}

void afisareRest() {
	cout << endl << "Restul este : " << endl;
	cout << rest << endl;
}

void rezolvare() {
	citire();
	aplicareHorner();
	afisareCat();
	afisareRest();
}

