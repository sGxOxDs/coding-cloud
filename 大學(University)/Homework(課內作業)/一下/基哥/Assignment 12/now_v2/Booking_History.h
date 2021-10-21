#include "Booking_System.h"
#ifndef BOOKING_HISTORY_H
#define BOOKING_HISTORY_H

class Booking_History:public Booking_System
{
public:
	Booking_History() {};
	void execute();
private:
	Reservation reservation;
	bool existReservation(fstream& ioFile);

	void displayReservations();

	// reduces adultTickets and/or concessionTickets in reservation
	void reduceSeats(fstream& ioFile);
};

#endif // !BOOKING_HISTORY_H
