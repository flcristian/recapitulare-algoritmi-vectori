#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Problema 1
// Se dau doi vectori. Primul contine nume de elevi, iar al doilea
// notele la informatica. Se cere sa se afiseze numele elevilor cu nota
// cea mai mica. Daca mai multi elevi au nota minima, se vor afisa toti.

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