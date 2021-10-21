#include "function.h"

bool existing( dictionary temp, const vector< dictionary > &data )
{
    for(int i=0;i<data.size();i++)
        if( strcmp(data.at(i).word ,temp.word)==0 )
            return true;
    return false;
}
void read(const char path[],const char igpath[],vector< dictionary > &data)
{
    dictionary temp;
    vector< dictionary > igword;
    string word;

    fstream ig(igpath, ios::in);
    if( !ig.is_open() )
        cout << "Can not open " << igpath << endl;
    while(ig >> word)
    {
        for(int i=0;i<word.size();i++)
        {
            if( isalpha(word[i])!=-1 )
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
        if( !existing(temp,igword) && k!=0)
            igword.push_back(temp);
    }
    ig.close();

    fstream File(path, ios::in);
    if( !File.is_open() )
        cout << "Can not open " << path << endl;
    while(File >> word)
    {
        for(int i=0;i<word.size();i++)
        {
            if( isalpha(word[i]) != -1)
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
        if( !existing(temp,data) && k!=0 && !existing(temp,igword))
                data.push_back(temp);
        else
            for(int i=0;i<data.size();i++)
                if( strcmp(data.at(i).word ,temp.word)==0 )
                    data.at(i).count++;
    }
    File.close();
}
void run(vector< dictionary > &data)
{
    dictionary temp;
    for(int i=0;i<data.size();i++)
        for(int j=i;j<data.size();j++)
            if(data[i].count<data[j].count)
            {
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
    for(int i=0;i<data.size();i++)
        cout<<setw(16)<<data[i].word<<setw(4)<<data[i].count<<endl;
}
void out(const char outpath[],vector< dictionary > &data)
{
    fstream File(outpath,ios::out);
    for(int i=0;i<data.size();i++)
        File<<setw(16)<<data[i].word<<setw(4)<<data[i].count<<endl;
    File.close();
}
