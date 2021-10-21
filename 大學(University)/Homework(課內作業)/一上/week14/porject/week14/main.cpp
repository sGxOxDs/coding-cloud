// Print above average numbers.  Illustrates multiple source file compilations.
// Standard includes
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// Private include for average function.
#include "matrix.h"

int main()
{
    Matrix A;
    Matrix B;
    Matrix C;


    loadmatrix(A,"matrix data\\3\\A.csv");
    loadmatrix(B,"matrix data\\3\\B.csv");

    printmatrix(A);
    cout<<"==="<<endl;
    printmatrix(B);

    C=multiplicationmatrix(A,B);
    cout<<"==="<<endl;
    printmatrix(C);

    A.deletemat();
    B.deletemat();
    C.deletemat();

    return 0;
}
