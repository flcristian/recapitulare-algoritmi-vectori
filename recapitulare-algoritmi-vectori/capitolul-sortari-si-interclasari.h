#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Problema 1
// Sa se sorteze vectorul utilizand bubble sort.

void citireProblema1(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void bubbleSortProblema1(int x[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

void afisareProblema1(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	} 
	cout << endl;
}

void problema1() {
	int x[100], n;
	citireProblema1(x, n);
	bubbleSortProblema1(x, n);
	afisareProblema1(x, n);
}

// Problema 2
// Sa se sorteze vectorul utilizand merge sort.

void citireProblema2(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void mergeProblema2(int x[], int min, int max, int mid) {
	int i, j, k, temp[100];
	i = min, j = mid + 1, k = 0;

	while (i <= mid && j <= max) {
		if (x[i] < x[j]) {
			temp[k] = x[i];
			k++;
			i++;
		}
		else {
			temp[k] = x[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		temp[k] = x[i];
		k++;
		i++;
	}
	while (j <= max) {
		temp[k] = x[j];
		k++;
		j++;
	}

	for (int i = min; i <= max; i++) {
		x[i] = temp[i - min];
	}
}

void mergeSortProblema2(int x[], int min, int max) {
	if (min < max) {
		int mid = (min + max) / 2;
		mergeSortProblema2(x, min, mid);
		mergeSortProblema2(x, mid + 1, max);
		mergeProblema2(x, min, max, mid);
	}
}

void afisareProblema2(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema2() {
	int x[100], n;
	citireProblema2(x, n);
	mergeSortProblema2(x, 0, n - 1);
	afisareProblema2(x, n);
}

// Problema 3
// Sa se sorteze vectorul utilizand bubble sort cu santinela.

void citireProblema3(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void bubbleSortSantinelaProblema3(int x[], int n) {
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

void afisareProblema3(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema3() {
	int x[100], n;
	citireProblema3(x, n);
	bubbleSortSantinelaProblema3(x, n);
	afisareProblema3(x, n);
}

// Problema 4
// Sa se ordoneze un vector format din elementele {0, 1}
// parcurgandu-l o singura data.

void citireProblema4(int x[], int& n) {
	ifstream f("input.txt");
	n = 0;
	while (!f.eof()) {
		f >> x[n];
		n++;
	}
	f.close();
}

void sortProblema4(int x[], int n) {
	for (int i = 0, j = n - 1; i < j; i++) {
		while (x[j] == 1) {
			j--;
		}
		while (x[i] == 0) {
			i++;
		}
		if (i < j) {
			x[i] = 0, x[j] = 1;
		}
	}
}

void afisareProblema4(int x[], int n) {
	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void problema4() {
	int x[100], n;
	citireProblema4(x, n);
	sortProblema4(x, n);
	afisareProblema4(x, n);
}

