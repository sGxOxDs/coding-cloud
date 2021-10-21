// FlightSchedule.cpp
// Member-function definitions for class SouthboundTimetable.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SouthboundTimetable.h"

extern string departureTimes[ 37 ];

// SouthboundTimetable default constructor
// loads southbound timetable from the file "Southbound timetable.dat"
SouthboundTimetable::SouthboundTimetable()
{
   loadSouthboundTimetable();
}

void SouthboundTimetable::loadSouthboundTimetable()
{
    fstream file("Southbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train));)
        southboundTimetable.push_back(temp_data);
    file.close();
}

// returns departureTimes[ station ]
string SouthboundTimetable::getDepartureTimes( string trainNumber, int station )
{
   vector< Train >::iterator it = searchTrain( trainNumber );
   return it->getDepartureTimes( station );
}

bool SouthboundTimetable::trainsAvailable( int departureTime,
     int originStation, int destinationStation )
{
    for (int i = 0; i < southboundTimetable.size(); i++)
        if (departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(originStation))
            if ("-" != southboundTimetable[i].getDepartureTimes(destinationStation))
                return true;
    return false;
}

void SouthboundTimetable::displayComingTrains( int departureTime,
     int originStation, int destinationStation )
{
    cout << endl << setw(12) << "Train No." << setw(12) << "Departure" << setw(12) << "Arrival" << endl;
    int ten = 0;
    for (int i = 0; i < southboundTimetable.size() && ten < 10; i++)
        if (departureTimes[departureTime] <= southboundTimetable[i].getDepartureTimes(originStation))
            if ("-" != southboundTimetable[i].getDepartureTimes(destinationStation))
            {
                cout << setw(12) << southboundTimetable[i].getTrainNumber()
                    << setw(12) << southboundTimetable[i].getDepartureTimes(originStation)
                    << setw(12) << southboundTimetable[i].getDepartureTimes(destinationStation) << endl;
                ten++;
            }
}

vector< Train >::iterator SouthboundTimetable::searchTrain( string trainNumber )
{
   vector< Train >::iterator it = southboundTimetable.begin();
   for( ; it != southboundTimetable.end(); ++it )
      if( it->getTrainNumber() == trainNumber )
         return it;

   return southboundTimetable.end();
}