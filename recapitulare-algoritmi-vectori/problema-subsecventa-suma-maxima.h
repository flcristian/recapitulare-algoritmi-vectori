#include <iostream>
#include <fstream>

using namespace std;

// Sa se determine subsecventa cu suma maxima de numere consecutive
// dintr-un vector citit.

int x[100]; // Vectorul.
int n; // Numarul de elemente;

// Subsecventa.

int start; // Pozitia de inceput.
int lenght; // Lungimea subsecventei;

void citire() {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void secventa() {
	int max = x[0];
	for (int i = 0; i < n; i++) {
		int s = 0, j = i;
		while (j < n) {
			s += x[j];
			if (s > max) {
				max = s;
				start = i;
				lenght = j - i + 1;
			}
			j++;
		}
	}
}

void rezolvare() {
	citire();
	secventa();
	cout << start << " " << lenght << endl;
}

// De continuat ^ ^ ^