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

void copiereVectoriProblema25(int x[], int tempA[], int n) {
	for (int i = 0; i < n; i++) {
		tempA[i] = x[i];
	}
}

int apartineProblema25(int x[], int n, int numar) {
	for (int i = 0; i < n; i++) {
		if (x[i] == numar) {
			return i;
		}
	}
	return -1;
}

void reuniuneaVectorilorProblema25(int x[], int y[], int n, int m) {
	int tempA[100];
	copiereVectoriProblema25(x, tempA, n);

	for (int i = 0; i < m; i++) {
		if (apartineProblema25(tempA, n, y[i]) == -1) {
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
		if (apartineProblema25(x, n, y[i]) != -1) {
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
	for (int i = 0; i < m; i++) {
		int k = apartineProblema25(tempA, d, y[i]);
		if (k != -1) {
			eliminarePozitieProblema25(tempA, d, k);
		}
	}

	cout << "\nDiferenta :\n";
	for (int i = 0; i < d; i++) {
		cout << tempA[i] << " ";
	}
	cout << endl;
}

void problema25() {
	int x[100], y[100], n, m;
	citireProblema25(x, y, n, m);
	reuniuneaVectorilorProblema25(x, y, n, m);
	intersectiaVectorilorProblema25(x, y, n, m);
	diferentaVectorilorProblema25(x, y, n, m);
}

// Problema 26
// Fie un tablou unidimensional ce contine n numere naturale si un singur
// element nul.
// Sa se sorteze vectorul (orice intershcimbare trebuie efectuata
// prin itermediul elementului nul).

void citireProblema26(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int pozitieElementNulProblema26(int x[], int n) {
	for (int i = 0; i < n; i++) {
		if (x[i] == 0) {
			return i;
		}
	}
	return -1;
}

void afisareProblema26(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void sentinelBubbleSortProblema26(int x[], int n, int& pos0) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j - 1] < x[j]) {
				if (x[j - 1] == 0) {
					x[j - 1] = x[j];
					x[j] = 0;
					pos0 = j;
				}
				else if (x[j] == 0) {
					x[j] = x[j - 1];
					x[j - 1] = 0;
					pos0 = j - 1;
				}
				else {
					x[pos0] = x[j - 1];
					x[j - 1] = 0;

					x[j - 1] = x[j];
					x[j] = 0;

					x[j] = x[pos0];
					x[pos0] = 0;
				}
				flag = true;
			}
		}
		i++;
	}
}

void problema26() {
	int x[100], n;
	citireProblema26(x, n);
	int nul = pozitieElementNulProblema26(x, n);
	sentinelBubbleSortProblema26(x, n, nul);
	afisareProblema26(x, n);
}

// Problema 27
// Sa se determine daca vectorul y contine toate elementele
// vectorului x, pe pozitii consecutive si sa se afiseze indicele
// primului element in vectorul y.
// Exemplu : y = [1 2 (3 4 2) 8 1] ; x = [ 2 3 4 ] => 3

// <=> Fisier citire <=>
// Primul rand : doua valori separate printr-un spatiu
// (numarul de elemente din primul vector, respectiv celui de-al doilea)
// Al doilea rand : valorile primului vector
// Al treilea rand : valorile celui de-al doilea vector

void citireProblema27(int x[], int y[], int& n, int& m) {
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

int pozitieElementProblema27(int x[], int n, int numar) {
	for (int i = 0; i < n; i++) {
		if (x[i] == numar) {
			return i;
		}
	}
	return -1;
}

void eliminarePozitieProblema27(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

void copiereVectorProblema27(int x[], int temp[], int n, int& d) {
	for (int i = 0; i < n; i++) {
		temp[i] = x[i];
	}
	d = n;
}

int rezolvareProblema27(int x[], int y[], int n, int m) {
	int temp[100], d;
	copiereVectorProblema27(x, temp, n, d);

	int count = 0, r = -1;
	for (int i = 0; i < m; i++) {
		int k = pozitieElementProblema27(temp, d, y[i]);
		if (k != -1) {
			if (r == -1) {
				r = i + 1;
			}
			count++;
			eliminarePozitieProblema27(temp, d, k);
			if (count == n) {
				return r;
			}
		}
		else {
			copiereVectorProblema27(x, temp, n, d);
			count = 0;
			r = -1;
		}
	}
}

void problema27() {
	int x[100], y[100], n, m;
	citireProblema27(x, y, n, m);
	cout << rezolvareProblema27(x, y, n, m);
}

// Problema 28
// A0 = 1 ; Daca x apartine sirului => si 2x+1, 3x+1 apartin
// Exemplu : n = 6 : 1 3 4 7 10 9
// Elementele nu trebuie sa fie neaparat distincte!

void creareSirProblema29(int x[], int n) {
	x[0] = 1;
	int i = 1;
	while (i < n) {
		int k = (i - 1) / 2;
		if (i % 2 == 1) {
			x[i] = 2 * x[i - k - 1] + 1;
		}
		else {
			x[i] = 3 * x[i - k - 2] + 1;
		}
		i++;
	}
}

void afisareProblema28(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema28() {
	int x[1000], n;
	cout << "Introduceti n : ";
	cin >> n;
	creareSirProblema29(x, n);
	afisareProblema28(x, n);
}

// Problema 29
// Sa se determine daca un numar este de tip munte.

bool esteTipMunteProblema29(int n) {
	int last = 0;
	bool lower = false;
	while (n > 0) {
		int c = n % 10;
		if (c > last) {
			if (lower) {
				return 0;
			}
		}
		else {
			lower = true;
		}
		last = c;
		n /= 10;
	}
	return 1;
}

void afisareProblema29(bool flag) {
	cout << "Numarul ";
	if (flag) {
		cout << "este";
	}
	else {
		cout << "nu este";
	}
	cout << " de tip munte." << endl;
}

void problema29() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	bool flag = esteTipMunteProblema29(n);
	afisareProblema29(flag);
}

// Problema 30
// Se considera un tablou unidimensional cu n elemente ce
// reprezinta o permutare a multimii 1..n. Asupra elementelor se vor
// face urmatoarele tipuri de mutari: in ordine de la 1 la n, fiecare
// element a[i] se va schimba cu elementul de pe pozitia i + a[i].
// Daca aceasta pozitie este mai mare decat n, atunci numerotarea se continua
// pe pozitia 1. Sa se afiseze continutul vectorului la finalul operatiilor.

void citireProblema30(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void modificareProblema30(int x[], int n) {
	for (int i = 0; i < n; i++) {
		int r = x[i];
		int pos = i + x[i] + 1;
		if (pos % n != 0) {
			pos = pos % n;
		}
		pos--;
		x[i] = x[pos];
		x[pos] = r;
	}
}

void afisareProblema30(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema30() {
	int x[100], n;
	citireProblema30(x, n);
	modificareProblema30(x, n);
	afisareProblema30(x, n);
}

// Problema 31
// Sa se stearga dintr-un vector, un numar de elemente,
// astfel incat la final sa se obtina un sir strict crescator.
// Primul element din vectorul initial nu se va sterge.

void citireProblema31(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void eliminarePozitieProblema31(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i ++) {
		x[i] = x[i + 1];
	}
	n--;
}

void stergereProblema31(int x[], int& n) {
	for (int i = 1; i < n; i++) {
		if (x[i] < x[i - 1]) {
			eliminarePozitieProblema31(x, n, i);
			i--;
		}
	}
}

void afisareProblema31(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema31() {
	int x[100], n;
	citireProblema31(x, n);
	stergereProblema31(x, n);
	afisareProblema31(x, n);
}

// Problema 32
// Sa se afiseze pe linii, elementele unui vector dupa
// cifra dominanta (prima in scrierea zecimala). Pe aceeasi
// linie vor fi scrise elementele cu aceeasi cifra dominanta.

struct Linie {
	int cifra;
	int x[100];
	int n = 0;
};

void citireProblema32(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

int cifraDominantaProblema32(int n) {
	while (n / 10 > 0) {
		n /= 10;
	}
	return n;
}

int pozitieCifraProblema32(int c, Linie linii[], int m) {
	for (int i = 0; i < m; i++) {
		if (linii[i].cifra == c) {
			return i;
		}
	}
	return -1;
}

void formareLiniiProblema32(int x[], int n, Linie linii[], int& m) {
	for (int i = 0; i < n; i++) {
		int c = cifraDominantaProblema32(x[i]);
		int p = pozitieCifraProblema32(c, linii, m);
		if (p != -1) {
			linii[p].x[linii[p].n] = x[i];
			linii[p].n = linii[p].n + 1;
		}
		else {
			linii[m].cifra = c;
			linii[m].x[linii[m].n] = x[i];
			linii[m].n = linii[m].n + 1;
			m++;
		}
	}
}

void sortareLiniiProblema32(Linie linii[], int m) {
	int i = 0;
	bool flag = true;
	while (flag && i < m) {
		flag = false;
		for (int j = m - 1; j > i; j--) {
			if (linii[j].cifra < linii[j - 1].cifra) {
				Linie r = linii[j];
				linii[j] = linii[j - 1];
				linii[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

void afisareLiniiProblema32(Linie linii[], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < linii[i].n; j++) {
			cout << linii[i].x[j] << " ";
		}
		cout << endl;
	}
}

void problema32() {
	int x[100], n;
	citireProblema32(x, n);

	Linie linii[100];
	int m = 0;
	formareLiniiProblema32(x, n, linii, m);
	sortareLiniiProblema32(linii, m);
	afisareLiniiProblema32(linii, m);
}

// Problema 33
// Sa se sorteze un tablou unidimensional descrescator
// in functie de numarul de cifre distincte al elementelor.

void citireProblema33(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

bool apareNumarul(int x[], int m, int c) {
	for (int i = 0; i < m; i++) {
		if (x[i] == c) {
			return 1;
		}
	}
	return 0;
}

int countCifreDistincteProblema33(int n) {
	int count = 0;
	int x[100], m = 0;
	while (n > 0) {
		int c = n % 10;
		if (!apareNumarul(x, m, c)) {
			count++;
			x[m] = c;
			m++;
		}
		n /= 10;
	}
	return count;
}

void sortareProblema33(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			int c1 = countCifreDistincteProblema33(x[j]);
			int c2 = countCifreDistincteProblema33(x[j - 1]);
			if (c1 > c2) {
				int r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

void afisareProblema33(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema33() {
	int x[100], n;
	citireProblema33(x, n);
	sortareProblema33(x, n);
	afisareProblema33(x, n);
}

// Problema 34
// Sa se ordoneze crescator un vector de numere reale dupa
// partea intreaga a lor, iar daca partea intreaga este egala,
// descrescator dupa cea fractionara.

void citireProblema34(double x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void sortareProblema34(double x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			int intreaga1 = x[j];
			int intreaga2 = x[j - 1];
			double fractionara1 = abs(x[j] - intreaga1);
			double fractionara2 = abs(x[j - 1] - intreaga2);
			if (intreaga1 < intreaga2) {
				double r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
			else if (intreaga1 == intreaga2) {
				if (fractionara1 > fractionara2) {
					double r = x[j];
					x[j] = x[j - 1];
					x[j - 1] = r;
					flag = true;
				}
			}
		}
		i++;
	}
}

void afisareProblema34(double x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema34() {
	double x[100];
	int n;
	citireProblema34(x, n);
	sortareProblema34(x, n);
	afisareProblema34(x, n);
}

// Problema 35
// Creati cu valorile unui tablou unidimensional
// de 2*n elemente un sir de fractii a caror suma
// este maxima. Fiecare fractie se va afisa pe cate
// o linie printr-o pereche de numere (numarator-numitor).

void citireProblema35(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void eliminarePozitieProblema35(int x[], int& n, int k) {
	for (int i = k; i < n - 1; i++) {
		x[i] = x[i + 1];
	}
	n--;
}

int posMaxProblema35(int x[], int n) {
	int max = x[0], p = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] > max) {
			max = x[i];
			p = i;
		}
	}
	return p;
}

int posMinProblema35(int x[], int n) {
	int min = x[0], p = 0;
	for (int i = 1; i < n; i++) {
		if (x[i] < min) {
			min = x[i];
			p = i;
		}
	}
	return p;
}

void rezolvareProblema35(int x[], int n) {
	while (n > 0) {
		int pMax = posMaxProblema35(x, n);
		int pMin = posMinProblema35(x, n);
		cout << x[pMax] << " " << x[pMin] << endl;
		eliminarePozitieProblema35(x, n, pMax);
		eliminarePozitieProblema35(x, n, pMin);
	}
}

void problema35() {
	int x[100], n;
	citireProblema35(x, n);
	rezolvareProblema35(x, n);
}