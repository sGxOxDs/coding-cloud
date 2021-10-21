// Bridge Pattern: Hide Implementation in C++
#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TimeImp;

class Time {
    public:
        Time(){}
        Time(int hr, int min);
        virtual void tell();
    protected:
        TimeImp *impl;
};

class CivilianTime: public Time {
    public:
        CivilianTime(int hr, int min, int pm);
};

class ZuluTime: public Time {
    public:
        ZuluTime(int hr, int min, int zone);
};

#endif // TIME_H
