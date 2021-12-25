#include <wiringPi.h>
#include "../headers/blinkSM.h"

using namespace std;

BlinkSM::BlinkSM(int ledPin, unsigned long elapsedTime, unsigned long period): SM(elapsedTime, period)
{
    this->ledPin = ledPin;
    this->state = OFF;
}

void BlinkSM::Step()
{
    // transition
    switch(this->state)
    {
        case OFF:
            this->state = ON;
            break;
        case ON:
            this->state = OFF;
            break;
        default:
            break;
    }

    // action
    switch(this->state)
    {
        case OFF:
            digitalWrite (this->ledPin, 0); 
            break;
        case ON:
            digitalWrite (this->ledPin, 1); 
            break;
        default:
            break;
    }
}

void BlinkSM::Stop()
{
    digitalWrite (this->ledPin, 0); 
}