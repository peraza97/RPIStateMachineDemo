#ifndef __TASK_SM_H__
#define __TASK_SM_H__

class SM
{
    public:
        unsigned long elapsedTime;
        unsigned long period;

        SM(unsigned long elapsedTime, unsigned long period)
        {
            this->elapsedTime = elapsedTime;
            this->period = period;
        }

        virtual void Step() = 0;
        virtual void Stop() = 0;
};

#endif