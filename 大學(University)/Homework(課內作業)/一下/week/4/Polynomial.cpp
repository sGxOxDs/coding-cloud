#include <iostream>
using namespace std;
#include "Polynomial.h"
//1083339
Polynomial::Polynomial()
{
	myptr = nullptr;
}
Polynomial::Polynomial(int x)
{
	size = x;
	myptr = new int[size]();
}
Polynomial::Polynomial(const Polynomial& copy)
{
	size = copy.size;
	myptr = new int[size]();
	for (int i = 0; i < size; i++)
		myptr[i] = copy.myptr[i];
}
Polynomial::~Polynomial()
{
	if (myptr != nullptr)
		delete[] myptr;
}
Polynomial Polynomial::operator+(Polynomial& right)
{
	Polynomial sum;
	sum.size = (size > right.size) ? size : right.size ;
	sum.myptr = new int[sum.size]();
	for (int i = 0; i < size; i++)
		sum.myptr[i] = myptr[i];
	for (int i = 0; i < right.size; i++)
		sum.myptr[i] += right.myptr[i];
	return sum;
}
Polynomial Polynomial::operator-(Polynomial& right)
{
	Polynomial difference;
	difference.size = (size > right.size) ? size : right.size;
	difference.myptr = new int[difference.size]();
	for (int i = 0; i < size; i++)
		difference.myptr[i] = myptr[i];
	for (int i = 0; i < right.size; i++)
		difference.myptr[i] -= right.myptr[i];
	return difference;
}
const Polynomial& Polynomial::operator=(const Polynomial& right)
{
	size = right.size;
	if (myptr != nullptr)
		delete[] myptr;
	myptr = new int[size]();
	for (int i = 0; i < size; i++)
		myptr[i] = right.myptr[i];
	return *this;
}
istream& operator>>(istream& input, Polynomial& right)
{
	for (int i = right.size - 1; i >= 0; i--)
		input >> right.myptr[i];
	return input;
}
ostream& operator<<(ostream& output, const Polynomial& right)
{
	for (int i = right.size - 1; i >= 0; i--)
	{
		if (i != right.size - 1)
			output << " + ";
		output << right.myptr[i] << " * X^" << i;
	}
	output << endl;
	return output;
}