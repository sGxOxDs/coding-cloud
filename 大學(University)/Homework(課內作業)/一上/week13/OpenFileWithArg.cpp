#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    ifstream iFile(argv[1], ios::in);
    if( !iFile.is_open() ){
        cout << "Can not open " << argv[1] << endl;
    }

    string word;
    while(iFile >> word){
        cout << word << endl;
    }
    return 0;
}
