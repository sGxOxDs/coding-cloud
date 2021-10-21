#include "Booking_System.h"
#include "Booking.h"
#include "Booking_History.h"

void Booking_System::execute()
{
    cout << "Taiwan High Speed Rail Booking System\n";
    srand(static_cast<unsigned int>(time(0)));

    Booking* booking;
    Booking_History* booking_history;

    int choice; // store user choice

    // enable user to specify action
    while (true)
    {
        cout << "\nEnter Your Choice\n"
            << "1. Booking\n"
            << "2. Booking History\n"
            << "3. End Program";

        do cout << "\n? ";
        while ((choice = inputAnInteger(1, 3)) == -1);
        cout << endl;

        switch (choice)
        {
        case 1:
            booking = new Booking();
            booking->execute();
            delete booking;
            break;
        case 2:
            booking_history = new Booking_History();
            booking_history->execute();
            delete booking_history;
            break;
        case 3:
            cout << "Thank you! Goodbye!\n\n";
            return;
        default: // display error if user does not select valid choice
            cerr << "Incorrect Choice!\n";
            break;
        }
    }
}

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end)
{
    char temp[33];
    int ans = 0;
    cin >> temp;
    for (int i = 0; i < 33 && temp[i] != '\0'; i++)
        if (!isdigit(temp[i]))
            return -1;
    for (int i = 0; isdigit(temp[i]) && i < 33; i++)
    {
        ans *= 10;
        ans += temp[i] - '0';
    }
    if (ans >= begin && ans <= end)
        return ans;
    return -1;
}

// loads the southbound timetable from the file "Southbound timetable.dat"
void Booking_System::loadSouthboundTimetable()
{
    fstream file("Southbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (numSouthboundTrains = 0; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train)); numSouthboundTrains++)
        southboundTimetable[numSouthboundTrains] = temp_data;
    numSouthboundTrains--;
    file.close();
}

// loads the northbound timetable from the file "Northbound timetable.dat"
void Booking_System::loadNorthboundTimetable()
{
    fstream file("Northbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (numNorthboundTrains = 0; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train)); numNorthboundTrains++)
    {
        for (int i = 1; i <= 6; i++)
        {
            char temp[8];
            for (int j = 0; j < 8; j++)
                temp[j] = temp_data.departureTimes[i][j];
            for (int j = 0; j < 8; j++)
                temp_data.departureTimes[i][j] = temp_data.departureTimes[13-i][j];
            for (int j = 0; j < 8; j++)
                temp_data.departureTimes[13 - i][j] = temp[j];
        }

        northboundTimetable[numNorthboundTrains] = temp_data;
    }
        
    numNorthboundTrains--;
    file.close();
    
}

// save reservation to the end of the file Reservation details.dat
void Booking_System::saveReservation(Reservation reservation)
{
    vector <Reservation> temp = {};
    fstream file("details.dat", ios::in | ios::binary);
    if (!file)
    {
        temp.push_back(reservation);
        fstream file("details.dat", ios::out | ios::binary);
        for (int i = 0; i < temp.size(); i++)
            file.write(reinterpret_cast<const char*> (&temp[i]), sizeof(Reservation));
    }
    else
    {
        Reservation temp_data;
        for (; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Reservation));)
            temp.push_back(temp_data);
        file.close();
        fstream file("details.dat", ios::out | ios::binary);
        temp.push_back(reservation);
        for (int i = 0; i < temp.size(); i++)
            file.write(reinterpret_cast<const char*> (&temp[i]), sizeof(Reservation));
    }
    file.close();
}

// displays date, originStation, destinationStation, departureTime, arrival time,
// fare for adultTickets, fare for concessionTickets and total fare
void Booking_System::display(Reservation reservation, Train trainTimetable[100],
    char stations[13][12], char carClass[12])
{
    cout << setw(12) << "Date" << setw(12) << "Train No."
        << setw(12) << "From" << setw(12) << "To"
        << setw(12) << "Departure" << setw(12) << "Arrival"
        << setw(12) << "Adult" << setw(12) << "Concession"
        << setw(12) << "Fare" << setw(12) << "Class" << endl;

    cout << setw(12) << reservation.date << setw(12) << reservation.trainNumber
        << setw(12) << stations[reservation.originStation] << setw(12) << stations[reservation.destinationStation];
    for (int i = 0; i < 100; i++)
        if (strcmp(trainTimetable[i].trainNumber, reservation.trainNumber) == 0)
        {
            cout << setw(12) << trainTimetable[i].departureTimes[reservation.originStation]
                << setw(12) << trainTimetable[i].departureTimes[reservation.destinationStation];
            break;
        }

    int price = 0;
    if (reservation.carClass == 1 && reservation.originStation < reservation.destinationStation)
        price = adultTicketPrice[reservation.destinationStation][reservation.originStation];

    else if (reservation.carClass == 1 && reservation.originStation > reservation.destinationStation)
        price = adultTicketPrice[13 - reservation.destinationStation][13 - reservation.originStation];

    else if (reservation.carClass == 2 && reservation.originStation < reservation.destinationStation)
        price = adultTicketPrice[reservation.originStation][reservation.destinationStation];

    else
        price = adultTicketPrice[13 - reservation.originStation][13 - reservation.destinationStation];
    cout << setw(8) << price << setw(1) << "*" << setw(3) << reservation.adultTickets << setw(8) << price / 2 << setw(1) << "*" << setw(3) << reservation.concessionTickets;
    cout << setw(12) << price * reservation.adultTickets + price / 2 * reservation.concessionTickets << setw(12) << carClass << endl;
}
