/*Sidereal Time Calculator
By: Jonathan Tiede
*/

#include "SiderealTime.h"
using namespace std;

int SiderealTime::dayOfYear() {
    int totalDays = 0;
    if (year%4==0) {
        for (size_t i = 1; i <= month; i++) {
            if (i == month) {
                totalDays += day;
            } else if (i == 2) {
                totalDays += 29;
            } else if ((i%2 == 1 && i < 8) || (i%2==0 && i>7 && i<=12)) {
                totalDays += 31;
            } else {
                totalDays += 30;
            }
        }
    } else {
        for (size_t i = 1; i <= month; i++) {
            if (i == month) {
                totalDays += day;
            } else if (i == 2) {
                totalDays += 28;
            } else if ((i % 2 == 1 && i < 8) || (i % 2 == 0 && i>7 && i <= 12)) {
                totalDays += 31;
            } else {
                totalDays += 30;
            }
        }
    }
    return totalDays;
}

int SiderealTime::timeZoneHours() {
    int totalDays = dayOfYear();
    
    if (hours - timeZone < 0) {
        hours = 24 + hours - timeZone;
        totalDays -= 1;
        if (totalDays < 1) { // if time zone causes year to move back one
            year -= 1;
            month = 12;
            day = 31;
            if (year%4==0) {
                totalDays = 366;
            } else {
                totalDays = 365;
            }
        } else { // if time zone doesn't cause year to change
            for (int i = 1; i < totalDays; i++) {
                int j = 1;
                // need to count months and days from totalDays.
            }
        }
        day -= 1; // need to inc. a ticker to tick back days and months (maybe) and years (maybe) and have value be accessible outside of timeZoneHours func.
        month -= 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
        year -= 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
    } else if (hours - timeZone > 23) {
        hours = hours - timeZone - 24;
        totalDays += 1;
        if ((totalDays > 365) && (year % 4 != 0)) {
            
        }
        day += 1; // need to incorporate a ticker to tick up days and months (maybe) and years (maybe) and have value be accessible outside of timeZoneHours func.
        month += 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
        year += 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
    } else {
        hours = hours - timeZone;
    }
    return hours; // Need to also return day, month, year out of this function;
}

double SiderealTime::theta() {
    double decLong = decLongitude();
    if (longitudeDir == "West") decLong *= -1;
    
    if (thetaG + decLong > 360) {
        return thetaG + decLong - trunc((thetaG + decLong) / 360) * 360;
    }
    else {
        return thetaG + decLong;
    }
}
