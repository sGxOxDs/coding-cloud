#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  
string a="test";/*宣告字串*/
char b[10]="testb";/*宣告10字元*/
//----------output a------------
cout<<"cout a"<<a<<endl;/*輸出"cout a"和a然後斷句*/
//printf(a);  error
//----------output a------------
//----------output b------------
cout<<"cout b"<<b<<endl;/*輸出"cout b"和b然後斷句*/
printf("printf a[0] %c \n",a[0]);/*輸出a的第一個字元*/
printf("printf b[0] %c \n",b[0]); /*輸出b的第一個字元*/
//printf("printf s a=%s \n",a);// error
printf("printf s b=%s \n",b);

cout<<a[0]<<endl;
cout<<b[0]<<endl;
//----------output b------------

//input a b  output a b  in  CIN COUT
cin>>a;/*輸入a*/
cin>>b;
cout<<a<<endl;
cout<<b<<endl;
scanf("%s", &a);
scanf("%s", &b);
//printf("%c \n",a[0]);  執行error
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

