#ifndef LOADING_H
#define LOADING_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string.h>
#include <vector>
using namespace std;

struct Reservation
{
    char reservationNumber[12]; // used to identify a reservation
    char trainNumber[8];  // used to identify a train
    char idNumber[12];    // the id number of the contact person
    char phone[12];       // the (local or mobile) phone number of the contact person
    char date[12];        // outbound date
    int originStation;      // the origin station code
    int destinationStation; // the destination station code
    int carClass;           // the car class code; 1:standard car, 2:business car
    int adultTickets;       // the number of adult tickets
    int concessionTickets;  // the number of concession tickets
};

struct Train
{
    char trainNumber[8];          // used to identify a train
    char departureTimes[13][8]; // the departure time of a train for each station,
};

int inputAnInteger(int begin, int end);

void loadSouthboundTimetable(Train southboundTimetable[100], int& numSouthboundTrains);

void loadNorthboundTimetable(Train northboundTimetable[100], int& numNorthboundTrains);

#include "Booking.h"
#include "Booking_History.h"

#endif // !LOADING_H
