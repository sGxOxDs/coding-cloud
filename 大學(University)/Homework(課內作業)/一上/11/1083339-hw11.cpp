#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <string.h>
using namespace::std;

char foods[ 14 ][ 48 ] = { "",
                           "Pork XiaoLongBao (12)",
                           "Steamed Vegetable and Ground Pork Dumplings (8)",
                           "Steamed Shrimp and Pork Dumplings (8)",
                           "Steamed Fish Dumplings (8)",
                           "Steamed Vegetarian Mushroom Dumplings (8)",
                           "Steamed Shrimp and Pork Shao Mai (12)",
                           "Pork Buns (5)",
                           "Vegetable and Ground Pork Buns (5)",
                           "Red Bean Buns (5)",
                           "Sesame Buns (5)",
                           "Taro Buns (5)",
                           "Vegetarian Mushroom Buns (5)",
                           "Golden Lava Buns (5)" };

int price[ 14 ] = { 0, 220, 176, 216, 200, 200, 432, 225,
                       225, 200, 200, 225, 250, 225 };

struct Date
{
   int year;
   int month;
   int day;
};

struct Account
{
   char email[ 40 ]; // used as the account number
   char password[ 20 ];
   char name[ 12 ];
   char address[ 80 ];
   char phone[ 12 ];
   int cart[ 14 ]; // Cart[i] is the quantity of food #i in the shopping cart
};

struct Order
{
   char orderNumber[ 12 ];
   char email[ 40 ];
   Date deliveryDate;
   Date arrivalDate;
   int quantity[ 14 ]; // quantity[i] is the quantity of food #i in the order
};

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

// add a new account to the file Accounts.dat
void registration( vector< Account > &accountDetails );

// return true if email belongs to accountDetails
bool exists( char email[], const vector< Account > &accountDetails );

// save all elements in accountDetails to the file Accounts.dat
void saveAllAccounts( const vector< Account > &accountDetails );

// login and call shopping
void login( vector< Account > &accountDetails );

// load all accounts details from the file Accounts.dat
void loadAccountDetails( vector< Account > &accountDetails );

// return true if there exists an account with specified email and password; and
// put the account with specified email and password into account
bool valid( char email[], char password[], Account &account,
            const vector< Account > &accountDetails );

// add chosen Foods to the shopping cart
void shopping( Account &account );

// return true if the shopping cart is empty
bool emptyCart( const Account &account );

// display the shopping cart in account
bool displayCart( const Account &account );

// append account in the file Accounts.dat
void saveAccount( const Account &account );

// update the shopping cart in account
void updateCart( Account &account );

// generate a Bill and reset account.cart
void check( Account &account );

// compute the current date
void compCurrentDate( Date &currentDate );

// open the file Orders.txt and call displayOrderDetails twice
void createOrder( const Account &account, const Order &order );

// write an order to Orders.txt or display it on the output window depending on os
void displayOrderDetails( ostream &os, const Account &account, const Order &order );

int main()
{
   vector< Account > accountDetails; // account details for all accounts

   cout << "Welcome to DintaiFung Shopping Mall!\n";
   srand( static_cast< int >( time( 0 ) ) );

   int choice;

   while( true )
   {
      cout << "\n1 - Registration\n";
      cout << "2 - Login\n";
      cout << "3 - End\n";

      do cout << "\nEnter your choice (1~3): ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      cout << endl;

      switch( choice )
      {
      case 1:
         registration( accountDetails );
         break;

      case 2:
         login( accountDetails );
         break;

      case 3:
         cout << "Thank you! Goodbye!\n\n";
         system( "pause" );
         return 0;
      }
   }

   system( "pause" );
}

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end ) //error
{
    char in[33];
    int temp=0;
    cin >> in;
    for(int i=0;in[i]!='\0';i++)
        if(!isdigit(in[i]))
            return -1;
    for(int i=0;in[i]!='\0';i++,temp*=10)
        temp+=(in[i]-'0');
    temp/=10;
    if(temp>=begin&&temp<=end)
       return temp;
    return -1;
}

// add a new account to the file Accounts.dat
void registration( vector< Account > &accountDetails )
{
    loadAccountDetails( accountDetails );
    Account temp;
    cout <<"Email address (Account number): ";
    cin >> temp.email;
    if( exists(temp.email,accountDetails) )
    {
        cout << "\nYou are already a member!\n" <<endl;
        return;
    }
    cout << "\nPassword: ";
    cin >>temp.password;
    cout << "\nName: ";
    cin >> temp.name;
    cout<< "\nShipping address: ";
    cin>>temp.address;
    cout<< "\nContact phone number: ";
    cin>>temp.phone;
    for(int i=0;i<14;i++)
        temp.cart[i]=0;
    accountDetails.push_back(temp);
    saveAllAccounts( accountDetails );
    cout << "\nRegistration Completed!\n" << endl;
}

// return true if email belongs to accountDetails
bool exists( char email[], const vector< Account > &accountDetails )
{
    for(int i=0;i<accountDetails.size();i++)
        if( strcmp(email,accountDetails[i].email)==0 )
            return true;
    return false;
}

// save all elements in accountDetails to the file Accounts.dat
void saveAllAccounts( const vector< Account > &accountDetails )
{
    fstream file;
    file.open("Accounts.dat",ios::out|ios::binary);
    if(!file)
    {
        cout<<"save Accounts error"<<endl;
        return;
    }
    for(int i=0;i<accountDetails.size();i++)
        file.write( reinterpret_cast <const char*> (&accountDetails[i]) ,sizeof(Account));
    file.close();
}

// login and call shopping
void login( vector< Account > &accountDetails )
{
    loadAccountDetails( accountDetails );
    Account temp;
    Account select;
    cout << "Email address (0 to end): ";
    cin >> temp.email;
    if(strcmp(temp.email,"0")==0)
        return;
    cout << "\nPassword: ";
    cin >> temp.password;

    while( !valid(temp.email,temp.password,select,accountDetails) )
    {
        cout << "\nInvalid account number or password. Please try again." << endl;
        cout << "\nEmail address (0 to end): ";
        cin >> temp.email;
        if(strcmp(temp.email,"0")==0)
            return;
        cout << "\nPassword: ";
        cin >> temp.password;
    }
    shopping(select);
}

// load all accounts details from the file Accounts.dat
void loadAccountDetails( vector< Account > &accountDetails )
{
    accountDetails.clear();
    fstream file;
    file.open("Accounts.dat",ios::in|ios::binary);
    if(!file)
        return;

    Account temp;
    for(int i=0;file.read( reinterpret_cast <char*> (&temp) ,sizeof(Account));i++)
        accountDetails.push_back(temp);
    file.close();
}

// return true if there exists an account with specified email and password; and
// put the account with specified email and password into account
bool valid( char email[], char password[], Account &account,
            const vector< Account > &accountDetails )
{
    for(int i=0;i<accountDetails.size();i++)
        if( strcmp(accountDetails.at(i).email,email)==0 && strcmp(accountDetails.at(i).password,password)==0)
        {
            account = accountDetails.at(i);
            return true;
        }
    return false;
}

// add chosen Foods to the shopping cart
void shopping( Account &account )
{
    while(true)
    {
        //shopping
        int choice_max=13;
        for(int i=1;i<14;i++)
            cout<<setw(4)<<i<<". "<<setw(50)<<foods[i]<<setw(6)<<price[i]<<endl;
        cout<<endl;
        if( !emptyCart(account) )
        {
            cout<<setw(4)<<"14"<<". "<<setw(50)<<"View your shopping cart"<<endl;
            choice_max=14;
        }
        int choice;
        do cout << "\nEnter your choice (0 to logout): ";
        while( ( choice = inputAnInteger( 0, choice_max ) ) == -1 );
        cout << endl;
        switch ( choice )
        {
            case 0:
                return;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
                int quantity;
                cout<<"Enter the quantity: ";
                cin>>quantity;
                account.cart[choice]+=quantity;
            case 14:
                break;
            default:
                cout << "\nIncorrect choice!\n";
                break;
        }
        //update done
        while(true)
        {
            displayCart( account );
            saveAccount( account );
            cout<<"\n1. Continue Shopping\n2. Update Cart\n3. Check"<<endl;
            do cout << "\nEnter your choice (1~3): ";
            while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
            cout << endl;
            switch ( choice )
            {
                case 1:
                    break;
                case 2:
                    updateCart( account );
                    break;
                case 3:
                    check( account );
                    return;
                default:
                    cout << "\nIncorrect choice!\n";
                    break;
            }
            if(choice==1)
                break;
        }
    }
}

// return true if the shopping cart is empty
bool emptyCart( const Account &account )
{
    for(int i=0;i<14;i++)
        if(account.cart[i]!=0)
            return false;
    return true;
}

// display the shopping cart in account
bool displayCart( const Account &account )
{
    cout<<"Your Shopping Cart Contents: "<<endl<<endl;
    int total=0;
    for(int i=0;i<14;i++)
    {
        if(i==0)
            cout<<setw(6)<<"Code"<<setw(50)<<"Item"<<setw(6)<<"Price"
                <<setw(10)<<"Quantity"<<setw(10)<<"Subtotal"<<endl;
        else if(account.cart[i]!=0)
        {
            cout<<setw(6)<<i<<setw(50)<<foods[i]<<setw(6)<<price[i]
                <<setw(10)<<account.cart[i]<<setw(10)<<price[i]*account.cart[i]<<endl;
            total+=price[i]*account.cart[i];
        }
    }
    cout<<endl<<"Total Cost: "<<total<<endl;
    return true;
}

// append account in the file Accounts.dat
void saveAccount( const Account &account )
{
    vector <Account> tempaccount;
    fstream file;
    file.open("Accounts.dat",ios::in|ios::binary);
    if(!file)
        return;
    Account temp;
    for(int i=0;file.read( reinterpret_cast <char*> (&temp) ,sizeof(Account));i++)
        tempaccount.push_back(temp);
    file.close();

    for(int i=0;i<tempaccount.size();i++)
        if(strcmp(tempaccount[i].email,account.email)==0)
        {
            for(int j=0;j<14;j++)
                tempaccount[i].cart[j]=account.cart[j];
            break;
        }

    file.open("Accounts.dat",ios::out|ios::binary);
    if(!file)
        return;
    for(int i=0;i<tempaccount.size();i++)
        file.write( reinterpret_cast <const char*> (&tempaccount[i]) ,sizeof(Account));
    file.close();
}

// update the shopping cart in account
void updateCart( Account &account )
{
    int code;
    do cout << "\nEnter the product code: ";
    while( ( code = inputAnInteger( 1, 13 ) ) == -1 || account.cart[code]==0);

    int quantity;
    do cout << "\nEnter the quantity: ";
    while( ( quantity = inputAnInteger( 0, 100 ) ) == -1 );

    account.cart[code]=quantity;
}

// generate a Bill and reset account.cart
void check( Account &account )
{
    Order order;
    compCurrentDate(order.deliveryDate);
    cout<<"Enter arrival dateDate"<<endl;
    cout<<"year: ";
    cin>>order.arrivalDate.year;
    cout<<"month: ";
    cin>>order.arrivalDate.month;
    cout<<"day: ";
    cin>>order.arrivalDate.day;
    strcpy(order.email,account.email);
    for(int i=0;i<14;i++)
    {
        order.quantity[i]=account.cart[i];
        account.cart[i]=0;
    }
    createOrder( account, order );
    saveAccount( account );
}

// compute the current date
void compCurrentDate( Date &currentDate )
{
    time_t now;
    time(&now);
    currentDate.year=localtime(&now)->tm_year+1900;
    currentDate.month=localtime(&now)->tm_mon+1;
    currentDate.day=localtime(&now)->tm_mday;
}

// open the file Orders.txt and call displayOrderDetails twice
void createOrder( const Account &account, const Order &order )
{
    ofstream file("Orderstest.txt",ios::out);
    displayOrderDetails( cout, account, order );
    displayOrderDetails( file, account, order );
    cout<<"An order has been created."<<endl;
}

// write an order to Orders.txt or display it on the output window depending on os
void displayOrderDetails( ostream &os, const Account &account, const Order &order )
{
    srand(time(NULL));

    os<<"Order number: ";
    char c='A'+rand()%26;
    os<<c<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10<<rand()%10;
    os<<endl;

    os<<"Delivery Date: "<<order.deliveryDate.year<<"/"<<order.deliveryDate.month<<"/"<<order.deliveryDate.day<<endl;
    os<<"Arrival Date: "<<order.arrivalDate.year<<"/"<<order.arrivalDate.month<<"/"<<order.arrivalDate.day<<endl;
    os<<"Recipient: "<<account.name<<endl;
    os<<"Contact Phone Number: "<<account.phone<<endl;
    os<<"Shipping address: "<<account.address<<endl<<endl;
    os<<"Shopping details:"<<endl<<endl;
    int total=0;
    for(int i=0;i<14;i++)
    {
        if(i==0)
            os<<setw(6)<<"Code"<<setw(50)<<"Item"<<setw(6)<<"Price"
                <<setw(10)<<"Quantity"<<setw(10)<<"Subtotal"<<endl;
        else if(order.quantity[i]!=0)
        {
            os<<setw(6)<<i<<setw(50)<<foods[i]<<setw(6)<<price[i]
                <<setw(10)<<order.quantity[i]<<setw(10)<<price[i]*order.quantity[i]<<endl;
            total+=price[i]*order.quantity[i];
        }
    }
    os<<endl<<"Total Cost: "<<total<<endl;
}
