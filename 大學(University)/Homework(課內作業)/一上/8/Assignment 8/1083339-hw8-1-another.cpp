#include <iostream>
#include <fstream>
#include <string.h>
using namespace::std;

// reads in a C++ program from a cpp file, and put it to the array program
void load( char( *program )[ 100 ], int &numLines );

// deletes the comment beginning with "//" from sourceLine if any
void delComment( char sourceLine[] );

// deletes all string constants from sourceLine
void delStrConsts( char sourceLine[] );

// deletes all character constants from sourceLine
void delCharConsts( char sourceLine[] );

// extracts all identifiers from sourceLine, and put them into the array identifiers
void extractIdentifiers( char sourceLine[], char identifiers[][ 32 ], int &numIdentifiers );

// stores all non-keyword strings in the array identifiers into a text file
void store( char ( *identifiers )[ 32 ], int numIdentifiers );
void outputpro( char ( *program )[ 100 ], int numLines );
void outputide( char ( *identifiers )[ 32 ], int numIdentifiers );

// returns true if and only if str is a C++ keyword
bool keyword( char str[] );

// returns true if and only if identifiers[ pos ] belongs to identifiers[ 0 .. pos-1 ]
bool duplicate( char ( *identifiers )[ 32 ], int pos );

const char keywords[][ 20 ] = { "auto", "break", "case", "char", "const",
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
   char ( *program )[ 100 ] = new char[ 500 ][ 100 ];
   int numLines = 0;

   // reads in a C++ program from a cpp file, and put it to the array program
   load( program, numLines );

   char ( *identifiers )[ 32 ] = new char[ 500 ][ 32 ];
   int numIdentifiers = 0;

   for( int i = 0; i < numLines; i++ )
   {
      delComment( program[ i ] ); // deletes the comment beginning with "//" from program[ i ]
      delStrConsts( program[ i ] ); // deletes all string constants from program[ i ]
      delCharConsts( program[ i ] ); // deletes all character constants from program[ i ]

      if( strcmp( program[ i ], "" ) != 0 )
         extractIdentifiers( program[ i ], identifiers, numIdentifiers );
         // extracts all identifiers from program[ i ], and put them into the array identifiers
   }

   // stores all non-keyword strings in the array identifiers into a text file
   store( identifiers, numIdentifiers );
   //outputpro( program, numLines );
   //cout<<"========================"<<endl;
   //outputide(identifiers, numIdentifiers );
	system( "pause" );
}
void load( char( *program )[ 100 ], int &numLines )
{
    fstream file;
    file.open("test.cpp",ios::in);
    if(!file)
        cout<<"fail"<<endl;
    else
        for(;file.getline(program[numLines],500);numLines++);
    file.close();
};
void delComment( char sourceLine[] )
{
    for(char *i=(sourceLine)+1;*i!='\0';i++)
        if( *(i-1)=='/'&& *i=='/')
        {
            *(i-1)='\0';
            break;
        }
};
void delStrConsts( char sourceLine[] )
{
    /*char ct[20];*/
    for(int i=0,j=0;sourceLine[i]!='\0';i++,j++)
    {
        /*ct[j]=sourceLine[i];
        if( !(sourceLine[i]>='a'&&sourceLine[i]<='z'))
        {
            ct[j]='\0';
            if(keyword(ct))
                for(int x=i-j;x<i;x++)
                    sourceLine[x]=' ';
            j=-1;
        }*/
        if(sourceLine[i]=='\"')
        {
            for(sourceLine[i++]=' ';sourceLine[i]!='\"';)
                sourceLine[i++]=' ';
            sourceLine[i++]=' ';
        }
    }
};
void delCharConsts( char sourceLine[] )
{
    for(int i=0;sourceLine[i]!='\0';i++)
        if( sourceLine[i]>='a'&&sourceLine[i]<='z' || sourceLine[i]>='A'&&sourceLine[i]<='Z' || sourceLine[i]>='0'&&sourceLine[i]<='9' || sourceLine[i]=='_');
        else
            sourceLine[i]=' ';
    for(int i=1;sourceLine[i]!='\0';i++)
        if(sourceLine[i]>='0'&&sourceLine[i]<='9'&&sourceLine[i-1]==' ')
            sourceLine[i]=' ';
};
void extractIdentifiers( char sourceLine[], char identifiers[][ 32 ], int &numIdentifiers )
{
    for(int i=0,j=0;sourceLine[i]!='\0';i++)
        if( (sourceLine[i]>='a'&&sourceLine[i]<='z') || (sourceLine[i]>='A'&&sourceLine[i]<='Z') )
        {
            for(;sourceLine[i]!=' ';)
                identifiers[numIdentifiers][j++]=sourceLine[i++];
            identifiers[numIdentifiers][j]='\0';
            if( duplicate( identifiers ,numIdentifiers ) )
                numIdentifiers++;
            j=0;
        }
};
void store( char ( *identifiers )[ 32 ], int numIdentifiers )
{
    fstream file;
    file.open("Ans-1.txt",ios::out);
    if(!file)
        cout<<"fail"<<endl;

    //cout<<numIdentifiers<<endl;
    for(int i=0;i<numIdentifiers;i++)
    {
        //cout<<i<<" ";
        //for(int j=0;identifiers[i][j]!='\0';j++)
        if( !( keyword(identifiers[i]) ) )
            file<<identifiers[i]<<endl;
    }
    file.close();
};
void outputpro( char ( *program )[ 100 ], int numLines )
{
    for(int i=0;i<numLines;i++)
    {
        for(int j=0;program[i][j]!='\0';j++)
            cout<<program[i][j];
        cout<<endl;
    }
};
void outputide( char ( *identifiers )[ 32 ], int numIdentifiers )
{
    cout<<numIdentifiers<<endl;
    for(int i=0;i<numIdentifiers;i++)
    {
        cout<<i<<" ";
        for(int j=0;identifiers[i][j]!='\0';j++)
            cout<<identifiers[i][j];
        cout<<endl;
    }
};
bool keyword( char str[] )
{
    for(int i=0;i<62;i++)
        if(strcmp(str,keywords[i])==0)
            return true;
    return false;
};
bool duplicate( char ( *identifiers )[ 32 ], int pos )
{
    for(int i=0;i<pos;i++)
        if(strcmp( identifiers[i] , identifiers[pos])==0)
            return false;
    return true;
};
