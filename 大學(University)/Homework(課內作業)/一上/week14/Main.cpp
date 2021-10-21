// Print above average numbers.  Illustrates multiple source file compilations.
// Standard includes
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
// Private include for average function.
#include "matrix.h"

int main(){

    vector<float> fv;    // Store the input floats here.
    float         temp;  // Temp for input.

    //... Read floats into vector
    while (cin >> temp) {
        fv.push_back(temp);
    }

    //... Compute average.
    float avg = average(fv);

    //... Print greater than average numbers.
    cout << "Average = " << avg << endl;
    for (int i = 0; i < fv.size(); i++) {
        if (fv[i] > avg) {
            cout << fv[i] << endl;
        }
    }

    return 0;
}
