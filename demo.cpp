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
}

vd demoTick(vd){
  bl endDemo;
  uc demoCnt;

  // 把持動作、車輪(両方), リフト(上下)を順番に動作させる
  switch( demoState ){
      case DEMO_STATE_MOVE:
        endDemo = demoMove();

        if( endDemo == TRUE ){
          demoCnt++;
          if( demoCnt >= 3){
            demoState = DEMO_STATE_LIFT;
            demoCnt = 0;
          }
        }
        break;
        
      case DEMO_STATE_LIFT:
        endDemo = demoLift();

        if( endDemo == TRUE ){
          demoCnt++;
          if( demoCnt >= 3){
            demoState = DEMO_STATE_GRASP;
            demoCnt = 0;
          }
        }
        break;
        
      case DEMO_STATE_GRASP:
        endDemo = demoGrasp();

        if( endDemo == TRUE ){
          demoCnt++;
          if( demoCnt >= 3){
            demoState = DEMO_STATE_MOVE;
            demoCnt = 0;
          }
        }
        break;
        
      default:
        break;
  }
}
