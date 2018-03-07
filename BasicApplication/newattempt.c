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


    while (1) 
    {   
		
		a=analogRead(120);
        printf("Pin 4f:");
        printf("%d\n",a);
        delay(200);

    }   
    return 0;
}
