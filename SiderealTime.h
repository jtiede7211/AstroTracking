// Sidereal Time Header
#ifndef SiderealTime_H
#define SiderealTime_H
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class SiderealTime {
	private:
		//Defining variables
		int day = 22;
		int month = 7;
		int year = 2018;
		int hours = 5;
		int minutes = 28;
		int seconds = 24;
		int timeZone = 7; // time zone value. Florida is -5. California is -8.

		double latitude[3] = { 28,5,41.8 };
		string latitudeDir = "North"; // Should be "North" or "South"
		double longitude[3] = { 80,34,2.7 };
		string longitudeDir = "West"; // Should be "West" or "East"

	public:
		double decLongitude() {
			return longitude[0] + longitude[1] / 60 + longitude[2] / 3600;
		};

		double decLatitude() {
			return latitude[0] + latitude[1] / 60 + latitude[2] / 3600;
		};

		int dayOfYear() {
			int totalDays = 0;
			if (year%4==0) {
				for (size_t i = 1; i <= month; i++) {
					if (i == month) {
						totalDays += day;
					}
					else if (i == 2) {
						totalDays += 29;
					}
					else if ((i%2 == 1 && i < 8) || (i%2==0 && i>7 && i<=12)) {
						totalDays += 31;
					}
					else {
						totalDays += 30;
					}
				}
			}
			else {
				for (size_t i = 1; i <= month; i++) {
					if (i == month) {
						totalDays += day;
					}
					else if (i == 2) {
						totalDays += 28;
					}
					else if ((i % 2 == 1 && i < 8) || (i % 2 == 0 && i>7 && i <= 12)) {
						totalDays += 31;
					}
					else {
						totalDays += 30;
					}
				}
			}
			return totalDays;
		};

		// this could be void and use hours instead of Hours
		int timeZoneHours() {
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
					}
					else {
						totalDays = 365;
					}
				}
				else { // if time zone doesn't cause year to change
					for (int i = 1; i < totalDays; i++) {
						int j = 1;
						// need to count months and days from totalDays.
					}
				}
				day -= 1; // need to inc. a ticker to tick back days and months (maybe) and years (maybe) and have value be accessible outside of timeZoneHours func.
				month -= 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
				year -= 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
			}
			else if (hours - timeZone > 23) {
				hours = hours - timeZone - 24;
				totalDays += 1;
				if ((totalDays > 365 && year % 4 != 0) || ()) {

				}
				day += 1; // need to incorporate a ticker to tick up days and months (maybe) and years (maybe) and have value be accessible outside of timeZoneHours func.
				month += 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
				year += 1; // this may not always be the case. Make if statement and have value be accessible outside of timeZoneHours func.
			}
			else {
				hours = hours - timeZone;
			}
			return hours // Need to also return day, month, year out of this function;
		};

		int time[3] = { timeZoneHours(),minutes,seconds }; // time in UTC Greenwich

		double J0 = (367 * year) - trunc(7 * (year + trunc((month + 9) / 12)) / 4) + trunc(275 * month / 9) + day + 1721013.5;
		double julianDay = J0 + (hours + minutes / 60 + seconds / 3600) / 24;
		double T0 = (J0 - 2451545) / 36525;
		double thetaG0 = 100.4606184+36000.77004*T0+0.000387933*pow(T0,2.0)-2.583*pow(10,-8)*pow(T0,3.0)-trunc((100.4606184+36000.77004*T0+0.000387933*pow(T0,2.0)-2.583*pow(10,-8)*pow(T0,3.0))/360)*360;
		double thetaG = thetaG0 + 360.98564724*(hours + minutes / 60 + seconds / 3600) / 24;

		double theta() {
			double decLong = decLongitude();
			if (longitudeDir == "West") { double decLong = -1 * decLongitude(); }

			if (thetaG + decLong > 360) {
				return thetaG + decLong - trunc((thetaG + decLong) / 360) * 360;
			}
			else {
				return thetaG + decLong;
			}
		};

		double sideTime = theta() / 360;
};
#endif