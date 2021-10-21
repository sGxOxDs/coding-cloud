#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[])
{
    string sList[3] = { "100","1","3" };
    int nList[3];

    //for (int i = 0; i < 3; i++) {
    //    stringstream sn;
    //    sn << sList[i];
    //    sn >> nList[i];
    //}
    
    stringstream sn;
    for (int i = 0; i < 3; i++) {
        sn.str("");
        sn.clear();
        sn << sList[i];
        sn >> nList[i];
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        cout << nList[i] << endl;
        sum += nList[i];
    }
    cout << "sum: " << sum << endl;

    return 0;
}
