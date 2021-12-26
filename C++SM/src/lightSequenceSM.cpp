#include <wiringPi.h>
#include <iostream>
#include "../headers/lightSequenceSM.h"

using namespace std;

LightSequenceSM::LightSequenceSM(
    string name,
    unsigned long elapsedTime, 
    unsigned long period,
    int ledPin,
    unsigned char * durations,
    unsigned char * downtime,
    int noteCount): SM(name, elapsedTime, period)
{
    this->state = LS_INIT;
    this->ledPin = ledPin;
    this->durations = durations;
    this->downtime = downtime;
    this->noteCount = noteCount;

    digitalWrite (this->ledPin, 0); 
}

void LightSequenceSM::Step()
{
    // transition
    switch(this->state)
    {
        case LS_INIT:
            this->counter = 0;
            this->currentNoteIndex = 0;
            this->state = LS_ON;
            break;
        case LS_ON:
            if(this->counter >= this->durations[this->currentNoteIndex])
            {
                this->counter = -1;
                this->state = LS_OFF;
            }
            break;
        case LS_OFF:
            if(this->counter >= this->downtime[this->currentNoteIndex])
            {
                this->currentNoteIndex +=1;
                if(this->currentNoteIndex == this->noteCount)
                {
                    this->state = LS_INIT;
                }
                else
                {
                    this->counter = -1;
                    this->state = LS_ON;
                }
            }
            break;
        default:
            break;
    }

    // action
    switch(this->state)
    {
        case LS_OFF:
            this->counter++;
            digitalWrite (this->ledPin, 0); 
            break;
        case LS_ON:
            this->counter++;
            digitalWrite (this->ledPin, 1); 
            break;
        default:
            break;
    }
}

void LightSequenceSM::Stop()
{
    digitalWrite (this->ledPin, 0);
}