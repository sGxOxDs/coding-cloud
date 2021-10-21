

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

class Polynomial
{
	friend istream& operator>>(istream&, Polynomial&);
	friend ostream& operator<<(ostream&, const Polynomial&);

public:
	Polynomial();
	Polynomial(int);
	Polynomial(const Polynomial&);
	~Polynomial();
	Polynomial operator+(Polynomial&);
	Polynomial operator-(Polynomial&);
	const Polynomial& operator=(const Polynomial&);

private:
	int* myptr;
	int size;
};




#endif
