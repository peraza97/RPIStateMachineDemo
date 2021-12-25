#ifndef __BLINK_SM_H__
#define __BLINK_SM_H__

#include "sm.h"

enum BlinkStates { OFF, ON };

class BlinkSM : public SM
{
    public:
        BlinkSM(int, unsigned long, unsigned long);
        void Step();
        void Stop();
        
    private:
        int ledPin;
        BlinkStates state;
};

#endif