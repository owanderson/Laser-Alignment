#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <pigpio.h>

/*
# servo_demo.c
# 2016-10-08
# Public Domain

gcc -Wall -pthread -o servo_demo servo_demo.c -lpigpio

sudo ./servo_demo          # Send servo pulses to GPIO 4.
sudo ./servo_demo 23 24 25 # Send servo pulses to GPIO 23, 24, 25.
*/

#define NUM_GPIO 32

#define MIN_WIDTH 1000
#define MAX_WIDTH 2000

int run=1;
int numbrz=0;

int step[NUM_GPIO];
int width[NUM_GPIO];
int used[NUM_GPIO];

int randint(int from, int to)
{
   return (random() % (to - from + 1)) + from;
}

void stop(int signum)
{
   run = 0;
}

int main(int argc, char *argv[])
{
   int i, g;

   if (gpioInitialise() < 0) return -1;

   gpioSetSignalFunc(SIGINT, stop);

   if (argc == 1) used[4] = 1;
   else
   {
     i =1;

     g = atoi(argv[i]);
     if ((g>=0) && (g<NUM_GPIO)) used[g] = 1;

   }

   printf("Sending servos pulses to GPIO");

   for (g=0; g<NUM_GPIO; g++)
   {
      if (used[g])
      {
         printf(" %d", g);
         step[g] = 0;
         if ((step[g] % 2) == 0) step[g] = -step[g];
         width[g] = (atoi(argv[2])*5)+1500;
      }
   }

   printf(", control C to stop.\n");

   while(run)
   {
      for (g=0; g<NUM_GPIO; g++)
      {
         if (used[g])
         {
            gpioServo(g, width[g]);
            numbrz = numbrz + 1;

            // printf("%d %d\n", g, width[g]);

            width[g] += step[g];

            if ((width[g]<MIN_WIDTH) || (width[g]>MAX_WIDTH))
            {
               step[g] = -step[g];
               width[g] += step[g];
            }

            if (numbrz > 100)
            {
                                run = 0;

                        }
         }
      }

      time_sleep(atof(argv[3])/5000);
   }

   printf("\ntidying up\n");

   for (g=0; g<NUM_GPIO; g++)
   {
      if (used[g]) gpioServo(g, 0);
   }

   gpioTerminate();

   return 0;
}

