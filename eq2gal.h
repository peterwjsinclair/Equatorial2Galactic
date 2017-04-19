/*
 *  eq2gal.h
 *  Equatorial2Galactic
 *
 *  Created by psinclai on 28/12/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coordMath.h"

double AG[3][3] = {
-0.0548755604, +0.4941094279, -0.8676661490, 
-0.8734370902, -0.4448296300, -0.1980763734,
-0.4838350155, +0.7469822445, +0.4559837762
};


void r0 (double ra, double de, double *r);
