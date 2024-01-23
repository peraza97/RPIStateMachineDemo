#include <stdio.h>
#include <string.h>
#include <gpiod.h>
#include <unistd.h>
#include <signal.h>

#include "SMTask.h"
#include "ledTask.h"

#define MICROTOMILLI 1000 

// GLOBAL variables
struct gpiod_chip *chip;
struct gpiod_line * ledLine;

unsigned long findGCD(unsigned long int a, unsigned long int b)
{
	unsigned long int c;
	while(1){
		c = a % b;
		if( c == 0 ) { return b; }
		a = b;
		b = c;
	}
	return 0;
}

void handleCtrlC(int signum) {
  printf("\nCtrl+C pressed. cleaning up...\n");

  if (ledLine != NULL) {
    printf("Releasing line\n");
    gpiod_line_release(ledLine);
  }   

  if (chip != NULL) {
    printf("Closing chip\n");
    gpiod_chip_close(chip);    
  }

  printf("exiting\n");
  exit(signum);
}

int main(int argc, char** argv){
  signal(SIGINT, handleCtrlC);

  chip = gpiod_chip_open("/dev/gpiochip4");

  if (chip == NULL) {
    printf("chip not found\n");
    return 1;
  }
  
  //use GPIO PIN, not PHYSICAL
  ledLine = gpiod_chip_get_line(chip, 18);  
  gpiod_line_request_output(ledLine, "example1", 0);
  
  SMTask ledTask;
  ledTask.state = 0;
  ledTask.period = 1000;
  ledTask.elapsedTime = 0;
  ledTask.TickFct = &ledATick;

  SMTask tasks[] = { ledTask };
  
  int gcd = findGCD(ledTask.period, 1);  

  int numTasks = sizeof(tasks) / sizeof(SMTask);
  while(1) {
    for(int i = 0; i < numTasks; ++i) {
      if (tasks[i].elapsedTime > tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = 0;
      }
      tasks[i].elapsedTime += gcd;
    }
    
    usleep(gcd * MICROTOMILLI);
  }

  return 0;
}
