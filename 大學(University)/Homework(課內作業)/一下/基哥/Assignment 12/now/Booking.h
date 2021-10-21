#ifndef BOOKING_H
#define BOOKING_H

class Booking
{
public:
	Booking(Train t_southboundTimetable[100], Train t_northboundTimetable[100]) {
		southboundTimetable = t_southboundTimetable;
		northboundTimetable = t_northboundTimetable;
	};
	void execute();
private:
	Reservation reservation;
	int departureTime;
	Train* southboundTimetable;
	Train* northboundTimetable;
	int numSouthboundTrains = 0;
	int numNorthboundTrains = 0;
	void inputReservationDetails();
	void selectSouthboundTrain();
	void selectNorthboundTrain();
	void inputContactInfo();
};

#endif // !BOOKING_HISTORY_H