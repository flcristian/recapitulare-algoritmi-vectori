#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Problema 25
// Sa se scrie un program care calculeaza suma si
// produsul a doua palindroame.

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