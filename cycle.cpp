#include "cycle.h"
#include <MsTimer2.h>

static uc cycleCounter;

//prototype
static vd cycleCount(vd);
static uc _cycleCounter(vd);

vd cycleInit(vd){
  cycleCounter = 0;

  MsTimer2::set(1, cycleCount);
  MsTimer2::start();
}

static vd cycleCount(vd){
  cycleCounter++;
}

static uc _cycleCounter(vd){
  return cycleCounter;
}

static vd cycleClrCounter(vd){
  cycleCounter = 0;
}

bl isElapsed10ms(vd){
  if( _cycleCounter() >= 10){
    cycleClrCounter();

    return TRUE;
  }

  return FALSE;
}
