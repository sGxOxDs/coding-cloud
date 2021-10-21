// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include <iomanip>
#include "MakingReservation.h" // MakingReservation class definition

extern int inputAnInteger( int begin, int end );

extern string departureTimes[ 37 ];

// MakingReservation constructor
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
                                      SouthboundTimetable &theSouthboundTimetable,
                                      NorthboundTimetable &theNorthboundTimetable )
   : reservationDatabase( theReservationDatabase ),
     southboundTimetable( theSouthboundTimetable ),
     northboundTimetable( theNorthboundTimetable )
{
}

void MakingReservation::execute()
{
   if( chooseTrain() ) // displays timetables for 10 coming trains, then let user choose a train
   {
      inputReservationDetails();

      inputContactPersonInfo();

      reservationDatabase.addReservation( reservation );

      cout << "\nReservation Completed!\n\n";
   }
   else
      cout << "\nSorry! No train is available!\n\n";
}

bool MakingReservation::chooseTrain()
{
    do {
        do {
            cout << "\nOrigin Station" << endl
                << "1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan" << endl
                << "5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua" << endl
                << "9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying" << endl
                << "? ";
            reservation.setOriginStation( inputAnInteger(1, 12) );
        } while (reservation.getOriginStation() == -1);
        do {
            cout << "\nDestination Station" << endl
                << "1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan" << endl
                << "5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua" << endl
                << "9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying" << endl
                << "? ";
            reservation.setDestinationStation(inputAnInteger(1, 12));
        } while (reservation.getDestinationStation() == -1);
    } while (reservation.getOriginStation() == reservation.getDestinationStation());

    int departureTime;
    do {
        cout << "\nDeparture Time" << endl;
        for (int i = 1; i <= 34; i++)
            cout << setw(2) << i << ". " << departureTimes[i] << endl;
        cout << "? ";
    } while ((departureTime = inputAnInteger(1, 34)) == -1);

    string t_trainNumber;
    if (reservation.getOriginStation() < reservation.getDestinationStation())
    {
        if (southboundTimetable.trainsAvailable(departureTime,
            reservation.getOriginStation(),
            reservation.getDestinationStation()))
        {
            southboundTimetable.displayComingTrains(departureTime,
                reservation.getOriginStation(),
                reservation.getDestinationStation());
            //do {
                cout << "Enter Train Number: ";
                cin >> t_trainNumber;
                reservation.setTrainNumber(t_trainNumber);
                
            //} while (southboundTimetable.getDepartureTimes(t_trainNumber, reservation.getOriginStation()) != departureTimes[departureTime]);
        }
        else
            return false;
    }
    else
    {
        if (northboundTimetable.trainsAvailable(departureTime,
            reservation.getOriginStation(),
            reservation.getDestinationStation()))
        {
            northboundTimetable.displayComingTrains(departureTime,
                reservation.getOriginStation(),
                reservation.getDestinationStation());
            //do {
                cout << "Enter Train Number: ";
                cin >> t_trainNumber;
                reservation.setTrainNumber(t_trainNumber);
            //} while (northboundTimetable.getDepartureTimes(t_trainNumber, reservation.getOriginStation()) != departureTimes[departureTime]);
        }
        else
            return false;
    }
        
    return true;
}

void MakingReservation::inputReservationDetails()
{
   cout << "\nCar Class\n" << "1. Standard Car\n" << "2. Business Car";

   int carClass;
   do cout << "\n? ";
   while( ( carClass = inputAnInteger( 1, 2 ) ) == -1 );
   reservation.setCarClass( carClass );

	cout << "\nDeparture Date: ";

   char date[12];
   cin >> date;
   reservation.setDate( date );
   cin.ignore();

	cout << "\nHow many adult tickets? ";

   int adultTickets;
   cin >> adultTickets;
   reservation.setAdultTickets( adultTickets );

	cout << "\nHow many concession tickets? ";

   int concessionTickets;
   cin >> concessionTickets;
   reservation.setConcessionTickets( concessionTickets );

   cout << "\nTrip Details\n";
   reservation.displayReservationDetails();
}

void MakingReservation::inputContactPersonInfo()
{
   cout << "\nEnter Contact Person Information\n\n";

   cout << "ID Number: ";
   string idNumber;
   cin >> idNumber;
   reservation.setIdNumber( idNumber );

   cout << "\nPhone: ";
   string phone;
   cin >> phone;
   cin.ignore();
   reservation.setPhone( phone );

   srand( static_cast< unsigned int >( time( 0 ) ) );
   char reservationNumber[ 12 ];
   for( int i = 0; i < 8; i++ )
      reservationNumber[ i ] = rand() % 10 + '0';
   reservationNumber[ 8 ] = '\0';
   reservation.setReservationNumber( reservationNumber );
   
	cout << "\nReservation Number: " << reservationNumber << endl;
}