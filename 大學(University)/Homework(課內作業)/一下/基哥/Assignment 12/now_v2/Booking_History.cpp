#include "Booking_History.h"

void Booking_History::execute()
{
    fstream file("details.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        std::cout << "Not find any Reservation History." << endl;
        return;
    }
    existReservation(file);
    int choice;
    do {
        displayReservations();
        std::cout << "\nEnter Your Choice\n1. Cancellation\n2. Reduce\n3. End\n? ";

    } while ((choice = inputAnInteger(1, 3)) == -1);
    if (choice == 1)
    {
        vector <Reservation> temp = {};
        file.open("details.dat", ios::in | ios::out | ios::binary);
        Reservation temp_data;
        for (int i = 0; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation)); i++)
        {
            temp.push_back(temp_data);
            if (strcmp(temp[i].idNumber, reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber, reservation.reservationNumber) == 0)
            {
                temp[i] = {};
                file.seekg(0, ios::beg);
                for (int j = 0; j < temp.size(); j++)
                    file.write(reinterpret_cast<const char*> (&temp[j]), sizeof(Reservation));
                break;
            }
        }
        file.close();
        std::cout << "\nReservation Cancelled!" << endl;
    }
    else if (choice == 2)
        reduceSeats(file);
}

bool Booking_History::existReservation(fstream& ioFile)
{
    vector <Reservation> temp = {};
    Reservation temp_data;
    for (; ioFile.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));)
        temp.push_back(temp_data);
    ioFile.close();

    int flag = 1;
    do {
        if (flag == 0)
            cout << "Reservation record not found." << endl;
        flag = 0;
        cout << "Enter ID Number: ";
        cin >> reservation.idNumber;
        cout << "Enter Reservation Number: ";
        cin >> reservation.reservationNumber;
        for (int i = 0; i < temp.size(); i++)
            if (strcmp(temp[i].idNumber, reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber, reservation.reservationNumber) == 0)
            {
                reservation = temp[i];
                return false;
            }

    } while (flag == 0);
    return true;
}

void Booking_History::displayReservations()
{
    char stations[13][12] = { "","Nangang","Taipei","Banqiao","Taoyuan",
                                    "Hsinchu","Miaoli","Taichung","Changhua",
                                    "Yunlin","Chiayi","Tainan","Zuoying" };
    char carClass[3][12] = { "","Standard","Business" };

    cout << "\nReservation Details" << endl;

    if (reservation.originStation < reservation.destinationStation)
    {
        loadSouthboundTimetable();
        display(reservation, southboundTimetable, stations, carClass[reservation.carClass]);
    }
    else
    {
        loadNorthboundTimetable();
        display(reservation, northboundTimetable, stations, carClass[reservation.carClass]);
    }
}

// reduces adultTickets and/or concessionTickets in reservation
void Booking_History::reduceSeats(fstream& ioFile)
{
    int cancel_a = 0;
    int cancel_c = 0;
    do {
        cout << "\nHow many adult tickets to cancel? ";
        cin >> cancel_a;
    } while (cancel_a<0 || cancel_a>reservation.adultTickets);
    do {
        cout << "\nHow many concession tickets to cancel? ";
        cin >> cancel_c;
    } while (cancel_c<0 || cancel_c>reservation.concessionTickets);

    reservation.adultTickets -= cancel_a;
    reservation.concessionTickets -= cancel_c;
    displayReservations();

    vector <Reservation> temp = {};
    ioFile.open("details.dat", ios::in | ios::out | ios::binary);
    Reservation temp_data;
    for (int i = 0; ioFile.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation)); i++)
    {
        temp.push_back(temp_data);
        if (strcmp(temp[i].idNumber, reservation.idNumber) == 0 && strcmp(temp[i].reservationNumber, reservation.reservationNumber) == 0)
        {
            if (reservation.adultTickets == 0 && reservation.concessionTickets == 0)
                temp[i] = {};
            else
                temp[i] = reservation;
            ioFile.seekg(0, ios::beg);
            for (int j = 0; j < temp.size(); j++)
                ioFile.write(reinterpret_cast<const char*> (&temp[j]), sizeof(Reservation));
            break;
        }
    }
    ioFile.close();

    cout << "\nYou have successfully reduced the number of tickets!" << endl;
}
