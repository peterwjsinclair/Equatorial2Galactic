/*
 *  coordMath.h
 *  Equatorial2Galactic
 *
 *  Created by psinclai on 27/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535897932384626433832795
#define DECPLACES 100000

double DegreesToRadians(double Degrees);
double RadiansToDegrees(double Radians);
void mmult3x3(double a[3][3], double r[3], double m[3]);
void minv3x3(double a[3][3], double ai[3][3]);
double roundDecplaces(double x);
double RaHmsToDegrees(double hr, double min, double sec);
double DecDmsToDegrees(double deg, double min, double sec);
