#ifndef s1081404_BigNUM_P1_h
#define s1081404_BigNUM_P1_h

#include<iostream>
using namespace std;

class BigNUM
{
	friend ostream& operator<<(ostream& output, const BigNUM& right);
public:
	BigNUM(unsigned int i);// constructor         make BigNUM diNFib can return a number //c
	BigNUM();//default constructor   default�q�{
	~BigNUM();//destructor
	BigNUM(const BigNUM& right);//copy constructor
	BigNUM operator+(const BigNUM& right);
	//BigNUM operator=(const BigNUM& right);
	int size()const;
	//void print();
	

	//const object
	//member function const
	/*1.�u��const objects�i�H�Qconst member function�I�s�C
	  2.const member function����I�s�Dconst��member function�C*/
	
private:
	unsigned int* ptr;//unsigned�S������Ÿ�
};



#endif s1081404_BigNUM_P1_h