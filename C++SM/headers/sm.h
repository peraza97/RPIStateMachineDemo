#ifndef __TASK_SM_H__
#define __TASK_SM_H__
#include <iostream>

using namespace std;

class SM
{
    public:
        unsigned long elapsedTime;
        unsigned long period;
        string name;

        SM(string name, unsigned long elapsedTime, unsigned long period)
        {
            this->name = name;
            this->elapsedTime = elapsedTime;
            this->period = period;
        }

        virtual void Step() = 0;
        virtual void Stop() = 0;
};

#endif