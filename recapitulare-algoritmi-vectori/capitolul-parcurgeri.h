#include <iostream>
#include <fstream>

using namespace std;

// Problema 1
// Calculati suma elementelor pozitive ale unui vector.

void citireProblema1(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int sumaPozitiveProblema1(int x[], int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			suma += x[i];
		}
	}
	return suma;
}

void problema1() {
	int x[100], n;
	citireProblema1(x, n);

	int suma = sumaPozitiveProblema1(x, n);
	cout << "Suma elementelor pozitive : " << suma << endl;
}