// Sidereal Time Header
#ifndef SiderealTime_H
#define SiderealTime_H

#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>

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

        int dayOfYear();

		// this could be void and use hours instead of Hours
		int timeZoneHours();

		int time[3] = { timeZoneHours(),minutes,seconds }; // time in UTC Greenwich

		double J0 = (367 * year) - trunc(7 * (year + trunc((month + 9) / 12)) / 4) + trunc(275 * month / 9) + day + 1721013.5;
		double julianDay = J0 + (hours + minutes / 60 + seconds / 3600) / 24;
		double T0 = (J0 - 2451545) / 36525;
		double thetaG0 = 100.4606184+36000.77004*T0+0.000387933*pow(T0,2.0)-2.583*pow(10,-8)*pow(T0,3.0)-trunc((100.4606184+36000.77004*T0+0.000387933*pow(T0,2.0)-2.583*pow(10,-8)*pow(T0,3.0))/360)*360;
		double thetaG = thetaG0 + 360.98564724*(hours + minutes / 60 + seconds / 3600) / 24;

		double theta();

		double sideTime = theta() / 360;
};
#endif
