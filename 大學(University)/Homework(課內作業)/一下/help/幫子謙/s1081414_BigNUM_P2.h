#ifndef BIGNUM_H
#define BIGNUM_H

#include<iostream>

using namespace std;

class BigNUM {

	friend ostream& operator<<(ostream& output, BigNUM &david);

	public:
		
		
		BigNUM();
		BigNUM(int);
		BigNUM(const BigNUM&);
		~BigNUM();
		BigNUM operator+(const BigNUM&);
		BigNUM& operator=(const BigNUM&);
		

	private:
	
		int* num;
		int size;

};


#endif // !BIGNUM

