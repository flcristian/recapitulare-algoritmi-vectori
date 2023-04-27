#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Problema 25
// Sa se scrie un program care calculeaza suma si
// produsul a doua palindroame.

// <=> Fisier Citire <=>
// Primul rand : doua numere naturale (gradele polinoamelor)
// Al doilea rand : coeficientii primului polinom
// Al treilea rand : coeficientii celui de-al doilea polinom

struct ElementPolinom {
	int coeficient = 0;
	int putere = 0;
};

struct Polinom {
	int grad = -1;
	ElementPolinom X[100];

	char litera[10] = "";
	void afisare() {
		cout << litera << "(x) = ";
		for (int i = 0; i < grad + 1; i++) {
			if (X[i].coeficient != 0) {
				if (X[i].coeficient < 0) {
					cout << "- ";
				}
				else if (i != 0) {
					cout << "+ ";
				} 
				if (abs(X[i].coeficient) != 1 || X[i].putere == 0) {
					cout << abs(X[i].coeficient);
				}
				if (i < grad - 1) {
					cout << "X^" << X[i].putere << " ";
				}
				else if (i == grad - 1) {
					cout << "X ";
				}
			}
		}
		cout << endl;
	}
};

void citireProblema25(Polinom& P, Polinom& Q) {
	ifstream f("input.txt");
	f >> P.grad >> Q.grad;
	for (int i = 0; i < P.grad + 1; i++) {
		f >> P.X[i].coeficient;
		P.X[i].putere = P.grad - i;
	}
	for (int i = 0; i < Q.grad + 1; i++) {
		f >> Q.X[i].coeficient;
		Q.X[i].putere = Q.grad - i;
	}
	f.close();
}

int maxProblema25(int n, int m) {
	if (n > m) {
		return n;
	}
	return m;	
}

void sumaPolinoame(Polinom A, Polinom B) {
	Polinom R;
	strcpy(R.litera, "Suma");
	R.grad = maxProblema25(A.grad, B.grad);
	for (int i = 0; i < R.grad + 1; i++) {
		R.X[i].putere = R.grad - i;
	}
	for (int i = 0; i < A.grad + 1; i++) {
		R.X[R.grad - A.X[i].putere].coeficient += A.X[i].coeficient;
	}
	for (int i = 0; i < B.grad + 1; i++) {
		R.X[R.grad - B.X[i].putere].coeficient += B.X[i].coeficient;
	}
	R.afisare();
}

void produsPolinoame(Polinom A, Polinom B) {
	Polinom R;
	strcpy(R.litera, "Produs");
	R.grad = A.grad + B.grad;
	for (int i = 0; i < R.grad + 1; i++) {
		R.X[i].putere = R.grad - i;
	}
	for (int i = 0; i < A.grad + 1; i++) {
		for (int j = 0; j < B.grad + 1; j++) {
			int k = A.X[i].putere + B.X[j].putere;
			int p = A.X[i].coeficient * B.X[j].coeficient;
			R.X[R.grad - k].coeficient += p;
		}
	}
	R.afisare();
}

void problema25() {
	Polinom P, Q;
	citireProblema25(P, Q);
	P.litera[0] = 'P', Q.litera[0] = 'Q';
	
	// Afisarea polinomelor

	P.afisare();
	Q.afisare();

	cout << endl;

	// Suma si produsul polinoamelor.
	
	sumaPolinoame(P, Q);

	produsPolinoame(P, Q);
}

// Problema 27
// Se dau doua multimi.
// Sa se determine intersectia si reuniunea acestora, iar
// apoi sa se compare eficienta implementarilor celor doua
// operatii cu cele doua reprezentari.

// <=> Fisier Citire <=>
// Primul rand : doua numere naturale (dimensiunea vectorilor)
// Al doilea rand : elementele primului vector
// Al treilea rand : elementele celui de-al doilea vector

void citireProblema27(int a[], int b[], int& n, int& m){
	ifstream f("input.txt");
	f >> n >> m;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}
	f.close();
}

void sortareVector(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			if (x[j] < x[j - 1]) {
				int r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

void intersectiaPrinMultime(int a[], int b[], int x[], int n, int m, int& d) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			x[k] = a[i];
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	d = k;
}

void intersectiaPrinFrecventa(int fa[], int fb[], int f[]) {
	for (int i = 0; i < 100; i++) {
		if (fa[i] > 0 && fb[i] > 0) {
			f[i]++;
		}
	}
}

void reuniuneaPrinMultime(int a[], int b[], int x[], int n, int m, int& d) {
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] == b[j]) {
			x[k] = a[i];
			i++;
			j++;
			k++;
		}
		else if (a[i] < b[j]) {
			x[k] = a[i];
			i++;
			k++;
		}
		else {
			x[k] = b[j];
			j++;
			k++;
		}
	}
	while (i < n) {
		x[k] = a[i];
		i++;
		k++;
	}
	while (j < m) {
		x[k] = b[j];
		j++;
		k++;
	}
	d = k;
}

void reuniuneaPrinFrecventa(int fa[], int fb[], int f[]) {
	for (int i = 0; i < 100; i++) {
		if (fa[i] > 0 || fb[i] > 0) {
			f[i]++;
		}
	}
}

void afisareVectorMultime(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void afisareVectorFrecventa(int f[]) {
	for (int i = 0; i < 100; i++) {
		if (f[i] != 0) {
			cout << i << " ";
		}
	}
	cout << endl;
}

void frecventaVector(int x[], int f[], int n) {
	for (int i = 0; i < n; i++) {
		f[x[i]]++;
	}
}

void problema27() {
	int a[100], b[100], n, m;
	citireProblema27(a, b, n, m);
	sortareVector(a, n);
	sortareVector(b, m);

	int fa[100]{}, fb[100]{};
	frecventaVector(a, fa, n);
	frecventaVector(b, fb, m);

	// Afisare multimi.
	cout << "A = ";
	afisareVectorMultime(a, n);
	cout << "B = ";
	afisareVectorMultime(b, m);

	// - - - - - - //
	// Intersectia : 
	int i[100], fi[100]{}, di;
	cout << "\nIntersectia :" << endl;
		
	// Prin multime.
	intersectiaPrinMultime(a, b, i, n, m, di);
	cout << "Prin multime = ";
	afisareVectorMultime(i, di);

	// Prin frecventa.
	intersectiaPrinFrecventa(fa, fb, fi);
	cout << "Prin frecventa = ";
	afisareVectorFrecventa(fi);

	// - - - - - - //
	// Reuniunea :
	int r[100], fr[100]{}, dr;
	cout << "\nReuniunea :" << endl;

	// Prin multime.
	reuniuneaPrinMultime(a, b, r, n, m, dr);
	cout << "Prin multime = ";
	afisareVectorMultime(r, dr);

	// Prin frecventa.
	reuniuneaPrinFrecventa(fa, fb, fi);
	cout << "Prin frecventa = ";
	afisareVectorFrecventa(fi);
}

// Problema 28
// Se da un numar natural nenul. Scrieti un program
// care sa determine si sa contorizeze toate modalitatile de a scrie
// numarul ca suma de minim doua numere intregi consecutive.

struct Suma {
	int x[100];
	int n = 0;
};

void creareMultimeProblema28(int x[], int n, int& d) {
	d = 0;
	for (int i = 0 - n + 1; i < n + 1; i++) {
		x[d] = i;
		d++;
	}
}

void adaugareSuma(Suma sume[], int& m, int s, int d) {
	for (int i = s; i <= d; i++) {
		sume[m].x[sume[m].n] = i;
		sume[m].n++;
	}
	m++;
}

void aflareSume(Suma sume[], int x[], int d, int& m, int n) {
	m = 0;
	for (int i = 0; i < d - 1; i++) {
		int suma = 0;
		for (int j = i; j < d; j++) {
			suma += x[j];
			if (suma == n) {
				adaugareSuma(sume, m, x[i], x[j]);
			}
		}
	}
}

void afisareSume(Suma sume[], int m) {
	cout << "S-au format " << m << " sume." << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < sume[i].n; j++) {
			cout << sume[i].x[j] << " ";
		}
		cout << endl;
	}
}

void problema28() {
	int n;
	cout << "Introduceti n : ";
	cin >> n;

	int x[100], d;
	creareMultimeProblema28(x, n, d);

	Suma sume[100];
	int m;
	aflareSume(sume, x, d, m, n);
	afisareSume(sume, m);
}

// Problema 29
// Sa se afiseze sirul de lungime maxima 
// de tip Zig-Zag care se poate genera cu 
// elementele sirului citit.
// Zig-Zag = a1 <= a2 >= a3 <= a4 >= a5

void citireProblema29(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void afisareProblema29(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void sortareZigZag(int x[], int n) {
	int i = 0;
	bool flag = true;
	while (flag && i < n) {
		flag = false;
		for (int j = n - 1; j > i; j--) {
			bool k(x[j] > x[j - 1]);
			if ((int)k != j % 2) {
				int r = x[j];
				x[j] = x[j - 1];
				x[j - 1] = r;
				flag = true;
			}
		}
		i++;
	}
}

void problema29() {
	int x[100], n;
	citireProblema29(x, n);
	sortareZigZag(x, n);
	afisareProblema29(x, n);
}