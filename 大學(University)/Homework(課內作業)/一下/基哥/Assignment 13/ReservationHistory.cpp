#include <iostream>
#include "ReservationHistory.h" // ReservationHistory class definition

extern int inputAnInteger( int begin, int end );

// ReservationHistory default constructor
ReservationHistory::ReservationHistory( ReservationDatabase &theReservationDatabase,
                                        SouthboundTimetable &theSouthboundTimetable,
                                        NorthboundTimetable &theNorthboundTimetable )
   : idNumber(),
     reservationNumber(),
     reservationDatabase( theReservationDatabase ),
     southboundTimetable( theSouthboundTimetable ),
     northboundTimetable( theNorthboundTimetable )
{
} // end ReservationHistory default constructor

void ReservationHistory::execute()
{
    cout << "Enter ID Number: ";
    cin >> idNumber;
    cout << "Enter Reservation Number: ";
    cin >> reservationNumber;
    if (!reservationDatabase.exist(idNumber, reservationNumber))
    {
        cout << "Reservation record not found." << endl;
        return;
    }

    int choice;
    do {
        reservationDatabase.displayReservation(idNumber, reservationNumber);
        cout << "\nEnter Your Choice\n1. Cancellation\n2. Reduce\n3. End\n? ";

    } while ((choice = inputAnInteger(1, 3)) == -1);
    if (choice == 1)
    {
        reservationDatabase.cancelReservation(idNumber, reservationNumber);
        cout << "\nReservation Cancelled!" << endl;
    }
    else if (choice == 2)
        reservationDatabase.reduceSeats(idNumber, reservationNumber);
}