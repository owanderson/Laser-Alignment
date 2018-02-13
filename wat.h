#include <wiringPi.h>
#include <softPwm.h>

#define PINNUM	0

int main (void)
{
	wiringPiSetup () ;

	pinMode () ;
	
	int softPwmCreate (int PINNUM, int 0, int 100) ;
	
	string userinput ;
	cout << "Position?" ;
	cin >> userinput ;
	 
	void softPwmWrite (int PINNUM, int userinput) ;
}