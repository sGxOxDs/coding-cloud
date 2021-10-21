#include "Loading.h"

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
void loadSouthboundTimetable(Train southboundTimetable[100], int& numSouthboundTrains)
{
    fstream file("Southbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (numSouthboundTrains=0; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train)); numSouthboundTrains++)
        southboundTimetable[numSouthboundTrains] = temp_data;
    numSouthboundTrains--;
    file.close();
}

// loads the northbound timetable from the file "Northbound timetable.dat"
void loadNorthboundTimetable(Train northboundTimetable[100], int& numNorthboundTrains)
{
    fstream file("Northbound timetable.dat", ios::in, ios::binary);
    Train temp_data;
    for (numNorthboundTrains = 0; file.read(reinterpret_cast<char*> (&temp_data), sizeof(Train)); numNorthboundTrains++)
        northboundTimetable[numNorthboundTrains] = temp_data;    
    numNorthboundTrains--;
    file.close();
}