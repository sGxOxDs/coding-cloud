#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace::std;

 // reads in a C++ program from a cpp file, and put it to the vector program
void load( vector< string > &program );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( string &sourceLine );

// deletes all string constants from sourceLine
void delStrConsts( string &sourceLine );

// deletes all character constants from sourceLine
void delCharConsts( string &sourceLine );

// deletes the first identifier from sourceLine, and returns it
string delFirstIdentifier( string &sourceLine );

// stores all non-keyword strings in the vector identifiers into a text file
void store( vector< string > &identifiers );
void outputpro( vector< string > &program );
void outputide( vector< string > &identifiers );

// return true if and only if "str" is a C++ keyword
bool keyword( string str );

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( vector< string > &identifiers, int pos );

const string keywords[] = { "auto", "break", "case", "char", "const",
                            "continue", "default", "define","do", "double",
                            "else", "enum", "extern", "float", "for",
                            "goto", "if", "int", "long", "register",
                            "return", "short", "signed", "sizeof",
                            "static", "struct", "switch", "typedef",
                            "union", "unsigned", "void", "volatile",
                            "while", "bool", "catch", "class",
                            "const_cast", "delete", "dynamic_cast",
                            "explicit", "false", "friend", "inline",
                            "mutable", "namespace", "new", "operator",
                            "private", "protected", "public",
                            "reinterpret_cast", "static_cast", "template",
                            "this", "throw", "true", "try", "typeid",
                            "typename", "using", "virtual", "include" };

int main()
{
   vector< string > program;

   // reads in a C++ program from a cpp file, and put it to the vector program
   load( program );

   vector< string > identifiers;
   string firstIdentifier;
   string null;

   for( unsigned int i = 0; i < program.size(); i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      // extracts all identifiers from program[ i ], and put them into the vector identifiers
      while( ( firstIdentifier = delFirstIdentifier( program[ i ] ) ) != null )
         identifiers.push_back( firstIdentifier );
   }

   // stores all non-keyword strings in the vector identifiers into a text file
    store( identifiers );
    //outputpro( program );
    //cout<<"=========="<<endl;
    //outputide( identifiers );
	//system( "pause" );
}
void load( vector< string > &program )
{
    fstream file;
    file.open("test.cpp",ios::in);
    program.reserve(150);
    string temp;
    if(!file)
        cout<<"fail"<<endl;
    else
        for(;getline(file,temp);)
            program.push_back(temp);
    file.close();
};
void delComment( string &sourceLine )
{
    for(int i=sourceLine.size()-1;i>0;i--)
        if(sourceLine.at(i)=='/'&& sourceLine.at(i-1)=='/')
        {
            for(i--;i<sourceLine.size();i++)
                sourceLine.at(i)='\0';
            break;
        }
};
void delStrConsts( string &sourceLine )
{
    char ct[20];
    for(int i=0,j=0;sourceLine[i]!='\0';i++,j++)
    {
        ct[j]=sourceLine[i];
        if( !(sourceLine[i]>='a'&&sourceLine[i]<='z'))
        {
            ct[j]='\0';
            if(keyword(ct))
                for(int x=i-j;x<i;x++)
                    sourceLine[x]=' ';
            j=-1;
        }
        if(sourceLine[i]=='\"')
        {
            for(sourceLine[i++]=' ';sourceLine[i]!='\"';)
                sourceLine[i++]=' ';
            sourceLine[i++]=' ';
        }
    }
};
void delCharConsts( string &sourceLine )
{
    for(int i=0;sourceLine[i]!='\0';i++)
        if( sourceLine[i]>='a'&&sourceLine[i]<='z' || sourceLine[i]>='A'&&sourceLine[i]<='Z' || sourceLine[i]>='0'&&sourceLine[i]<='9' || sourceLine[i]=='_');
        else
            sourceLine[i]=' ';
    for(int i=1;sourceLine[i]!='\0';i++)
        if(sourceLine[i]>='0'&&sourceLine[i]<='9'&&sourceLine[i-1]==' ')
            sourceLine[i]=' ';
};
string delFirstIdentifier( string &sourceLine )
{
    string Ans;
    char identifiers[500];
    for(int i=0,j=0;sourceLine[i]!='\0';i++)
        if( (sourceLine[i]>='a'&&sourceLine[i]<='z') || (sourceLine[i]>='A'&&sourceLine[i]<='Z') )
        {
            for(;sourceLine[i]!=' ';)
                identifiers[j++]=sourceLine[i++];
            identifiers[j]='\0';
            if( identifiers )
            {
                Ans=identifiers;
                for(int x=i-1;x>=i-j;)
                    sourceLine[x--]='+';
                break;
            }
            j=0;
        }
    return Ans;
};
void store( vector< string > &identifiers )
{
    fstream file;
    file.open("Ans-3.txt",ios::out);
    if(!file)
        cout<<"fail"<<endl;

    for(int i=0;i<identifiers.size();i++)
        if(duplicate( identifiers, i ))
            file<<identifiers[i]<<endl;
    file.close();
};
void outputpro( vector< string > &program )
{
    for(int i=0;i<program.size();i++)
        cout<<i<<" "<<program[i]<<endl;
};
void outputide( vector< string > &identifiers )
{
    for(int i=0;i<identifiers.size();i++)
        cout<<i<<" "<<identifiers[i]<<endl;
};
bool keyword( string str )
{
    for(int i=0;i<62;i++)
        if(str==keywords[i])
            return true;
    return false;
};
bool duplicate( vector< string > &identifiers, int pos )
{
    for(int i=0;i<pos;i++)
        if(identifiers[i]==identifiers[pos])
            return false;
    return true;
};
