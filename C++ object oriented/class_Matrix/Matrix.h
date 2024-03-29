#pragma once
using namespace std;

class Matrix {
	int** coef;
	int size;

public:
	Matrix();
	Matrix(int _size);
	Matrix(int** m, int _size);
	~Matrix();
	Matrix(const Matrix& m);
	Matrix& operator=(const Matrix& m);

	friend ostream& operator<<(ostream& out, const Matrix& m);
};
