#include "ARC_cycle.h"
#include <MsTimer2.h>

static uc cycleCounter;

//prototype
static vd cycleCount(vd);

vd cycleInit(vd){
  cycleCounter = 0;

  MsTimer2::set(1, cycleCount);
  MsTimer2::start();
}

static vd cycleCount(vd){
  cycleCounter++;
}

static vd cycleClrCounter(vd){
  cycleCounter = 0;
}

bl isElapsed10ms(vd){
  if( cycleCounter >= 10){
    cycleClrCounter();

    return TRUE;
  }

  return FALSE;
}
