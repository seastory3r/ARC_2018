
#include "demo.h"
#include "demo_grasp.h"
#include "demo_lift.h"
#include "demo_move.h"

enum {
  DEMO_STATE_MOVE = 0,
  DEMO_STATE_LIFT,
  DEMO_STATE_GRASP,  
};

static uc demoState;

//prototype


vd demoInit(vd){
  demoState = DEMO_STATE_MOVE;
  demoMoveInit();
}

vd demoTick(vd){
  bl endDemo;
  uc demoCnt;

  // 車輪(両方)の
  switch( demoState ){
      case DEMO_STATE_MOVE:
        endDemo = demoMove();
        break;
        
      default:
        break;
  }
}
