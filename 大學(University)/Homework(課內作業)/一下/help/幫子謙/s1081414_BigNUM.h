#ifndef BIGNUM
#define BIGNUM

#include<iostream>
#include<string>
using namespace std;

class BigNUM {

	friend ostream& operator<<(ostream& output, const BigNUM& david);
	
	public:
		
		
		BigNUM();
		BigNUM(int);

		BigNUM(const BigNUM&);

		~BigNUM();

		BigNUM operator+(BigNUM);
		
		int size;

	private:
		int* num;
		

};


#endif // !BIGNUM

