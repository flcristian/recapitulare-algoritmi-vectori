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
			if (X[i].coeficient < 0) {
				cout << "- ";
			}
			else {
				if (i != 0) {
					cout << "+ ";
				}
			}
			cout << abs(X[i].coeficient);
			if (i < grad - 1) {
				cout << "X^" << X[i].putere << " ";
			}
			if (i == grad - 1) {
				cout << "X ";
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

void sumaPolinoame(Polinom A, Polinom B, Polinom& R) {
	R.grad = maxProblema25(A.grad, B.grad);
	for (int i = 0; i < R.grad + 1; i++) {
		R.X[i].putere = R.grad - i;
	}
	for (int i = 0; i < A.grad + 1; i++) {
		R.X[A.X[i].putere].coeficient += A.X[i].coeficient;
	}
	for (int i = 0; i < B.grad + 1; i++) {
		R.X[B.X[i].putere].coeficient += B.X[i].coeficient;
	}
}

void produsPolinoame(Polinom A, Polinom B, Polinom& R) {
	R.grad = A.grad + B.grad;
}

void problema25() {
	Polinom P, Q;
	citireProblema25(P, Q);
	P.litera[0] = 'P', Q.litera[0] = 'Q';
	
	// Suma polinoamelor.

	Polinom Suma;
	strcpy(Suma.litera, "Suma");
	sumaPolinoame(P, Q, Suma);
	Suma.afisare();

	// Produsul polinoamelor.

	Polinom Produs;
	strcpy(Produs.litera, "Produs");
	produsPolinoame(P, Q, Produs);
	Produs.afisare();
}