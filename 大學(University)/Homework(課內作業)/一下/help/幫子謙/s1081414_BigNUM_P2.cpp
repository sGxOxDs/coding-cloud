#include"s1081414_BigNUM_P2.h"

#include<iostream>
#include<algorithm>

using namespace std;
BigNUM::BigNUM(){
	num = NULL;
	size = 0;
};
int maxN(int a, int b) {
	if (a < b) return a;
	return b;
}
BigNUM::BigNUM(int x) {

	if (x == 0 ) {
		num = new int[1];
		num[0] = 0;
		size = 1;
	}
	else {
		size = 1;
		num = new int[size];
		num[0] = x;
	}
	//num = array;


}
BigNUM::BigNUM(const BigNUM&y):size(y.size) {
	//delete num;
	num = new int[size];
	size = y.size;
	for (int i = 0;i < size;i++) {
		num[i] = y.num[i];
	}
	
	
}

BigNUM::~BigNUM() {
	
	//cout << "Hello";
	delete[] num ;
}
BigNUM BigNUM::operator+(const BigNUM &D) {


	BigNUM sum(0);

	delete[]sum.num;
	sum.num = new int[size+1]();
	sum.size = size +1;
	
	for (int i = 0;i < size;i++) {
		sum.num[i] = D.num[i] + num[i];
	}
	
	for (int i = 0;i < size;i++) { //問題出在這一行
		if (sum.num[i] > 9) {
			sum.num[i] -= 10;
			sum.num[i + 1] = sum.num[i + 1] + 1;
		}
	}


	if (sum.num[sum.size - 1] == 0) {
		sum.size--;
	}
	

	return sum;
}
BigNUM& BigNUM::operator=(const BigNUM& D) {

	delete num;
	size = D.size;
	num = new int[size];
	
	//cout << size<<"kl"<<D.size << "hr";
	//size = D.size;
	for (int i = 0;i < size;i++) {
		num[i] = D.num[i];
	}
	return *this;
}
ostream& operator<<(ostream& cout,BigNUM &david) {
	if (david.num[0]== 0&&david.size==1) {
		cout << 0;
	}
	else {
		for (int i = david.size-1;i >=0;i--) {
			
			cout << david.num[i]<<" ";
		}
	}
	
	return cout;
}