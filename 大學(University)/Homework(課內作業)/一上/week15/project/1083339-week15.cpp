#include "Lib1.h"
//1083339

int main()
{
    vector<dictionary> nowdata;

    char path[]="IHaveADream.txt";
    char igpath[]="prepositions.txt";
    char outpath[]="test.txt";

    read(path,igpath,nowdata);
    run(nowdata);
    out(outpath,nowdata);

    return 0;
}

