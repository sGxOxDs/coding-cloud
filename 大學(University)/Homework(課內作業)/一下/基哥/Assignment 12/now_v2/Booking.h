#include "Booking_System.h"
#ifndef BOOKING_H
#define BOOKING_H

class Booking:public Booking_System
{
public:
	Booking() {};
	void execute();
private:
	Reservation reservation;
	int departureTime;
	void inputReservationDetails();
	void selectSouthboundTrain();
	void selectNorthboundTrain();
	void inputContactInfo();
};

#endif // !BOOKING_HISTORY_H