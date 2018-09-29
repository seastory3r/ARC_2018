#include "ARC_cycle.h"

void setup() {
  cycleInit();

}

void loop() {
  bl isElapsed;

  noInterrupts();
  isElapsed = isElapsed10ms();
  interrupts();

  if( isElapsed ){

  }
  
}
