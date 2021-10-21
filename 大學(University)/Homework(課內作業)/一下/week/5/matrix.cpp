#include "matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < ROWS * COLUMNS; i++)
		elements[i] = 0;
}

double& Matrix::operator()(int i, int j)
{
	return elements[i * 3 + j];
}

double Matrix::operator()(int i, int j) const
{
	return elements[i * 3 + j];
}

Matrix& Matrix::operator+=(const Matrix& right)
{
	for (int i = 0; i < ROWS * COLUMNS; i++)
		elements[i] += right.elements[i];
	return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right)
{
	Matrix sum;
	sum += left;
	sum += right;
	return sum;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
	Matrix product;

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			for (int z = 0; z < 3; z++)
				product(x, z) += left(x, y) * right(y, z);


	return product;
}

Matrix operator*(double left, const Matrix& right)
{
	Matrix product;
	
	for (double i = 0; i < left; i++)
		product += right;
	return product;
}

Matrix operator*(const Matrix& left, double right)
{
	Matrix product;
	for (double i = 0; i < right; i++)
		product += left;
	return product;
}

ostream& operator<<(ostream& left, const Matrix& right)
{
	for (int i = 0; i < 9; i++)
	{
		left << right(i / 3, i % 3) << " ";
		if (i % 3 == 2)
			left << endl;
	}
		
	return left;
}
