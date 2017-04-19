/*
 *  eq2gal.cpp
 *  Equatorial2Galactic
 *
 *  Created by psinclai on 28/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "eq2gal.h"
#include "coordMath.h"

void eq2gal(double ra, double de) {

	int n;
	double g[3], r[3], AGi[3][3];
	double b, l, lA, lB, lC, lD, lE;

	// Get galactic coord vector g
	r0(ra, de, r);
	minv3x3(AG, AGi);
	mmult3x3(AGi, r, g);
	
	// Optional values for different vector elements, rounded for comparison test
	b = asin(g[2]); //galactic latitude
	
	lA = roundDecplaces(acos(g[0] / cos(b)));
	lB = roundDecplaces(asin(g[1] / cos(b)));
	lC = roundDecplaces(PI - asin(g[1] / cos(b)));
	lD = roundDecplaces(acos(-g[0] / cos(b)));
	lE = roundDecplaces(PI - acos(-g[0] / cos(b)));

	// Calculate galactic longitude l by testing options to see how many are equal	
	n = 1;
	if (lA == lB) 
		n++;
	
	if (lA == lC)
	    n++;
	
	if (lA == lD)
	    n++;
	
	if (lA == lE)
	    n++;
	
	if (n == 2)
		l = (PI * 2) - lA;
	else if (n > 2)
		l = lA;
	else
		l = DegreesToRadians(9999);  // error condition	
	
	//Galactic coords in degrees
	lA = RadiansToDegrees(lA);
	lB = RadiansToDegrees(lB);
	lC = RadiansToDegrees(lC);
	lD = RadiansToDegrees(lD);
	lE = RadiansToDegrees(lE);
	l = RadiansToDegrees(l);
	b = RadiansToDegrees(b);
		
	// printf("%11.8f %11.8f %11.8f %11.8f\n", RadiansToDegrees(ra), RadiansToDegrees(de), l, b);
    printf("%11.8f %11.8f %11.8f %11.8f\n", ra, de, l, b);
}

void r0 (double ra, double de, double *r) {
	
	ra = DegreesToRadians(ra);
	de = DegreesToRadians(de);
	
	r[0] = cos(de) * cos(ra);
	r[1] = cos(de) * sin(ra);
	r[2] = sin(de);
	
}

	
