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

// Problema 2
// Sa se afiseze doar numerele pare dintr-un vector de numere intregi.

void citireProblema2(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

void afisarePareProblema2(int x[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) {
            cout << x[i] << " ";
        }
    }
}

void problema2() {
    int x[100], n;
    citireProblema2(x, n);
    afisarePareProblema2(x, n);
}

// Problema 3
// Sa se afiseze numerele pare de pe pozitiile divizibile cu 3.

void citireProblema3(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

void afisarePareProblema3(int x[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0 && (i + 1) % 3 == 0) {
            cout << x[i] << " ";
        }
    }
}

void problema3() {
    int x[100], n;
    citireProblema3(x, n);
    afisarePareProblema3(x, n);
}

// Problema 4
// Sa se afiseze numerele pozitive de pe pozitii impare.

void citireProblema4(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

void afisarePozitiveProblema4(int x[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] > 0 && (i + 1) % 2 == 1) {
            cout << x[i] << " ";
        }
    }
}

void problema4() {
    int x[100], n;
    citireProblema4(x, n);
    afisarePozitiveProblema4(x, n);
}

// Problema 5
// Sa se construiasca un vector nou si sa se afiseze, doar cu elementele patrat perfect.

void citireProblema5(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

bool estePatratPerfectProblema5(int n) {
    if (sqrt(n) == (int)sqrt(n)) {
        return 1;
    }
    return 0;
}

void elementelePatratPerfectProblema5(int x[], int y[], int n, int& m) {
    m = 0;
    for (int i = 0; i < n; i++) {
        if (estePatratPerfectProblema5(x[i])) {
            y[m] = x[i];
            m++;
        }
    }
}

void afisareProblema5(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}

void problema5() {
    int x[100], n;
    citireProblema5(x, n);

    int y[100], m;
    elementelePatratPerfectProblema5(x, y, n, m);
    afisareProblema5(y, m);
}