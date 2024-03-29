#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {

	int** mtx;
	mtx = new (nothrow) int* [3];
	for (int i = 0; i < 3; i++)
	{
		mtx[i] = new (nothrow) int[3];
		for (int j = 0; j < 3; j++)
		{
			mtx[i][j] = 3;
		}
	}

	Matrix m0;
	Matrix m1(3);
	Matrix m2(mtx, 3);
	Matrix m3(m2);

	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	m0 = m2;
	cout << m0 << endl;

	return 0;
}
