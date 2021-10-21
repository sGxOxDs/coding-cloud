#include <iostream>
#include <fstream>  
#include <sstream>  

using namespace std;
int main(int argc, const char *argv[])
{
    stringstream ss;
    string value;

    // clear error flags and stream buffer 
    ss.str("");
    ss.clear();

    ss << "tim,100,1";
    while(getline(ss,value,','))                                                                                                                      
    {
        std::cout << "Value:" << value << endl;
    }   
    return 0;
}

