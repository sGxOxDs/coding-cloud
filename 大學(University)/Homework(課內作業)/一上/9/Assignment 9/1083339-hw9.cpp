#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace::std;

struct MemberRecord
{
   char IDNumber[ 12 ];   // account number
   char password[ 24 ];   // password
   char name[ 8 ];        // name
};

// input memberDetails from the file Members.dat
void loadMemberDetails( vector< MemberRecord > &memberDetails );

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

// login
void login( const vector< MemberRecord > &memberDetails );

// there exists a member with specified IDNumber and password
bool valid( char IDNumber[], char password[],
            const vector< MemberRecord > &memberDetails );

// add a new member
void registration( vector< MemberRecord > &memberDetails );

// return true if IDNumber is a legal ID number
bool legalID( char IDNumber[] );

// return true if IDNumber belongs to memberDetails
bool existingID( char IDNumber[], const vector< MemberRecord > &memberDetails );

// output all memberDetails into the file Members.dat
void saveMemberDetails( const vector< MemberRecord > &memberDetails );

int main()
{
   vector< MemberRecord > memberDetails = {}; // member details for all members
   int numMembers = 0;                     // number of members

   loadMemberDetails( memberDetails );

   cout << "Welcome to the Cashbox Party World!\n\n";

   int choice;

   while( true )
   {
      cout << "1 - Login\n";
      cout << "2 - Registration\n";
      cout << "3 - End\n";

      do cout << "\nEnter your choice (1~3): ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      cout << endl;

      switch ( choice )
      {
      case 1:
         login( memberDetails );
         break;

      case 2:
         registration( memberDetails );
         break;

      case 3:
         saveMemberDetails( memberDetails );
         cout << "Thank you! Goodbye!\n\n";
         system( "pause" );
         return 0;

      default:
         cout << "\nIncorrect choice!\n";
         break;
      }
   }

   system( "pause" );
}

void loadMemberDetails( vector< MemberRecord > &memberDetails )
{
    fstream file;
    file.open("Members.dat",ios::in|ios::binary);
    if(!file)
    {
        cout<<"open error"<<endl;
        return;
    }

    MemberRecord temp;
    for(int i=0;file.read( reinterpret_cast <char*> (&temp) ,sizeof(MemberRecord));i++)
        memberDetails.push_back(temp);
    file.close();
}
int inputAnInteger( int begin, int end )
{
    char in;
    cin >> in;
    if(in>=begin+'0'&&in<=end+'0')
        return in-'0';
    return -1;
}
void login( const vector< MemberRecord > &memberDetails )
{
    MemberRecord temp;
    cout << "Please enter your ID number: ";
    cin >> temp.IDNumber;
    cout << "Enter your password: ";
    cin >> temp.password;
    while( !valid(temp.IDNumber,temp.password,memberDetails) )
    {
        cout << "\nInvalid account number or password. Please try again.\n" << endl;
        cout << "Please enter your ID number: ";
        cin >> temp.IDNumber;
        cout << "Enter your password: ";
        cin >> temp.password;
    }
}
bool valid( char IDNumber[], char password[],
           const vector< MemberRecord > &memberDetails )
{
    int i=0;
    for(;i<memberDetails.size();i++)
        if( strcmp(memberDetails.at(i).IDNumber,IDNumber)==0 )
            break;
    if(i==memberDetails.size())
        return false;
    if( strcmp(memberDetails.at(i).IDNumber,IDNumber)==0 && strcmp(memberDetails.at(i).password,password)==0 )
        return true;
    return false;
}
void registration( vector< MemberRecord > &memberDetails )
{
    MemberRecord temp;
    cout <<"Input your ID Number: ";
    cin >> temp.IDNumber;
    if( !(legalID(temp.IDNumber)) )
    {
        cout<<"\nThe ID number "<<temp.IDNumber<<" is illegal.\n"<<endl;
        return;
    }
    else if( existingID(temp.IDNumber,memberDetails) )
    {
        cout << "\nYou are already a member!\n" <<endl;
        return;
    }
    cout << "\nInput your Name: ";
    cin >> temp.name;
    cout << "\nChoose a password: ";
    cin >>temp.password;
    memberDetails.push_back(temp);
    cout << "\nRegistration Completed!\n" << endl;
}
bool legalID( char IDNumber[] )
{
    int temp;
    if( (IDNumber[0]>='A'&&IDNumber[0]<='H') )
        temp=IDNumber[0]-'A'+10;
    else if( (IDNumber[0]>='a'&&IDNumber[0]<='h') )
        temp=IDNumber[0]-'a'+10;
    else if( IDNumber[0]=='I' || IDNumber[0]=='i')
        temp=34;
    else if( (IDNumber[0]>='J'&&IDNumber[0]<='N') )
        temp=IDNumber[0]-'J'+18;
    else if( (IDNumber[0]>='j'&&IDNumber[0]<='n') )
        temp=IDNumber[0]-'j'+18;
    else if( IDNumber[0]=='O' || IDNumber[0]=='o')
        temp=35;
    else if( (IDNumber[0]>='P'&&IDNumber[0]<='V') )
        temp=IDNumber[0]-'P'+23;
    else if( (IDNumber[0]>='p'&&IDNumber[0]<='v') )
        temp=IDNumber[0]-'p'+23;
    else if( IDNumber[0]=='W' || IDNumber[0]=='w')
        temp=32;
    else if( IDNumber[0]=='X' || IDNumber[0]=='x')
        temp=30;
    else if( IDNumber[0]=='Y' || IDNumber[0]=='y')
        temp=31;
    else if( IDNumber[0]=='Z' || IDNumber[0]=='z')
        temp=33;

    if( (((temp/10)+(temp%10)*9+(IDNumber[1]-'0')*8+(IDNumber[2]-'0')*7+(IDNumber[3]-'0')*6+(IDNumber[4]-'0')*5+(IDNumber[5]-'0')*4+(IDNumber[6]-'0')*3+(IDNumber[7]-'0')*2+(IDNumber[8]-'0')*1+(IDNumber[9]-'0')*1)%10) == 0 )
        return true;
    return false;
}
bool existingID( char IDNumber[], const vector< MemberRecord > &memberDetails )
{
    for(int i=0;i<memberDetails.size();i++)
        if( strcmp(IDNumber,memberDetails[i].IDNumber)==0 )
            return true;
    return false;
}
void saveMemberDetails( const vector< MemberRecord > &memberDetails )
{
    fstream file;
    file.open("Members.dat",ios::out|ios::binary);
    if(!file)
    {
        cout<<"save error"<<endl;
        return;
    }
    for(int i=0;i<memberDetails.size();i++)
        file.write( reinterpret_cast <const char*> (&memberDetails[i]) ,sizeof(MemberRecord));
    file.close();
}
