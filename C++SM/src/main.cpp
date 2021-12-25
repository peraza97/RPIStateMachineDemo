#include <stdio.h>
#include <wiringPi.h>
#include "../headers/scheduler.h"
#include "../headers/blinkSM.h"
#include "../headers/sm.h"

using namespace std;

#define ledPin1 15
#define ledPin2 16

int main(int argc, char ** argv)
{
    printf("Starting program\n");

    if (wiringPiSetup() < 0)
    {
        printf("Failed to set up wiringPi\n");
    }

    pinMode (ledPin1, OUTPUT);
    SM ** stateMachines = new SM*[2];
    stateMachines[0] = new BlinkSM(ledPin1, 0, 1000);
    stateMachines[1] = new BlinkSM(ledPin2, 0, 500);

    Scheduler * myScheduler = new Scheduler(2, stateMachines);
    printf("Scheduler numTasks: %d\n", myScheduler->getNumTasks());
    printf("Scheduler common period: %d\n", myScheduler->getInterval());

    myScheduler->Loop();

    return 0;
}