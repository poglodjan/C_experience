#include <iostream>
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


Matrix::Matrix() :coef(nullptr), size(0){}

Matrix::Matrix(int _size) : coef(nullptr), size(0) {
	size = _size;
	coef = new (nothrow) int* [size];
	for (int i = 0; i < size; i++) {
		coef[i] = new (nothrow) int[size];
		for (int j = 0; j < size; j++) {
			coef[i][j] = 0;
		}
	}
}

Matrix::Matrix(int** m, int _size) : coef(nullptr), size(0)
{
	size = _size;
	coef = new (nothrow) int* [size];
	for (int i = 0; i < size; i++) {
		coef[i] = new (nothrow) int[size];
		for (int j = 0; j < size; j++) {
			coef[i][j] = m[i][j];
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < size; i++)
	{
		delete[] coef[i];
	}
	delete[] coef;
}

Matrix::Matrix(const Matrix& m) : coef(nullptr), size(0)
{
	size = m.size;
	coef = new(nothrow) int* [size];
	for (int i = 0; i < size; i++) {
		coef[i] = new (nothrow) int[size];
		for (int j = 0; j < size; j++) {
			coef[i][j] = m.coef[i][j];
		}
	}
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m)
		return *this;
	if (size != m.size)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] coef[i];
		}
		delete[] coef;

		coef = new (nothrow) int* [m.size];
		for (int i = 0; i < m.size; i++)
		{
			coef[i] = new (nothrow) int[m.size];
		}

		size = m.size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				coef[i][j] = m.coef[i][j];
			}
		}
		return *this;
	}
}

ostream& operator<<(ostream &out, const Matrix &m){
	out << "( ";
	for (int i = 0; i < m.size; i++) {
		if (i != 0)
			out << "  ";
		for (int j = 0; j < m.size; j++)
		{
			out << m.coef[i][j] << " ";
		}
		if(i!=m.size-1)
			out << endl;
	}
	out << ")" << endl;
	return out;
}
