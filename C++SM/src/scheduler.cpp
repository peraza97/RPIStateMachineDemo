#include "../headers/scheduler.h"
#include <stdio.h>

Scheduler::Scheduler(){}

Scheduler::Scheduler(int numTasks, SM ** stateMachines)
{
    this->numTasks = numTasks;
    this->stateMachines = stateMachines;
    
    this->commonInterval = this->stateMachines[0]->period;
    for(int i = 1; i < this->numTasks; ++i)
    {
        this->commonInterval = this->findGCD(this->commonInterval, this->stateMachines[i]->period);
    }
}

void Scheduler::Loop()
{
    while(1)
    {
        this->Step(this->commonInterval);
        usleep(this->commonInterval * 1000);
    }
}

void Scheduler::Step(unsigned long currentTime)
{
    for(int i = 0; i < this->numTasks; ++i)
    {
        this->stateMachines[i]->elapsedTime += this->commonInterval;
        if(this->stateMachines[i]->elapsedTime >= this->stateMachines[i]->period)
        {
            this->stateMachines[i]->Step();
            this->stateMachines[i]->elapsedTime = 0;
        }
    }
}

unsigned long Scheduler::getInterval()
{
    return this->commonInterval;
}

int Scheduler::getNumTasks()
{
    return this->numTasks;
}

unsigned long Scheduler::findGCD(unsigned long a, unsigned long b)
{
    unsigned long c;
    while(1){
        c = a % b;
        if( c == 0 ) { return b; }
        a = b;
        b = c;
    }
    return 0;
}
