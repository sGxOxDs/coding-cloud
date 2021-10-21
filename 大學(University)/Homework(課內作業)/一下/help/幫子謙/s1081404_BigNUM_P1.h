#ifndef s1081404_BigNUM_P1_h
#define s1081404_BigNUM_P1_h

#include<iostream>
using namespace std;

class BigNUM
{
	friend ostream& operator<<(ostream& output, const BigNUM& right);
public:
	BigNUM(unsigned int i);// constructor         make BigNUM diNFib can return a number //c
	BigNUM();//default constructor   default默認
	~BigNUM();//destructor
	BigNUM(const BigNUM& right);//copy constructor
	BigNUM operator+(const BigNUM& right);
	//BigNUM operator=(const BigNUM& right);
	int size()const;
	//void print();
	

	//const object
	//member function const
	/*1.只有const objects可以被const member function呼叫。
	  2.const member function不能呼叫非const的member function。*/
	
private:
	unsigned int* ptr;//unsigned沒有任何符號
};



#endif s1081404_BigNUM_P1_h