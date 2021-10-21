#include "Time.h"

int main() {
    Time *times[3];
    times[0] = new Time(14, 30);
    times[1] = new CivilianTime(2, 30, 1);
    times[2] = new ZuluTime(14, 30, 6);
    for (int i = 0; i < 3; i++)
        times[i]->tell();
}

