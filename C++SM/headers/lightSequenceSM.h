#ifndef __LIGHTSEQUENCE_SM_H__
#define __LIGHTSEQUENCE_SM_H__

#include "sm.h"

enum LightSequenceStates { LS_INIT, LS_OFF, LS_ON, LS_DONE };

class LightSequenceSM : public SM
{
    public:
        LightSequenceSM(string, unsigned long, unsigned long, int, unsigned char *, unsigned char *,  int);
        void Step();
        void Stop();
        
    private:
        int ledPin;
        unsigned char * durations;
        unsigned char * downtime;
        int noteCount;
        LightSequenceStates state;
        int counter;
        int currentNoteIndex;
};

#endif