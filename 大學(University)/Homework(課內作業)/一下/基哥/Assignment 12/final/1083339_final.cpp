#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string.h>
#include <vector>
using namespace std;

int adultTicketPrice[ 13 ][ 13 ] = {
   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,  500,  700,  920, 1330, 1510, 1660, 1880, 2290, 2500,
   0,   40,    0,    0,  440,  640,  850, 1250, 1430, 1600, 1820, 2230, 2440,
   0,   70,   40,    0,  400,  590,  800, 1210, 1390, 1550, 1780, 2180, 2390,
   0,  200,  160,  130,    0,  400,  620, 1010, 1210, 1370, 1580, 1990, 2200,
   0,  330,  290,  260,  130,    0,  410,  820, 1010, 1160, 1390, 1790, 2000,
   0,  480,  430,  400,  280,  140,    0,  610,  790,  950, 1160, 1580, 1790,
   0,  750,  700,  670,  540,  410,  270,    0,  400,  550,  770, 1180, 1390,
   0,  870,  820,  790,  670,  540,  390,  130,    0,  370,  580, 1000, 1210,
   0,  970,  930,  900,  780,  640,  500,  230,  110,    0,  430,  830, 1040,
   0, 1120, 1080, 1050,  920,  790,  640,  380,  250,  150,    0,  620,  820,
   0, 1390, 1350, 1320, 1190, 1060,  920,  650,  530,  420,  280,    0,  410,
   0, 1530, 1490, 1460, 1330, 1200, 1060,  790,  670,  560,  410,  140,    0 };

char departureTimes[ 37 ][ 8 ] = { "",
   "06:00", "06:30", "07:00", "07:30", "08:00", "08:30", "09:00", "09:30",
   "10:00", "10:30", "11:00", "11:30", "12:00", "12:30", "13:00", "13:30",
   "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30",
   "18:00", "18:30", "19:00", "19:30", "20:00", "20:30", "21:00", "21:30",
   "22:00", "22:30", "23:00", "23:30" };

struct Reservation
{
   char reservationNumber[ 12 ]; // used to identify a reservation
   char trainNumber[ 8 ];  // used to identify a train
   char idNumber[ 12 ];    // the id number of the contact person
   char phone[ 12 ];       // the (local or mobile) phone number of the contact person
   char date[ 12 ];        // outbound date
   int originStation;      // the origin station code
   int destinationStation; // the destination station code
   int carClass;           // the car class code; 1:standard car, 2:business car
   int adultTickets;       // the number of adult tickets
   int concessionTickets;  // the number of concession tickets
};

struct Train
{
   char trainNumber[ 8 ];          // used to identify a train
   char departureTimes[ 13 ][ 8 ]; // the departure time of a train for each station,
};                                 // departureTimes[0] is not used

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end );

void makingReservation( Train southboundTimetable[ 100 ], Train northboundTimetable[ 100 ] );

// inputs originStation, destinationStation, carClass,
// date, departureTime, adultTickets and concessionTickets
void inputReservationDetails( Reservation &reservation, int &departureTime );

// loads the southbound timetable from the file "Southbound timetable.dat"
void loadSouthboundTimetable( Train southboundTimetable[ 100 ], int &numSouthboundTrains );

// loads the northbound timetable from the file "Northbound timetable.dat"
void loadNorthboundTimetable( Train northboundTimetable[ 100 ], int &numNorthboundTrains );

// displays timetables for 10 coming southbound trains, then let user select one
void selectSouthboundTrain( Train southboundTimetable[ 100 ], int numSouthboundTrains,
                            Reservation &reservation, int departureTime );

// displays timetables for 10 coming northbound trains, then let user select one
void selectNorthboundTrain( Train northboundTimetable[ 100 ], int numNorthboundTrains,
                            Reservation &reservation, int departureTime );

// inputs idNumber and phone, and randomly generate reservationNumber
void inputContactInfo( Reservation &reservation );

// save reservation to the end of the file Reservation details.dat
void saveReservation( Reservation reservation );

void reservationHistory( Train southboundTimetable[ 100 ],
                         Train northboundTimetable[ 100 ] );

// inputs idNumber and reservationNumber, and
// checks if the corresponding reservation exists
bool existReservation( fstream &ioFile, Reservation &reservation );


void displayReservations( Train southboundTimetable[ 100 ],
                          Train northboundTimetable[ 100 ], Reservation reservation );

// displays date, originStation, destinationStation, departureTime, arrival time,
// fare for adultTickets, fare for concessionTickets and total fare
void display( Reservation reservation, Train trainTimetable[ 100 ],
              char stations[ 13 ][ 12 ], char carClass[ 12 ] );

// reduces adultTickets and/or concessionTickets in reservation
void reduceSeats( fstream &ioFile, Train southboundTimetable[ 100 ],
                  Train northboundTimetable[ 100 ], Reservation &reservation );

int main()
{
   cout << "Taiwan High Speed Rail Booking System\n";
   srand( static_cast< unsigned int >( time( 0 ) ) );

   Train southboundTimetable[ 100 ];
   Train northboundTimetable[ 100 ];
   int choice; // store user choice

   // enable user to specify action
   while( true )
   {
      cout << "\nEnter Your Choice\n"
         << "1. Booking\n"
         << "2. Booking History\n"
         << "3. End Program";

      do cout << "\n? ";
      while( ( choice = inputAnInteger( 1, 3 ) ) == -1 );
      cout << endl;

      switch( choice )
      {
      case 1:
         makingReservation( southboundTimetable, northboundTimetable );
         break;
      case 2:
         reservationHistory( southboundTimetable, northboundTimetable );
         break;
      case 3:
         cout << "Thank you! Goodbye!\n\n";
         system( "pause" );
         return 0;
      default: // display error if user does not select valid choice
         cerr << "Incorrect Choice!\n";
         break;
      }
   }

   system( "pause" );
} // end main

// input an integer in the range [ begin, end ]
int inputAnInteger( int begin, int end )
{
    char temp[33];
    int ans=0;
    cin>>temp;
    for(int i=0;i<33 && temp[i]!='\0';i++)
        if( !isdigit(temp[i]) )
            return -1;
    for(int i=0;isdigit(temp[i]) && i<33;i++)
    {
        ans*=10;
        ans+=temp[i]-'0';
    }
    if( ans>=begin && ans<=end )
        return ans;
    return -1;
}

void makingReservation( Train southboundTimetable[ 100 ], Train northboundTimetable[ 100 ] )
{
    Reservation temp_reservation;
    int temp_departureTime;

    int numSouthboundTrains = 0;
    int numNorthboundTrains = 0;

    inputReservationDetails(temp_reservation, temp_departureTime);

    if( temp_reservation.originStation < temp_reservation.destinationStation )
    {
        loadSouthboundTimetable(southboundTimetable, numSouthboundTrains);
        selectSouthboundTrain(southboundTimetable, numSouthboundTrains, temp_reservation, temp_departureTime);
    }
    else
    {
        loadNorthboundTimetable(northboundTimetable, numNorthboundTrains);
        selectNorthboundTrain(northboundTimetable, numNorthboundTrains, temp_reservation, temp_departureTime);
    }

    inputContactInfo(temp_reservation);
    saveReservation(temp_reservation);
}

// inputs originStation, destinationStation, carClass,
// date, departureTime, adultTickets and concessionTickets
void inputReservationDetails( Reservation &reservation, int &departureTime )
{
    do{
        do{
            cout<<"\nOrigin Station"<<endl
                <<"1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan"<<endl
                <<"5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua"<<endl
                <<"9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying"<<endl
                <<"? ";
        } while ( (reservation.originStation=inputAnInteger(1,12)) == -1 );
        do{
            cout<<"\nDestination Station"<<endl
                <<"1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan"<<endl
                <<"5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua"<<endl
                <<"9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying"<<endl
                <<"? ";
        } while ( (reservation.destinationStation=inputAnInteger(1,12)) == -1 );
    } while( reservation.originStation == reservation.destinationStation );

    if( (reservation.originStation==1&&reservation.destinationStation==2)||(reservation.originStation==2&&reservation.destinationStation==1))
    {
        do{
            cout<<"\nCar Class"<<endl
                <<"1. Standard Car"<<endl
                <<"? ";
        } while( (reservation.carClass=inputAnInteger(1,1)) == -1 );
    }
    else if( (reservation.originStation==1&&reservation.destinationStation==3)||(reservation.originStation==3&&reservation.destinationStation==1))
    {
        do{
            cout<<"\nCar Class"<<endl
                <<"1. Standard Car"<<endl
                <<"? ";
        } while( (reservation.carClass=inputAnInteger(1,1)) == -1 );
    }
    else if( (reservation.originStation==2&&reservation.destinationStation==3)||(reservation.originStation==3&&reservation.destinationStation==2))
    {
        do{
            cout<<"\nCar Class"<<endl
                <<"1. Standard Car"<<endl
                <<"? ";
        } while( (reservation.carClass=inputAnInteger(1,1)) == -1 );
    }
    else
    {
        do{
            cout<<"\nCar Class"<<endl
                <<"1. Standard Car"<<endl
                <<"2. Business Car"<<endl
                <<"? ";
        } while( (reservation.carClass=inputAnInteger(1,2)) == -1 );
    }


    cout<<"\nDeparture Date: ";
    cin>>reservation.date;

    do{
        cout<<"\nDeparture Time"<<endl;
        for(int i=1;i<=34;i++)
            cout<<setw(2)<<i<<". "<<departureTimes[i]<<endl;
        cout<<"? ";
    } while( (departureTime=inputAnInteger(1,34)) == -1 );

    do{
        do{
            cout<<"\nHow many adult tickets? ";
        } while( (reservation.adultTickets=inputAnInteger(0,99999)) == -1 );
        do{
            cout<<"\nHow many concession tickets? ";
        } while( (reservation.concessionTickets=inputAnInteger(0,99999)) == -1 );
    } while(reservation.adultTickets+reservation.concessionTickets <= 0);
}

// loads the southbound timetable from the file "Southbound timetable.dat"
void loadSouthboundTimetable( Train southboundTimetable[ 100 ], int &numSouthboundTrains )
{
    fstream file("Southbound timetable.txt",ios::in);
    for(numSouthboundTrains=0;!file.eof();numSouthboundTrains++)
    {
        file>>southboundTimetable[numSouthboundTrains].trainNumber;
        for(int i=1;i<=12;i++)
            file>>southboundTimetable[numSouthboundTrains].departureTimes[i];
    }
    numSouthboundTrains--;
    file.close();
}

// loads the northbound timetable from the file "Northbound timetable.dat"
void loadNorthboundTimetable( Train northboundTimetable[ 100 ], int &numNorthboundTrains )
{
    fstream file("Northbound timetable.txt",ios::in);
    for(numNorthboundTrains=0;!file.eof();numNorthboundTrains++)
    {
        file>>northboundTimetable[numNorthboundTrains].trainNumber;
        for(int i=12;i>=1;i--)
            file>>northboundTimetable[numNorthboundTrains].departureTimes[i];
    }
    numNorthboundTrains--;
    file.close();
}

// displays timetables for 10 coming southbound trains, then let user select one
void selectSouthboundTrain( Train southboundTimetable[ 100 ], int numSouthboundTrains,
                            Reservation &reservation, int departureTime )
{
    cout<<endl<<setw(12)<<"Train No."<<setw(12)<<"Departure"<<setw(12)<<"Arrival"<<endl;
    int ten = 0;
    Train temp_train[10];
    for(int i=0;i<numSouthboundTrains && ten<10;i++)
        if( strcmp(departureTimes[departureTime],southboundTimetable[i].departureTimes[reservation.originStation]) <= 0 )
            if( !(strcmp("-",southboundTimetable[i].departureTimes[reservation.destinationStation]) == 0) )
            {
                cout<<setw(12)<<southboundTimetable[i].trainNumber
                    <<setw(12)<<southboundTimetable[i].departureTimes[reservation.originStation]
                    <<setw(12)<<southboundTimetable[i].departureTimes[reservation.destinationStation]<<endl;
                temp_train[ten]=southboundTimetable[i];
                ten++;
            }
    int flag;
    do{
        flag=0;
        cout<<"Enter Train Number: ";
        cin>>reservation.trainNumber;
        for(int i=0;i<ten;i++)
            if(strcmp(reservation.trainNumber,temp_train[i].trainNumber) == 0)
            {
                flag=1;
                break;
            }
    } while(flag==0);
    cout<<"\nTrip Details"<<endl;
    char stations[ 13 ][ 12 ] = {"","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying"};
    char carClass[3][ 12 ] = {"","Standard","Business"};
    display(reservation,southboundTimetable,stations,carClass[reservation.carClass]);
}

// displays timetables for 10 coming northbound trains, then let user select one
void selectNorthboundTrain( Train northboundTimetable[ 100 ], int numNorthboundTrains,
                            Reservation &reservation, int departureTime )
{
    cout<<endl<<setw(12)<<"Train No."<<setw(12)<<"Departure"<<setw(12)<<"Arrival"<<endl;
    int ten = 0;
    Train temp_train[10];
    for(int i=0;i<numNorthboundTrains && ten<10;i++)
        if( strcmp(departureTimes[departureTime],northboundTimetable[i].departureTimes[reservation.originStation]) <= 0 )
            if( !(strcmp("-",northboundTimetable[i].departureTimes[reservation.destinationStation]) == 0) )
            {
                cout<<setw(12)<<northboundTimetable[i].trainNumber
                    <<setw(12)<<northboundTimetable[i].departureTimes[reservation.originStation]
                    <<setw(12)<<northboundTimetable[i].departureTimes[reservation.destinationStation]<<endl;
                temp_train[ten]=northboundTimetable[i];
                ten++;
            }
    int flag;
    do{
        flag=0;
        cout<<"Enter Train Number: ";
        cin>>reservation.trainNumber;
        for(int i=0;i<ten;i++)
            if(strcmp(reservation.trainNumber,temp_train[i].trainNumber) == 0)
            {
                flag=1;
                break;
            }
    } while(flag==0);
    cout<<"\nTrip Details"<<endl;
    char stations[ 13 ][ 12 ] = {"","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying"};
    char carClass[3][ 12 ] = {"","Standard","Business"};
    display(reservation,northboundTimetable,stations,carClass[reservation.carClass]);
}

// inputs idNumber and phone, and randomly generate reservationNumber
void inputContactInfo( Reservation &reservation )
{
    cout<<"\nEnter Contact Person Information"<<endl
        <<"\nID Number: ";
    cin>>reservation.idNumber;
    cout<<"\nPhone: ";
    cin>>reservation.phone;
    for(int i=0;i<8;i++)
        reservation.reservationNumber[i]=rand()%10+'0';
    reservation.reservationNumber[8]='\0';
    cout<<"\nReservation Number: "<<reservation.reservationNumber<<endl;
    cout<<"\nReservation Completed!"<<endl;
}

// save reservation to the end of the file Reservation details.dat
void saveReservation( Reservation reservation )
{
    vector <Reservation> temp = {};
    fstream file("details.dat",ios::in|ios::binary);
    if(!file)
    {
        temp.push_back(reservation);
        fstream file("details.dat",ios::out|ios::binary);
        for(int i=0;i<temp.size();i++)
            file.write(reinterpret_cast<const char*> (&temp[i]), sizeof(Reservation) );
    }
    else
    {
        Reservation temp_data;
        for(;file.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));)
            temp.push_back(temp_data);
        file.close();
        fstream file("details.dat",ios::out|ios::binary);
        temp.push_back(reservation);
        for(int i=0;i<temp.size();i++)
            file.write(reinterpret_cast<const char*> (&temp[i]), sizeof(Reservation));
    }
    file.close();
}

void reservationHistory( Train southboundTimetable[ 100 ],
                         Train northboundTimetable[ 100 ] )
{
    fstream file("details.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
        cout<<"Not find any Reservation History."<<endl;
        return;
    }
    Reservation temp_reservation;
    existReservation(file,temp_reservation);
    int choice;
    do{
        displayReservations( southboundTimetable, northboundTimetable, temp_reservation);
        cout<<"\nEnter Your Choice\n1. Cancellation\n2. Reduce\n3. End\n? ";

    } while( (choice=inputAnInteger(1,3)) == -1 );
    if(choice==1)
    {
        vector <Reservation> temp = {};
        file.open("details.dat",ios::in|ios::out|ios::binary);
        Reservation temp_data;
        for(int i=0;file.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));i++)
        {
            temp.push_back(temp_data);
            if(strcmp(temp[i].idNumber,temp_reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber,temp_reservation.reservationNumber) == 0 )
            {
                temp[i] = {};
                file.seekg(0,ios::beg);
                for(int j=0;j<temp.size();j++)
                    file.write(reinterpret_cast<const char*> (&temp[j]), sizeof(Reservation));
                break;
            }
        }
        file.close();
        cout<<"\nReservation Cancelled!"<<endl;
    }
    else if(choice==2)
        reduceSeats(file, southboundTimetable, northboundTimetable, temp_reservation);
}

// inputs idNumber and reservationNumber, and
// checks if the corresponding reservation exists
bool existReservation( fstream &ioFile, Reservation &reservation )
{
    vector <Reservation> temp = {};
    Reservation temp_data;
    for(;ioFile.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));)
            temp.push_back(temp_data);
    ioFile.close();

    int flag=1;
    do{
        if(flag==0)
            cout<<"Reservation record not found."<<endl;
        flag=0;
        cout<<"Enter ID Number: ";
        cin>>reservation.idNumber;
        cout<<"Enter Reservation Number: ";
        cin>>reservation.reservationNumber;
        for(int i=0;i<temp.size();i++)
            if(strcmp(temp[i].idNumber,reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber,reservation.reservationNumber) == 0 )
            {
                reservation=temp[i];
                return false;
            }

    } while(flag==0);
	return true;
}


void displayReservations( Train southboundTimetable[ 100 ],
                          Train northboundTimetable[ 100 ], Reservation reservation )
{
    int numSouthboundTrains = 0;
    int numNorthboundTrains = 0;

    char stations[ 13 ][ 12 ] = {"","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying"};
    char carClass[3][ 12 ] = {"","Standard","Business"};

    cout<<"\nReservation Details"<<endl;

    if( reservation.originStation < reservation.destinationStation )
    {
        loadSouthboundTimetable(southboundTimetable, numSouthboundTrains);
        display(reservation,southboundTimetable,stations,carClass[reservation.carClass]);
    }
    else
    {
        loadNorthboundTimetable(northboundTimetable, numNorthboundTrains);
        display(reservation,northboundTimetable,stations,carClass[reservation.carClass]);
    }
}

// displays date, originStation, destinationStation, departureTime, arrival time,
// fare for adultTickets, fare for concessionTickets and total fare
void display( Reservation reservation, Train trainTimetable[ 100 ],
              char stations[ 13 ][ 12 ], char carClass[ 12 ] )
{
    cout<<setw(12)<<"Date"<<setw(12)<<"Train No."
        <<setw(12)<<"From"<<setw(12)<<"To"
        <<setw(12)<<"Departure"<<setw(12)<<"Arrival"
        <<setw(12)<<"Adult"<<setw(12)<<"Concession"
        <<setw(12)<<"Fare"<<setw(12)<<"Class"<<endl;

    cout<<setw(12)<<reservation.date<<setw(12)<<reservation.trainNumber
        <<setw(12)<<stations[reservation.originStation]<<setw(12)<<stations[reservation.destinationStation];
    for(int i=0;i<100;i++)
        if( strcmp(trainTimetable[i].trainNumber,reservation.trainNumber) == 0 )
        {
            cout<<setw(12)<<trainTimetable[i].departureTimes[reservation.originStation]
                <<setw(12)<<trainTimetable[i].departureTimes[reservation.destinationStation];
            break;
        }

    int price=0;
    if(reservation.carClass==1 && reservation.originStation<reservation.destinationStation)
        price=adultTicketPrice[reservation.destinationStation][reservation.originStation];
    else if(reservation.carClass==1 && reservation.originStation>reservation.destinationStation)
        price=adultTicketPrice[reservation.originStation][reservation.destinationStation];
    else if(reservation.carClass==2 && reservation.originStation<reservation.destinationStation)
        price=adultTicketPrice[reservation.originStation][reservation.destinationStation];
    else
        price=adultTicketPrice[reservation.destinationStation][reservation.originStation];
    cout<<setw(8)<<price<<setw(1)<<"*"<<setw(3)<<reservation.adultTickets<<setw(8)<<price/2<<setw(1)<<"*"<<setw(3)<<reservation.concessionTickets;
    cout<<setw(12)<<price*reservation.adultTickets+price/2*reservation.concessionTickets<<setw(12)<<carClass<<endl;
}

// reduces adultTickets and/or concessionTickets in reservation
void reduceSeats( fstream &ioFile, Train southboundTimetable[ 100 ],
                  Train northboundTimetable[ 100 ], Reservation &reservation )
{
    int cancel_a = 0;
    int cancel_c = 0;
    do{
        cout<<"\nHow many adult tickets to cancel? ";
        cin>>cancel_a;
    } while(cancel_a<0||cancel_a>reservation.adultTickets);
    do{
        cout<<"\nHow many concession tickets to cancel? ";
        cin>>cancel_c;
    } while(cancel_c<0||cancel_c>reservation.concessionTickets);

    reservation.adultTickets-=cancel_a;
    reservation.concessionTickets-=cancel_c;
    displayReservations(southboundTimetable, northboundTimetable, reservation);

    vector <Reservation> temp = {};
    ioFile.open("details.dat",ios::in|ios::out|ios::binary);
    Reservation temp_data;
    for(int i=0;ioFile.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));i++)
    {
        temp.push_back(temp_data);
        if(strcmp(temp[i].idNumber,reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber,reservation.reservationNumber) == 0 )
        {
            if( reservation.adultTickets == 0 && reservation.concessionTickets == 0)
                temp[i] = {};
            else
                temp[i] = reservation;
            ioFile.seekg(0,ios::beg);
            for(int j=0;j<temp.size();j++)
                ioFile.write(reinterpret_cast<const char*> (&temp[j]), sizeof(Reservation));
            break;
        }
    }
    ioFile.close();

    cout<<"\nYou have successfully reduced the number of tickets!"<<endl;
}
