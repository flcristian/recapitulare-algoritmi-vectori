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
	int max = x[0], maxStart = 0, maxEnd = 0;
	int suma = 0, newStart = 0;
	for (int i = 0; i < n; i++) {
		suma += x[i];
		if (suma < 0) {
			if (suma - x[i] > max) {
				max = suma - x[i];
				maxStart = newStart;
				maxEnd = i;
			}
			suma = 0;
			newStart = i + 1;
		}
	}
	start = maxStart;
	lenght = maxEnd - maxStart;
}

void rezolvare() {
	citire();
	secventa();
	cout << start << " " << lenght << endl;
}