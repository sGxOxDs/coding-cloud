// NorthboundTimetable.cpp
// Member-function definitions for class NorthboundTimetable.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "NorthboundTimetable.h"

extern string departureTimes[ 37 ];

// NorthboundTimetable default constructor
// loads northbound timetable from the file "Northbound timetable.dat"
NorthboundTimetable::NorthboundTimetable()
{
   loadNorthboundTimetable();
}

void NorthboundTimetable::loadNorthboundTimetable()
{
    fstream file("Northbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train));)
    {
        string* temp = new string[14];
        for (int i = 0; i < 13; i++)
        {
            temp[13 - i] = temp_data.getDepartureTimes(i);
        }
            
        Train turn_data(temp_data.getTrainNumber(), temp);
        northboundTimetable.push_back(turn_data);
    }
    file.close();
}

// returns departureTimes[ station ]
string NorthboundTimetable::getDepartureTimes( string trainNumber, int station )
{
   vector< Train >::iterator it = searchTrain( trainNumber );
   return it->getDepartureTimes( station );
}

bool NorthboundTimetable::trainsAvailable( int departureTime,
     int originStation, int destinationStation )
{
    for (int i = 0; i < northboundTimetable.size(); i++)
        if (departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(originStation))
            if ("-" != northboundTimetable[i].getDepartureTimes(destinationStation))
                return true;
    return false;
}

void NorthboundTimetable::displayComingTrains( int departureTime,
     int originStation, int destinationStation )
{
    cout << endl << setw(12) << "Train No." << setw(12) << "Departure" << setw(12) << "Arrival" << endl;
    int ten = 0;
    for (int i = 0; i < northboundTimetable.size() && ten < 10; i++)
        if (departureTimes[departureTime] <= northboundTimetable[i].getDepartureTimes(originStation))
            if ("-" != northboundTimetable[i].getDepartureTimes(destinationStation))
            {
                cout << setw(12) << northboundTimetable[i].getTrainNumber()
                    << setw(12) << northboundTimetable[i].getDepartureTimes(originStation)
                    << setw(12) << northboundTimetable[i].getDepartureTimes(destinationStation) << endl;
                ten++;
            }
}

vector< Train >::iterator NorthboundTimetable::searchTrain( string trainNumber )
{
   vector< Train >::iterator it = northboundTimetable.begin();
   for( ; it != northboundTimetable.end(); ++it )
      if( it->getTrainNumber() == trainNumber )
         return it;

   return northboundTimetable.end();
}