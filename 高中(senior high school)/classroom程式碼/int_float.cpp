#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	
	
	printf("example:%.2f\n", 19.234);
	printf("example:%6.2f\n", 19.234);
	
	
	int a,b,c;
	float fa,fb,fc;
	double da,db,dc;
	long la,lb,lc;
	
	
	a=5;b=4;c=3;
	fa=5;fb=4;fc=3;
	
	fa=a/b+b/c;
	cout<<fa<<endl;
  //	fa=(float)a/b+b/c;
//	cout<<fa<<endl;
   // fa=(float)a/b+(float)b/c;
   //	cout<<fa<<endl;
}
