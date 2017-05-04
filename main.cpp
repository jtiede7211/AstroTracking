//
//  main.cpp
//  Planet Tracker
//
//  Created by Jonathan Tiede and Frankie Pereda on 5/4/17.
//  Copyright © 2017 Jonathan Tiede and Frankie Pereda. All rights reserved.
//

#include "SiderealTime.h"

int main() {
    SiderealTime sidereal;
    cout << setprecision(15) << sidereal.timeZoneHours() << "\n";
    system("pause");
}
