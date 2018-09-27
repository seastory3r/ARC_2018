#include "cycle.h"
#include "demo.h"

void setup() {
  // put your setup code here, to run once:
  cycleInit();
  demoInit();
}

void loop() {
  bl isElapsed;
  // put your main code here, to run repeatedly:
  noInterrupts();
  isElapsed = isElapsed10ms();
  interrupts();

  if( isElapsed ){
    demoTick();
  }
  
}
