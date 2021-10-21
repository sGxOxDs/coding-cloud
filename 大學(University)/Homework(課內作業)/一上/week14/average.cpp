// Compute average in vector.
// Standard includes
#include <vector>
using namespace std;
// Private header file with prototype for average.
#include "average.h"

// average
float average(const vector<float>& x) {
    float sum = 0.0;
    for (int i=0; i<x.size(); i++) {
        sum += x[i];
    }    
    
    return sum / x.size();
}
