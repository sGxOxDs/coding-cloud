#include "Booking.h"

void Booking::execute()
{
    inputReservationDetails();
    if (reservation.originStation < reservation.destinationStation)
    {
        loadSouthboundTimetable();
        selectSouthboundTrain();
    }
    else
    {
        loadNorthboundTimetable();
        selectNorthboundTrain();
    }

    inputContactInfo();
    saveReservation(reservation);
}

// inputs originStation, destinationStation, carClass,
// date, departureTime, adultTickets and concessionTickets
void Booking::inputReservationDetails()
{
    do {
        do {
            cout << "\nOrigin Station" << endl
                << "1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan" << endl
                << "5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua" << endl
                << "9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying" << endl
                << "? ";
        } while ((reservation.originStation = inputAnInteger(1, 12)) == -1);
        do {
            cout << "\nDestination Station" << endl
                << "1. Nangang\n2. Taipei\n3. Banqiao\n4. Taoyuan" << endl
                << "5. Hsinchu\n6. Miaoli\n7. Taichung\n8. Changhua" << endl
                << "9. Yunlin\n10. Chiayi\n11. Tainan\n12. Zuoying" << endl
                << "? ";
        } while ((reservation.destinationStation = inputAnInteger(1, 12)) == -1);
    } while (reservation.originStation == reservation.destinationStation);

    if ((reservation.originStation == 1 && reservation.destinationStation == 2) || (reservation.originStation == 2 && reservation.destinationStation == 1))
    {
        do {
            cout << "\nCar Class" << endl
                << "1. Standard Car" << endl
                << "? ";
        } while ((reservation.carClass = inputAnInteger(1, 1)) == -1);
    }
    else if ((reservation.originStation == 1 && reservation.destinationStation == 3) || (reservation.originStation == 3 && reservation.destinationStation == 1))
    {
        do {
            cout << "\nCar Class" << endl
                << "1. Standard Car" << endl
                << "? ";
        } while ((reservation.carClass = inputAnInteger(1, 1)) == -1);
    }
    else if ((reservation.originStation == 2 && reservation.destinationStation == 3) || (reservation.originStation == 3 && reservation.destinationStation == 2))
    {
        do {
            cout << "\nCar Class" << endl
                << "1. Standard Car" << endl
                << "? ";
        } while ((reservation.carClass = inputAnInteger(1, 1)) == -1);
    }
    else
    {
        do {
            cout << "\nCar Class" << endl
                << "1. Standard Car" << endl
                << "2. Business Car" << endl
                << "? ";
        } while ((reservation.carClass = inputAnInteger(1, 2)) == -1);
    }


    cout << "\nDeparture Date: ";
    cin >> reservation.date;

    do {
        cout << "\nDeparture Time" << endl;
        for (int i = 1; i <= 34; i++)
            cout << setw(2) << i << ". " << departureTimes[i] << endl;
        cout << "? ";
    } while ((departureTime = inputAnInteger(1, 34)) == -1);

    do {
        do {
            cout << "\nHow many adult tickets? ";
        } while ((reservation.adultTickets = inputAnInteger(0, 99999)) == -1);
        do {
            cout << "\nHow many concession tickets? ";
        } while ((reservation.concessionTickets = inputAnInteger(0, 99999)) == -1);
    } while (reservation.adultTickets + reservation.concessionTickets <= 0);
}

// displays timetables for 10 coming southbound trains, then let user select one
void Booking::selectSouthboundTrain()
{
    cout << endl << setw(12) << "Train No." << setw(12) << "Departure" << setw(12) << "Arrival" << endl;
    int ten = 0;
    Train temp_train[10];
    for (int i = 0; i < numSouthboundTrains && ten < 10; i++)
        if (strcmp(departureTimes[departureTime], southboundTimetable[i].departureTimes[reservation.originStation]) <= 0)
            if (!(strcmp("-", southboundTimetable[i].departureTimes[reservation.destinationStation]) == 0))
            {
                cout << setw(12) << southboundTimetable[i].trainNumber
                    << setw(12) << southboundTimetable[i].departureTimes[reservation.originStation]
                    << setw(12) << southboundTimetable[i].departureTimes[reservation.destinationStation] << endl;
                temp_train[ten] = southboundTimetable[i];
                ten++;
            }
    int flag;
    do {
        flag = 0;
        cout << "Enter Train Number: ";
        cin >> reservation.trainNumber;
        for (int i = 0; i < ten; i++)
            if (strcmp(reservation.trainNumber, temp_train[i].trainNumber) == 0)
            {
                flag = 1;
                break;
            }
    } while (flag == 0);
    cout << "\nTrip Details" << endl;
    char stations[13][12] = { "","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying" };
    char carClass[3][12] = { "","Standard","Business" };
    display(reservation, southboundTimetable, stations, carClass[reservation.carClass]);
}

// displays timetables for 10 coming northbound trains, then let user select one
void Booking::selectNorthboundTrain()
{
    cout << endl << setw(12) << "Train No." << setw(12) << "Departure" << setw(12) << "Arrival" << endl;
    int ten = 0;
    Train temp_train[10];
    for (int i = 0; i < numNorthboundTrains && ten < 10; i++)
        if (strcmp(departureTimes[departureTime], northboundTimetable[i].departureTimes[reservation.originStation]) <= 0)
            if (!(strcmp("-", northboundTimetable[i].departureTimes[reservation.destinationStation]) == 0))
            {
                cout << setw(12) << northboundTimetable[i].trainNumber
                    << setw(12) << northboundTimetable[i].departureTimes[reservation.originStation]
                    << setw(12) << northboundTimetable[i].departureTimes[reservation.destinationStation] << endl;
                temp_train[ten] = northboundTimetable[i];
                ten++;
            }
    int flag;
    do {
        flag = 0;
        cout << "Enter Train Number: ";
        cin >> reservation.trainNumber;
        for (int i = 0; i < ten; i++)
            if (strcmp(reservation.trainNumber, temp_train[i].trainNumber) == 0)
            {
                flag = 1;
                break;
            }
    } while (flag == 0);
    cout << "\nTrip Details" << endl;
    char stations[13][12] = { "","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying" };
    char carClass[3][12] = { "","Standard","Business" };
    display(reservation, northboundTimetable, stations, carClass[reservation.carClass]);
}

// inputs idNumber and phone, and randomly generate reservationNumber
void Booking::inputContactInfo()
{
    cout << "\nEnter Contact Person Information" << endl
        << "\nID Number: ";
    cin >> reservation.idNumber;
    cout << "\nPhone: ";
    cin >> reservation.phone;
    for (int i = 0; i < 8; i++)
        reservation.reservationNumber[i] = rand() % 10 + '0';
    reservation.reservationNumber[8] = '\0';
    cout << "\nReservation Number: " << reservation.reservationNumber << endl;
    cout << "\nReservation Completed!" << endl;
}