// Convert equatorial to galactic coordinates using modern astrometric method
// (c) Peter W J Sinclair 2008

#include "Equatorial2Galactic.h"
#include "coordMath.h"

int main (int argc, char * const argv[]) {
	double ra, de;
	
	// check args	
	if (argc < 3) {
		fprintf(stderr, "\nUsage: %s ra_deg, de_deg\n", argv[0]);
		exit(1);
	}
	
	printf("Equatorial to galactic coordinate conversion\n");
	printf("RA Dec GLong GLat\n");
	
    if (argc > 3) {
        ra = RaHmsToDegrees(atof(argv[1]), atof(argv[2]), atof(argv[3]));
        de = DecDmsToDegrees(atof(argv[4]), atof(argv[5]), atof(argv[6]));
    } else {
        ra = atof(argv[1]);
        de = atof(argv[2]);
    }
	
	eq2gal(ra, de);
    
	return 0;
}

	

