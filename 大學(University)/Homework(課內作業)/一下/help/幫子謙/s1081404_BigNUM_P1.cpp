#include<iostream>
#include<iomanip>
#include "s1081404_BigNUM_P1.h"
using namespace std;

ostream& operator<<(ostream& output, const BigNUM& right)
{
	for ( int i = right.size() - 1; i >= 0; i--) //c
	{
		if (right.ptr[0] == 0 && right.size() == 1)
		{
			output << "0";
			break;
		}

		output << right.ptr[i];
		if (i > 0)
		{
			output << ",";
		}

		if (right.ptr[i] > 999)//3位一個逗號1,000
		{
			output << right.ptr[i] / 1000 << ',';
			right.ptr[i] %= 1000; //
			output << right.ptr[i];
		}


	}
	return output;
}

//void BigNUM::print()
//{
//	for (unsigned int i = size() - 1; i >= 0; i--)
//	{
//		if (ptr[0] == 0 && size() == 1)
//		{
//			cout << "0";
//			break;
//		}
//
//		cout << ptr[i];
//		if (i > 0)
//		{
//			cout << ",";
//		}
//
//		if (ptr[i] > 999)//3位一個逗號1,000
//		{
//			cout << ptr[i] / 1000 << ',';
//			ptr[i] % 1000;
//			cout << ptr[i];
//		}
//
//
//	}
//}

BigNUM::BigNUM()
{
	
}

BigNUM::BigNUM(unsigned int i)
{
	if (i == 0) {
		ptr = new unsigned int[1];
		ptr[0] = 0;
	}
	else {
		ptr = new unsigned int[1];
		ptr[0] = 1;
	}
}

BigNUM::~BigNUM()
{
	if (ptr != nullptr) 
	{
		delete[] ptr;
	}
}

BigNUM::BigNUM(const BigNUM& right)
{
	 ptr= new unsigned int[300]();//300格
	for ( int j = 0; j < right.size(); j++)//c
	{
		ptr[j]=right.ptr[j];
	}

}


BigNUM BigNUM::operator+(const BigNUM& right)//a+b  ->  a.operator+(b)           進位
{
	for ( int j = 0; j < size(); j++)//c
	{
		ptr[j] += right.ptr[j];
		if (ptr[j] > 999999)  //       每格6位
		{
			ptr[j + 1]++;
			ptr[j] -= 1000000;
		}
		
	}
	return *this;

}

/*BigNUM BigNUM::operator=(const BigNUM& right)
{
	for  (int j = 0; j < right.size(); j++) //c
	{
		ptr[j] = right.ptr[j];
	}
	return *this;
}*/


int BigNUM::size()const//算有幾格
{
	int i = 1,size=1;
	while (ptr[i] != NULL)
	{
		size++;
		i++;
	}
	return size;
		
}

// BigNUM ostream::operator<<(ostream& output, const BigNUM& right)
//{
//	for (unsigned int i = right.size() - 1; i >= 0; i--)
//	{
//		if (right.ptr[0] == 0 && right.size() == 1)
//		{
//			output << "0";
//			break;
//		}
//
//		output << right.ptr[i];
//		if (i > 0)
//		{
//			output << ",";
//		}
//
//		if (right.ptr[i] > 999)//3位一個逗號1,000
//		{
//			output << right.ptr[i] / 1000 << ',';
//			right.ptr[i] % 1000;
//			output << right.ptr[i];
//		}
//
//
//	}
//}






BigNUM diNFib(unsigned int n = 0) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return diNFib(n-1) + diNFib(n-2);
}

int main() {
	unsigned int level = 0;
	cout << "Hello s1234567! how many level do you want to reach?" << endl;
	cin >> level; //this input value will always >=0

	BigNUM ANS(0);
	
	for (unsigned int i = 0; i < level; ++i) {
		ANS = diNFib(i);

		cout << "F(" << i << ") = " << ANS << endl;
		//cout << "F(" << i << ") = "; ANS.print();
	}
	system("pause");
	return 0;
}