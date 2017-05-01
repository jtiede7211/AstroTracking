/*Sidereal Time Calculator
By: Jonathan Tiede
*/

#include "SiderealTime.h"
#include <iomanip>
using namespace std;

int main() {	
	SiderealTime sidereal;
	cout << setprecision(15) << sidereal.timeZoneHours() << "\n";
	system("pause");

}