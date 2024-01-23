#ifndef __LED_TASK_H__
#define __LED_TASK_H__

enum LEDState {LED_OFF, LED_ON};

extern struct gpiod_line * ledLine;  // Declaration of the global variable

int ledATick(int);

#endif
