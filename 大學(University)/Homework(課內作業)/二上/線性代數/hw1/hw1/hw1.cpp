#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream fin;
	fin.open(argv[1]);
    //fin.open("test2.bmp", ios::in | ios::binary);

    if (!fin)
    {
        cout << "open error" << endl;
        return 0;
    }

    char temp;
    int set = 0;
    int bch[24];
    for (int line = 1; fin.read(&temp, sizeof(temp)); line++)
    {
        if (line > 54)
        {
            if (temp == NULL)
                bch[set] = 1;
            else
                bch[set] = 0;
            set++;

            if (set == 24)
            {
                int ich = 0;
                ich += bch[21];
                ich += bch[18] * 2;
                ich += bch[15] * 2 * 2;
                ich += bch[12] * 2 * 2 * 2;
                ich += bch[9] * 2 * 2 * 2 * 2;
                ich += bch[6] * 2 * 2 * 2 * 2 * 2;
                ich += bch[3] * 2 * 2 * 2 * 2 * 2 * 2;
                ich += bch[0] * 2 * 2 * 2 * 2 * 2 * 2 * 2;
                char ch = ich;
                if (ch >= 32 && ch <= 126)
                    cout << ch;
                set = 0;
            }
        }
        //printf("%02x ", temp);
    }
        
    
    fin.close();
    return 0;
}
