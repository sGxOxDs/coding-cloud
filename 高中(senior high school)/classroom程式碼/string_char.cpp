#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  
string a="test";/*�ŧi�r��*/
char b[10]="testb";/*�ŧi10�r��*/
//----------output a------------
cout<<"cout a"<<a<<endl;/*��X"cout a"�Ma�M���_�y*/
//printf(a);  error
//----------output a------------
//----------output b------------
cout<<"cout b"<<b<<endl;/*��X"cout b"�Mb�M���_�y*/
printf("printf a[0] %c \n",a[0]);/*��Xa���Ĥ@�Ӧr��*/
printf("printf b[0] %c \n",b[0]); /*��Xb���Ĥ@�Ӧr��*/
//printf("printf s a=%s \n",a);// error
printf("printf s b=%s \n",b);

cout<<a[0]<<endl;
cout<<b[0]<<endl;
//----------output b------------

//input a b  output a b  in  CIN COUT
cin>>a;/*��Ja*/
cin>>b;
cout<<a<<endl;
cout<<b<<endl;
scanf("%s", &a);
scanf("%s", &b);
//printf("%c \n",a[0]);  ����error
//printf("%s \n",a);     compiler  error
//cout<<a<<endl;   run error  because scanf a 
cout<<b<<endl;
printf("%s \n",b);
//input a b  output a b  in  CIN COUT

//compute length
int count = printf("This is a test!\n");
    printf("%d\n", count);
    
    cout<<count;
    
system("pause");
return 0;

}

