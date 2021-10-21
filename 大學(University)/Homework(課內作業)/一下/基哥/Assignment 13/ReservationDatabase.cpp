// ReservationDatabase.cpp
// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <fstream>
using namespace std;
#include "ReservationDatabase.h"

// ReservationDatabase default constructor loads reservations from the file Reservation details.dat
ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

// ReservationDatabase destructor stores reservations into the file Reservation details.dat
ReservationDatabase::~ReservationDatabase()
{
   storeReservations();
}

void ReservationDatabase::loadReservations()
{
    fstream file("Reservation details.dat", ios::in | ios::binary);
    if (file)
    {
        Reservation temp_data;
        for (; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));)
            reservations.push_back(temp_data);
        file.close();
    }
}

void ReservationDatabase::storeReservations()
{
    fstream file("Reservation details.dat", ios::out | ios::binary);
    for (int i = 0; i < reservations.size(); i++)
        file.write(reinterpret_cast<const char*> (&reservations[i]), sizeof(Reservation));
}

bool ReservationDatabase::exist( string idNumber, string reservationNumber )
{
   // loop through reservations searching for matching idNumber and reservationNumber
   for( vector< Reservation >::iterator it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getIdNumber() == idNumber && it->getReservationNumber() == reservationNumber )
         return true; // return true if match found

   return false; // if no matching reservation was found, return false
}

void ReservationDatabase::displayReservation( string idNumber, string reservationNumber )
{
   vector< Reservation >::iterator it = searchReservation( idNumber, reservationNumber );
   it->displayReservationDetails();
}

void ReservationDatabase::cancelReservation( string idNumber, string reservationNumber )
{
   vector< Reservation >::iterator it = searchReservation( idNumber, reservationNumber );
   reservations.erase( it );
   cout << "Reservation Cancelled.\n\n";
}

void ReservationDatabase::addReservation( Reservation reservation )
{
   reservations.push_back( reservation );
}

void ReservationDatabase::reduceSeats( string idNumber, string reservationNumber )
{
    vector< Reservation >::iterator it = searchReservation(idNumber, reservationNumber);

    int cancel_a = 0;
    int cancel_c = 0;
    do {
        cout << "\nHow many adult tickets to cancel? ";
        cin >> cancel_a;
    } while (cancel_a<0 || cancel_a>it->getAdultTickets());
    do {
        cout << "\nHow many concession tickets to cancel? ";
        cin >> cancel_c;
    } while (cancel_c<0 || cancel_c>it->getConcessionTickets());

    it->setAdultTickets(it->getAdultTickets() - cancel_a);
    it->setConcessionTickets(it->getConcessionTickets() - cancel_c);
    it->displayReservationDetails();

    cout << "\nYou have successfully reduced the number of tickets!" << endl;
}

vector< Reservation >::iterator ReservationDatabase::searchReservation( string idNumber, string reservationNumber )
{
   // loop through reservations searching for matching idNumber and reservationNumber
   for( vector< Reservation >::iterator it = reservations.begin(); it != reservations.end(); ++it )
      if( it->getIdNumber() == idNumber && it->getReservationNumber() == reservationNumber )
         return it; // return iterator to thecurrent reservation if match found

   return reservations.end();
}