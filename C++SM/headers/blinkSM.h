#ifndef __BLINK_SM_H__
#define __BLINK_SM_H__

#include "sm.h"

enum BlinkStates { B_INIT, B_OFF, B_ON };

class BlinkSM : public SM
{
    public:
        BlinkSM(string, unsigned long, unsigned long, int);
        void Step();
        void Stop();
        
    private:
        int ledPin;
        BlinkStates state;
};

#endif