#include <iostream>
#include <iomanip>
#include <time.h>

int** Create(const int n, const int low, const int high ) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = low + rand() % (high - low + 1);
		}
	}
	return arr;
}

void Free(int** arr,const int n) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void Print(int** arr, const int n) {
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << std::endl;
	}
}

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void TransposeMatrix(int** arr, const int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			Swap(arr[i][j], arr[j][i]);
		}
	}
}

int main() {

	srand((unsigned)time(NULL));

	int low = 1;
	int high = 50;
	int n = 6;

	int** arr = Create(n, low, high);
	Print(arr, n);
	TransposeMatrix(arr, n);
	Print(arr, n);


	Free(arr, n);
	return 0;
}

