#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
#include <stdlib.h>

#include <pcf8591.h>



int main (void)
{


    wiringPiSetup();

	pcf8591Setup (120, 0x48); 



	int a;



		
	a=analogRead(120);
	printf("Pin 4f:");
	printf("%d\n",a);
	
	
	FILE *f = fopen("test.txt", "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}


	/* print integers and floats */
	int i = a;
	fprintf(f, "%d", i);



	fclose(f);

    
    return 0;
}
