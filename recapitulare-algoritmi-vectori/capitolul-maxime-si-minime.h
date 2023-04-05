#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Problema 1
// Se dau doi vectori. Primul contine nume de elevi, iar al doilea
// notele la informatica. Se cere sa se afiseze numele elevilor cu nota
// cea mai mica. Daca mai multi elevi au nota minima, se vor afisa toti.

// <=> Fisier citire <=>
// Primul rand : numarul de elevi
// Al doilea rand : numele elevilor cu spatiu intre
// Al treilea rand : notele elevilor respectivi in aceeasi ordine

void splitProblema1(char text[], char nume[100][100]) {
	int n = 0;
	char* a;
	a = strtok(text, " ");
	while (a != NULL) {
		strcpy(nume[n], a);
		n++;
		a = strtok(NULL, " ");
	}
}

void citireProblema1(char nume[100][100], int x[], int& n) {
	ifstream f("input.txt");
	char nt[10] = "";
	f.getline(nt, 10);
	n = atoi(nt);
	char text[100] = "";
	f.getline(text, 100);
	splitProblema1(text, nume);
	for (int i = 0; i < n; i++) {
		f >> x[i];
	}
	f.close();
}

int minimProblema1(int x[], int n) {
	int min = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] < min) {
			min = x[i];
		}
	}
	return min;
}

void problema1() {
	char nume[100][100];
	int x[100], n;
	citireProblema1(nume, x, n);

	int minim = minimProblema1(x, n);
	for (int i = 1; i < n; i++) {
		if (x[i] == minim) {
			cout << nume[i] << " ";
		}
	}
	cout << endl;
}

// Problema 2
// Sa se determine elementul maxim si pozitiile pe care apare acesta.

void citireProblema2(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

int elementulMaximProblema2(int x[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;
}

void rezolvareProblema2(int x[], int n) {
    int max = elementulMaximProblema2(x, n);
    cout << "Elementul maxim este :\n";
    cout << max;
    cout << "\n\nPozitiile pe care apare acesta sunt :\n";
    for (int i = 0; i < n; i++) {
        if (x[i] == max) {
            cout << i + 1 << " ";
        }
    }
}

void problema2() {
    int x[100], n;
    citireProblema2(x, n);
    rezolvareProblema2(x, n);
}

// Problema 3
// Sa se determine elementele cu numar maxim si minim de divizori.

void citireProblema3(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

int countDivProblema3(int x) {
    int c = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            c++;
            if (pow(i, 2) != x) {
                c++;
            }
        }
    }
    return c;
}

void numereMaxMinDivProblema3(int x[], int y[], int z[], int n, int& m, int& k) {
    m = 0, k = 0;
    int maxD = 0, minD = 99999;
    for (int i = 0; i < n; i++) {
        int D = countDivProblema3(x[i]);
        if (D > maxD) {
            maxD = D;
            m = 0;
        }
        if (D < minD) {
            minD = D;
            k = 0;
        }
        if (D == maxD) {
            y[m] = x[i];
            m++;
        }
        if (D == minD) {
            z[k] = x[i];
            k++;
        }
    }
}

void afisareProblema3(int y[], int z[], int m, int k) {
    cout << "Elemente cu numar maxim de divizori :\n";
    for (int i = 0; i < m; i++) {
        cout << y[i] << " ";
    }
    cout << "\n\nElemente cu numar minim de divizori :\n";
    for (int i = 0; i < k; i++) {
        cout << z[i] << " ";
    }
}

void problema3() {
    int x[100], n;
    int y[100], z[100], m, k;
    citireProblema3(x, n);
    numereMaxMinDivProblema3(x, y, z, n, m, k);
    afisareProblema3(y, z, m, k);
}

// Problema 4
// Sa se determine lungimea maxima a unui segment format cu
// punctele date. Sa se afiseze acele doua puncte.

// <=> Fisier citire <=>
// Primul rand : numarul de puncte
// Dupa, pe fiecare rand, cate doua elemente (abscisa si ordonata)
// (Atatea randuri cate numere de puncte sunt)

void citireProblema4(int x[100][100], int& n) {
    ifstream f("input.txt");
    f >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            f >> x[i][j];
        }
    }
    f.close();
}

double distantaDouaPuncte(int x1, int y1, int x2, int y2) {
    double lenght = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    lenght = sqrt(lenght);
    return lenght;
}

void maxDistantaProblema4(int x[100][100], int n, int& punct1, int& punct2, double& maxLenght) {
    maxLenght = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = x[i][0], y1 = x[i][1];
            int x2 = x[j][0], y2 = x[j][1];
            double lenght = distantaDouaPuncte(x1, y1, x2, y2);
            if (lenght > maxLenght) {
                maxLenght = lenght;
                punct1 = i;
                punct2 = j;
            }
        }
    }
}

void afisareProblema4(int x[100][100], int punct1, int punct2, double maxLenght) {
    cout << "Punctele sunt :\n";
    cout << "(" << x[punct1][0] << ", " << x[punct1][1] << ") si (" << x[punct2][0] << ", " << x[punct2][1] << ")\n";
    cout << "\nDistanta este :\n";
    cout << maxLenght << endl;
}

void problema4() {
    int x[100][100], n;
    citireProblema4(x, n);

    int punct1, punct2;
    double maxLenght;
    maxDistantaProblema4(x, n, punct1, punct2, maxLenght);
    afisareProblema4(x, punct1, punct2, maxLenght);
}

// Problema 5
// Se da un vector de n numere intregi.
// Sa se tipareasca primele 3 cele mai mari numere negative si
// primele 3 cele mai mici numere pozitive. Vectorul nu poate fi
// modificat (nici sortat).

void citireProblema5(int x[], int& n) {
    ifstream f("input.txt");
    n = 0;
    while (!f.eof()) {
        f >> x[n];
        n++;
    }
    f.close();
}

int countMaiMiciPozitiveProblema5(int x[], int n, int numar) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] < numar && x[i] >= 0) {
            c++;
        }
    }
    return c;
}

int countMaiMariNegativeProblema5(int x[], int n, int numar) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > numar && x[i] < 0) {
            c++;
        }
    }
    return c;
}

void creareVectorProblema5(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] < 0) {
            y[i] = countMaiMariNegativeProblema5(x, n, x[i]);
        }
        else {
            y[i] = countMaiMiciPozitiveProblema5(x, n, x[i]);
        }
    }
}

void afisareProblema5(int x[], int y[], int n) {
    cout << "Primele 3 cele mai mari numere negative sunt :\n";
    for (int i = 0, j = 0; i < n && j < 3; i++) {
        if (x[i] < 0 && y[i] < 3) {
            cout << x[i] << " ";
            j++;
        }
    }
    cout << "\n\nPrimele 3 cele mai mici numere pozitive sunt :\n";
    for (int i = 0, j = 0; i < n && j < 3; i++) {
        if (x[i] > 0 && y[i] < 3) {
            cout << x[i] << " ";
            j++;
        }
    }
}

void problema5() {
    int x[100], n;
    citireProblema5(x, n);

    int y[100];
    creareVectorProblema5(x, y, n);
    afisareProblema5(x, y, n);
}