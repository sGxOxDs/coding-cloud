#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <vector>
//1083339
using namespace std;

#define MAXWORDLENGTH 255
struct dictionary {
char word[MAXWORDLENGTH];
unsigned int count;
};
void read(const char path[],vector< dictionary > &nowdata);
void run(vector< dictionary > &nowdata);
void out(vector< dictionary > &nowdata);
bool existing( dictionary temp, const vector< dictionary > &data );

int main()
{
    vector<dictionary> nowdata;

    char path[]="IHaveADream.txt";

    read(path,nowdata);

    run(nowdata);

    out(nowdata);

    return 0;
}
bool existing( dictionary temp, const vector< dictionary > &data )
{
    for(int i=0;i<data.size();i++)
        if( strcmp(data.at(i).word ,temp.word)==0 )
            return true;
    return false;
}
void read(const char path[],vector< dictionary > &nowdata)
{
    dictionary temp;
    fstream File(path, ios::in);
    if( !File.is_open() )
        cout << "Can not open " << path << endl;

    string word;
    while(File >> word)
    {
        for(int i=0;i<word.size();i++)
        {
            if( !isalpha(word[i]) )
            {
                word.erase(word.begin()+i);
                i--;
            }
            else
                word[i]=tolower( word[i] );
        }
        int k;
        for(k=0;k<word.size();k++)
            temp.word[k]=word[k];
        temp.word[k]='\0';
        temp.count=1;
        if( !existing(temp,nowdata) && k!=0)
            nowdata.push_back(temp);
        else
            for(int i=0;i<nowdata.size();i++)
                if( strcmp(nowdata.at(i).word ,temp.word)==0 )
                    nowdata.at(i).count++;
    }
    File.close();
}
void run(vector< dictionary > &nowdata)
{
    dictionary temp;
    for(int i=0;i<nowdata.size();i++)
        for(int j=i;j<nowdata.size();j++)
            if(nowdata[i].count<nowdata[j].count)
            {
                temp=nowdata[i];
                nowdata[i]=nowdata[j];
                nowdata[j]=temp;
            }
    for(int i=0;i<nowdata.size();i++)
        cout<<setw(16)<<nowdata[i].word<<setw(4)<<nowdata[i].count<<endl;
}
void out(vector< dictionary > &nowdata)
{
    fstream File("test.txt",ios::out);
    for(int i=0;i<nowdata.size();i++)
        File<<setw(16)<<nowdata[i].word<<setw(4)<<nowdata[i].count<<endl;
    File.close();
}
