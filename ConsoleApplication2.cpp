#include "stdafx.h" // Uncomment this line if using Visual Studio
#include <iostream>
#include <string>

using namespace std;

bool align_bool;
int photodiode_0 = 0, photodiode_1 = 0, photodiode_2 = 0, photodiode_3 = 0;


int photodiode(int photodiode_reading) {
	photodiode_1 = photodiode_0;
	photodiode_2 = photodiode_1;
	photodiode_3 = photodiode_2;

	photodiode_0 = photodiode_reading;

	if (/* LOCAL PEAK OBSERVED AT PHOTODIODE_2 */) {
		goto label2;
	}
}


int align() {
	label1:
	string ans;
	cout << "Align? y/n" << endl;
	cin >> ans;
	if (ans == "y") {
		align_bool = 1;
	}
	if (ans == "n") {
		goto label1;
	}
	return 0;
}

int photodiode_initialise() {
	/* Read in photodiode background levels before taking real measurements */

	int background_level_1, background_level_2;

	/* Flip in P1 and set background_level_1 to current levels and flip out P1 */
	/* Flip in P2 and set background_level_2 to current levels and flip out P2 */
	
}

int main()
{
	/* "While the program is on, but align hasn't been pressed".
	This will be handled by QT calling functions in the command line */

	/* ACTUALLY, it is probably not advantageous to have the bulk 
	of the programming inside QT. We will likely be much better getting 
	QT to call a single script which can run everything else without too much faff
	*/

	bool off = 0;

	while (off != 1) {
		/* SHOW GUI */
		/* INITIALISATION CODE */
		/* TAKE IN DISTANCE MEASUREMENTS */
		/* RASTER_SETUP */
		/* PHOTODIODE BACKGROUND LEVELS */

		/* "While the align button has been pressed, but the
		system is not yet aligned."
		This will also be handled by QT, probably, calling
		functions in the CL.
		*/
		
		align();

		while (align_bool == 1) {
			/* RASTER CODE */
			/* PHOTODIODE READINGS */

			raster_setup();

			for (int n = 0; n < 5; n++) 
			{
				for (int m = 0; m < 9; m++)
				{
					cout << "Move right" << endl;
					/* Do a photodiode reading */
				}
				cout << "Move down" << endl;
				/* Do a photodiode reading */
				cout << "Move down" << endl;
				/* Do a photodiode reading */
				
				for (int o = 0; o < 9; o++)
				{
					cout << "Move left" << endl;
					/* Do a photodiode reading */
				}
				cout << "Move down" << endl;
				/* Do a photodiode reading */
				cout << "Move down" << endl;
				/* Do a photodiode reading */
			}
			label2:
			align_bool = 0;

		}
	}
	if (align_bool == 0) {
		cout << "The system has finished aligning";
	}
}