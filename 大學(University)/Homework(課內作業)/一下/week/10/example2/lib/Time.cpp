// Bridge Pattern: Hide Implementation in C++

#include "Time.h"

// Implementation Class
class TimeImp {
    public:
        TimeImp(int hr, int min);
        virtual void tell();
    protected:
        int hour, minite;
};

TimeImp::TimeImp(int hr, int min) {
        hour = hr;
        minite = min;
}

void TimeImp::tell()
{
        cout << "TimeImp::tell()"<< endl;
        cout << "time is " << setw(2) << hour << minite << endl;
}

// Civilian
class CivilianTimeImp: public TimeImp {
    public:
        CivilianTimeImp(int hr, int min, int pm);
        void tell();
    protected:
        string whichM;
};

CivilianTimeImp::CivilianTimeImp(int hr, int min, int pm): TimeImp(hr, min) {
    if (pm)
      whichM=" PM";
    else
      whichM=" AM";
}

void CivilianTimeImp::tell() {
    cout << "CivilianTimeImp::tell()"<< endl;
    cout << "time is " << hour << ":" << minite << whichM << endl;
}

// Zulu
class ZuluTimeImp: public TimeImp {
    public:
        ZuluTimeImp(int hr, int min, int zone);
        void tell();
    protected:
        string zone;
};

ZuluTimeImp::ZuluTimeImp(int hr, int min, int zn): TimeImp(hr, min) {
    if (zn == 5)
      zone=" Eastern Standard Time";
    else if (zn == 6)
      zone=" Central Standard Time";
}

void ZuluTimeImp::tell() {
    cout << "ZuluTimeImp::tell()"<< endl;
    cout << "time is " << setw(2) << hour << minite << zone << endl;
}

// Normal Class
Time::Time(int hr, int min) {
    impl = new TimeImp(hr, min);
}
void Time::tell() {
    cout << "Time::tell()"<< endl;
    impl->tell();
}

CivilianTime::CivilianTime(int hr, int min, int pm) {
    impl = new CivilianTimeImp(hr, min, pm);
}

ZuluTime::ZuluTime(int hr, int min, int zone) {
    impl = new ZuluTimeImp(hr, min, zone);
}

