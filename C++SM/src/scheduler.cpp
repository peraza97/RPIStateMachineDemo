#include "../headers/scheduler.h"
#include <stdio.h>
#include <thread>

using namespace std;

Scheduler::Scheduler(){}

Scheduler::Scheduler(int numTasks, SM ** stateMachines)
{
    this->numTasks = numTasks;
    this->stateMachines = stateMachines;
    
    this->commonInterval = this->stateMachines[0]->period;
    for(int i = 1; i < this->numTasks; ++i)
    {
        this->commonInterval = this->FindGCD(this->commonInterval, this->stateMachines[i]->period);
    }
}

unsigned long Scheduler::GetInterval()
{
    return this->commonInterval;
}

int Scheduler::GetNumTasks()
{
    return this->numTasks;
}

unsigned long Scheduler::FindGCD(unsigned long a, unsigned long b)
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
    thread threads[this->numTasks];
    for(int i = 0; i < this->numTasks; ++i)
    {
        this->stateMachines[i]->elapsedTime += this->commonInterval;
        if(this->stateMachines[i]->elapsedTime >= this->stateMachines[i]->period)
        {
            threads[i] = thread(&SM::Step,this->stateMachines[i]);
            this->stateMachines[i]->elapsedTime = 0;
        }
    }

    for(int i = 0; i < this->numTasks; ++i)
    {
        if(threads[i].joinable()) //thread is not running if sm is not ready
        {
            threads[i].join();
        }
    }
}
