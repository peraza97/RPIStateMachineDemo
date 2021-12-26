#include <stdio.h>
#include <wiringPi.h>
#include "../headers/scheduler.h"
#include "../headers/sm.h"
#include "../headers/blinkSM.h"
#include "../headers/lightSequenceSM.h"

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
    pinMode (ledPin2, OUTPUT);

    SM ** stateMachines = new SM*[2];
    
    //Blinking light sm: toggle off and on every 1 second
    stateMachines[0] = new BlinkSM("Blink1", 10000, 1000, ledPin1); 

    // light sequence sm
    unsigned char durations[] = {1, 1, 1, 1}; 
    unsigned char downtime[] =  {3, 1, 1, 5};   
    int noteCount = sizeof(durations)/sizeof(unsigned char);
    stateMachines[1] = new LightSequenceSM("lightSequence", 100, 100, ledPin2, durations, downtime, noteCount);

    Scheduler * myScheduler = new Scheduler(2, stateMachines);
    printf("Scheduler numTasks: %d\n", myScheduler->GetNumTasks());
    printf("Scheduler common period: %d\n", myScheduler->GetInterval());

    myScheduler->Loop();

    return 0;
}