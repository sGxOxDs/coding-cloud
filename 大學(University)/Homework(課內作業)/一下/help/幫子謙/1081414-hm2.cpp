#include<iostream>
#include<algorithm>
#include<cmath>
#include"s1081414_BigNUM.h"

using namespace std;
BigNUM::BigNUM(){
	num = NULL;
	size = 0;
};
BigNUM::BigNUM(int x) {

	if (x == 0) {
		num = new int[1];
		num[0] = 0;
		size = 1;
	}
	else {
		size = x;
		//int* array = new int [size];
		num = new int[size];
		num[0] = 1;
	}
	//num = array;

}
BigNUM::~BigNUM() {
	
	if (num != nullptr)
		delete[] num;
		//num = NULL;
		//size = 0;
	//}
}
BigNUM BigNUM::operator+(BigNUM D) {

	BigNUM sum(0);
	
	delete[]sum.num;
	sum.num = new int[size + 1]();
	sum.size = size + 1;

	for (int i = 0;i < size;i++) {
		sum.num[i] = D.num[i]+num[i];
	}
	
	
	for (int i = 0;i < sum.size-1;i++) {
		if (sum.num[i] > 9) {
			sum.num[i] -= 10;
			sum.num[i+1]++;
		}
	}
	

	if (sum.num[sum.size - 1] == 0) {
		sum.size--;
	}
	//delete[] num; //change
	//delete[] D.num; //change
	
	return sum;

}
ostream& operator<<(ostream&output,const BigNUM &david) {
	if (david.num[0]== 0&&david.size==1) {
		output << 0;
	}
	else {
		for (int i = david.size-1;i >=0;i--) {
			output << david.num[i];
		}
	}
	
	return output;
}