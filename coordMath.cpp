/*
 *  coordMath.cpp
 *  Equatorial2Galactic
 *
 *  Created by psinclai on 27/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "coordMath.h"

void mmult3x3(double a[3][3], double r[3], double m[3]) {
	int i;
	
	for (i = 0; i < 3; i++) {
		m[i] = a[i][0]*r[0] + a[i][1]*r[1] + a[i][2]*r[2];
	}
	
}

double DegreesToRadians(double Degrees)
{
    return Degrees * 0.017453292519943295769236907684886;
}

double RadiansToDegrees(double Radians)
{
    return Radians * 57.295779513082320876798154814105;
}

double RaHmsToDegrees(double hr, double min, double sec)
{
    double deg;
    
    deg = (hr / 24.0 * 360.0) + (min / 60.0) + (sec / 3600.0);
    
    return deg;
    
}

double DecDmsToDegrees(double degrees, double min, double sec)
{
    double deg;
    
    if (degrees >= 0) {
        deg = degrees + (min / 60.0) + (sec / 3600.0);
    } else {
        deg = degrees - (min / 60.0) - (sec / 3600.0);
    }
    
    return deg;
    
}

void minv3x3(double a[3][3], double ai[3][3]) {
	double det;
	
	det = (a[0][0] * a[1][1] * a[2][2]) - (a[0][0] * a[1][2] * a[2][1]) -
		  (a[0][1] * a[1][0] * a[2][2]) + (a[0][1] * a[1][2] * a[2][0]) +
		  (a[0][2] * a[1][0] * a[2][1]) - (a[0][2] * a[1][1] * a[2][0]);
	
	ai[0][0] = a[0][0] / det;
	ai[0][1] = a[1][0] / det;
	ai[0][2] = a[2][0] / det;
	ai[1][0] = a[0][1] / det;
	ai[1][1] = a[1][1] / det;
	ai[1][2] = a[2][1] / det;
	ai[2][0] = a[0][2] / det;
	ai[2][1] = a[1][2] / det;
	ai[2][2] = a[2][2] / det;
	
}

double roundDecplaces(double x) {

	return (round(x * DECPLACES) / DECPLACES);
}
