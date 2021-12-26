#include <wiringPi.h>
#include <iostream>
#include "../headers/blinkSM.h"

using namespace std;

BlinkSM::BlinkSM(string name, unsigned long elapsedTime, unsigned long period, int ledPin): SM(name, elapsedTime, period)
{
    this->ledPin = ledPin;
    this->state = B_INIT;
    digitalWrite (this->ledPin, 0); 
}

void BlinkSM::Step()
{
    // transition
    switch(this->state)
    {
        case B_INIT:
            this->state = B_OFF;
            break;
        case B_OFF:
            this->state = B_ON;
            break;
        case B_ON:
            this->state = B_OFF;
            break;
        default:
            break;
    }

    // action
    switch(this->state)
    {
        case B_OFF:
            digitalWrite (this->ledPin, 0); 
            break;
        case B_ON:
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