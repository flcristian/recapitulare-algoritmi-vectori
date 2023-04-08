#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Problema 16
// Afisati pentru un sir de n elemente
// numarul de aparitii al fiecarei valori.

void citireProblema16(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void sentinelBubbleSortProblema16(int numere[], int frecventa[], int d) {
	int i = 0;
	bool flag = true;
	while (flag&& i < d) {
		flag = false;
		for (int j = d - 1; j > i; j--) {
			if (frecventa[j - 1] < frecventa[j]) {
				int rf = frecventa[j - 1];
				int rn = numere[j - 1];
				frecventa[j - 1] = frecventa[j];
				numere[j - 1] = numere[j];
				frecventa[j] = rf;
				numere[j] = rn;
				flag = true;
			}
		}
		i++;
	}
}

void frecventaProblema16(int x[], int f[], int numere[], int frecventa[], int n, int& d) {
	for (int i = 0; i < n; i++) {
		f[x[i]]++;
	}

	d = 0;
	for (int i = 0; i < 100; i++) {
		if (f[i] > 0) {
			numere[d] = i;
			frecventa[d] = f[i];
			d++;
		}
	}

	sentinelBubbleSortProblema16(numere, frecventa, d);
}

void afisareFrecventaProblema16(int numere[], int frecventa[], int d) {
	for (int i = 0; i < d; i++) {
		cout << numere[i] << " " << frecventa[i] << endl;
	}
}

void problema16() {
	int x[100], n;
	citireProblema16(x, n);
	int f[100]{};
	int numere[100], frecventa[100], d;
	frecventaProblema16(x, f, numere, frecventa, n, d);
	afisareFrecventaProblema16(numere, frecventa, d);
}

// Problema 17
// Determianti suma maxima care se poate forma cu m numere distincte
// dintr-un vector ce conmtine n valori intregi.
// Daca contine mai putin de m valori, se va afisa mesajul imposibil.

// <=> Fisier citire <=>
// Primul rand : numarul m
// Al doilea rand : elementele vectorului x

void citireProblema17(int x[], int& n, int& m) {
	ifstream f("input.txt");
	f >> m;
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool validProblema17(int s[], int k) {
	for (int i = 0; i < k; i++) {
		if (s[k] == s[i]) {
			return 0;
		}
	}
	return 1;
}

bool solutieProblema17(int k, int m) {
	if (k == m - 1) {
		return 1;
	}
	return 0;
}

void modificareProblema17(int s[], int m, int& max) {
	int suma = 0;
	for (int i = 0; i < m; i++) {
		suma += s[i];
	}
	if (suma > max) {
		max = suma;
	}
}

void backProblema17(int x[], int s[], int n, int m, int k, int& max) {
	for (int i = 0; i < n; i++) {
		s[k] = x[i];
		if (validProblema17(s, k)) {
			if (solutieProblema17(k, m)) {
				modificareProblema17(s, m, max);
			}
			else {
				backProblema17(x, s, n, m, k + 1, max);
			}
		}
	}
}

void problema17() {
	int x[100], n, m;
	citireProblema17(x, n, m);

	if (m > n) {
		cout << "Imposibil" << endl;
	}
	else {
		int max = -999999;
		int s[100];
		backProblema17(x, s, n, m, 0, max);
		cout << max << endl;
	}
}

// Problema 18
// Sa se scrie un program care afiseaza permutarile circulare ale unui
// vector cu n elemente intregi. O permutare circulara se obtine prin
// rotirea elementelor vectorului cu i pozitii (i<n).

void citireProblema18(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void afisarePermutareProblema18(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void permutareProblema18(int x[], int n) {
	int r = x[0];
	for (int i = 0; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	x[n - 1] = r;
}

void rezolvareProblema18(int x[], int n) {
	for (int i = 0; i < n - 1; i++) {
		permutareProblema18(x, n);
		afisarePermutareProblema18(x, n);
	}
}

void problema18() {
	int x[100], n;
	citireProblema18(x, n);
	rezolvareProblema18(x, n);
}

// Problema 19
// Se considera un vector ce contine n numere reale.
// Vom spune ca doua elemente ale sale, formeaza o
// "pereche in dezordine" daca sunt indeplinite simultan
// conditiile :
// - i < j
// - x[i] > x[j], unde (i <= i < n) si (1 < j <= n)
// Sa se afiseze aceste perechi si numarul lor.

void citireProblema19(double x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void perechiInDezordineProblema19(double x[], int n) {
	int c = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] > x[j]) {
				cout << x[i] << " " << x[j] << endl;
				c++;
			}
		}
	}
	cout << c << endl;
}

void problema19() {
	double x[100];
	int n;
	citireProblema19(x, n);
	perechiInDezordineProblema19(x, n);
}

// Problema 20
// Afisati cifrele distincte ale unui numar in ordine
// crescatoare a numarului lor de aparitii.

void sentinelBubbleSortProblema20(int cifre[], int frecventa[], int d) {
	int i = 0;
	bool flag = true;
	while (flag && i < d) {
		flag = false;
		for (int j = d - 1; j > i; j--) {
			if (frecventa[j - 1] > frecventa[j]) {
				int rf = frecventa[j - 1];
				int rc = cifre[j - 1];
				frecventa[j - 1] = frecventa[j];
				cifre[j - 1] = cifre[j];
				frecventa[j] = rf;
				cifre[j] = rc;
				flag = true;
			}
		}
		i++;
	}
}

void frecventaCifreProblema20(int n, int f[], int cifre[], int frecventa[], int& d) {
	while (n > 0) {
		f[n % 10]++;
		n /= 10;
	}

	d = 0;
	for (int i = 0; i < 10; i++) {
		if (f[i] > 0) {
			cifre[d] = i;
			frecventa[d] = f[i];
			d++;
		}
	}

	sentinelBubbleSortProblema20(cifre, frecventa, d);
}

void afisareFrecventaCifreProblema20(int cifre[], int d) {
	for (int i = 0; i < d; i++) {
		cout << cifre[i] << " ";
	}
	cout << endl;
}

void problema20() {
	int n;
	cout << "Introduceit n : ";
	cin >> n;
	int f[10]{};
	int cifre[100], frecventa[100], d;
	frecventaCifreProblema20(n, f, cifre, frecventa, d);
	afisareFrecventaCifreProblema20(cifre, d);
}

// Problema 21
// Sa se ordoneze elementele pare, fara insa a afecta pozitiile pe care
// sunt situate numerele impare.

void citireProblema21(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void sentinelBubbleSortProblema21(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] % 2 == 0 && x[j] % 2 == 0) {
				if (x[j - 1] > x[j]) {
					int r = x[j - 1];
					x[j - 1] = x[j];
					x[j] = r;
					flag = true;
				}
			}
		}
		i++;
	}
}

void rezolvareProblema21(int x[], int n) {
	int d = 0;
	int pare[100], indici[100];
	for (int i = 0; i < n; i++) {
		if (x[i] % 2 == 0) {
			pare[d] = x[i];
			indici[d] = i;
			d++;
		}
	}

	sentinelBubbleSortProblema21(pare, d);
	
	for (int i = 0, j = 0; i < n; i++) {
		if (i == indici[j]) {
			x[i] = pare[j];
			j++;
		}
	}
}

void afisareProblema21(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema21() {
	int x[100], n;
	citireProblema21(x, n);
	rezolvareProblema21(x, n);
	afisareProblema21(x, n);
}

// Problema 22
// Se considera un vector de caractere.
// Sa se afiseze perechea de doa elementele egal departate
// de centru, a caror suma a codurilor ASCII este maxima.

void citireProblema22(char x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareProblema22(char x[], int n, char max[]) {
	int sMax = 0;
	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		if (x[i] + x[j] > sMax) {
			sMax = x[i] + x[j];
			max[0] = x[i];
			max[1] = x[j];
		}
	}
}

void problema22() {
	char x[100];
	int n;
	citireProblema22(x, n);
	n--;

	char max[10];
	rezolvareProblema22(x, n, max);
	cout << max[0] << " " << max[1] << endl;
}

// Problema 23
// Sa se sorteze elementele dintre elementul maxim si
// cel minim al vectorului.

void citireProblema23(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void sentinelBubbleSortProblema23(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] > x[j]) {
				int r = x[j - 1];
				x[j - 1] = x[j];
				x[j] = r;
				flag = true;
			}
		}
		i++;
	}
}

void pozitieMaximSiMaxim(int x[], int n, int& iMax, int& iMin) {
	int max = x[0], min = x[0];
	iMax = 0, iMin = 0;

	for (int i = 0; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
			iMax = i;
		}
		if (x[i] < min) {
			min = x[i];
			iMin = i;
		}
	}
}

void rezolvareProblema23(int x[], int n) {
	int iMax, iMin;
	pozitieMaximSiMaxim(x, n, iMax, iMin);
	if (iMax == iMin) {
		cout << "Nu se efectueaza sortatea." << endl;
	}
	else {
		int a = iMax, b = iMin;
		if (a > b) {
			int r = a;
			a = b;
			b = r;
		}

		int numere[100], d = 0;
		for (int i = a + 1; i < b; i++) {
			numere[d] = x[i];
			d++;
		}

		sentinelBubbleSortProblema23(numere, d);

		for (int i = a + 1, j = 0; j < d; i++, j++) {
			x[i] = numere[j];
		}
	}
}

void afisareProblema23(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema23() {
	int x[100], n;
	citireProblema23(x, n);
	rezolvareProblema23(x, n);
	afisareProblema23(x, n);
}

// Problema 24
// Se da un vector de 2*n numere reale.
// Sa se afiseze n numere reale obtinute
// prin adunmarea partilor intregi cu partile
// fractionare a elementelor egal departate de centru.

void citireProblema24(double x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void rezolvareProblema24(double x[], int n) {
	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		double s = floor(x[i]);
		if (s < 0) {
			s *= -1;
		}

		double z;
		if (x[j] >= 0) {
			z = x[j] - floor(x[j]);
		}
		else {
			z = x[j] - ceil(x[j]);
		}
		
		if (z < 0) {
			z *= -1;
		}
		s = s + z;
		cout << s << " ";
	}
	cout << endl;
}

void problema24() {
	double x[100];
	int n;
	citireProblema24(x, n);
	rezolvareProblema24(x, n);
}

// Problema 25
// Reuniunea, intersectia, diferenta unor vectori.

// <=> Fisier citire <=>
// Primul rand : doua valori separate printr-un spatiu
// (numarul de elemente din primul vector, respectiv celui de-al doilea)
// Al doilea rand : valorile primului vector
// Al treilea rand : valorile celui de-al doilea vector

void citireProblema25(int x[], int y[], int& n, int& m) {
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

void sentinelBubbleSortProblema25(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] > x[j]) {
				int r = x[j - 1];
				x[j - 1] = x[j];
				x[j] = r;
				flag = true;
			}
		}
		i++;
	}
}

void copiereVectoriProblema25(int x[], int tempA[], int n) {
	for (int i = 0; i < n; i++) {
		tempA[i] = x[i];
	}
}

bool apartineProblema25(int x[], int n, int numar) {
	for (int i = 0; i < n; i++) {
		if (x[i] == numar) {
			return 1;
		}
	}
	return 0;
}

void reuniuneaVectorilorProblema25(int x[], int y[], int n, int m) {
	int tempA[100];
	copiereVectoriProblema25(x, tempA, n);

	for (int i = 0; i < m; i++) {
		if (!apartineProblema25(tempA, n, y[i])) {
			tempA[n] = y[i];
			n++;
		}
	}
	cout << "Reuniunea :\n";
	for (int i = 0; i < n; i++) {
		cout << tempA[i] << " ";
	}
	cout << endl;
}

void intersectiaVectorilorProblema25(int x[], int y[], int n, int m) {
	int z[100], d = 0;
	for (int i = 0; i < m; i++) {
		if (apartineProblema25(x, n, y[i])) {
			z[d] = y[i];
			d++;
		}
	}

	cout << "\nIntersectia :\n";
	for (int i = 0; i < d; i++) {
		cout << z[i] << " ";
	}
	cout << endl;
}

void eliminarePozitieProblema25(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void diferentaVectorilorProblema25(int x[], int y[], int n, int m) {
	int tempA[100], d;
	copiereVectoriProblema25(x, tempA, n);
	d = n;

}

void problema25() {
	int x[100], y[100], n, m;
	citireProblema25(x, y, n, m);
	reuniuneaVectorilorProblema25(x, y, n, m);
	intersectiaVectorilorProblema25(x, y, n, m);
	diferentaVectorilorProblema25(x, y, n, m);
}