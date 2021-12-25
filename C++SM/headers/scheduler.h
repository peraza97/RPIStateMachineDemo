#ifndef __TASK_SCHEDULER_H__
#define __TASK_SCHEDULER_H__

#include <unistd.h>
#include "sm.h"

class Scheduler
{
    private:
        unsigned long commonInterval;
        int numTasks;
        SM ** stateMachines;
        unsigned long findGCD(unsigned long, unsigned long);
    public:
        Scheduler();
        Scheduler(int, SM **);
        void Step(unsigned long time);
        void Loop();
        unsigned long getInterval();
        int getNumTasks();
};

#endif