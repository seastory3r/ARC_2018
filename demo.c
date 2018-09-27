#include "common.h"
enum {
  DEMO_STATE_MOVE = 0,
  DEMO_STATE_LIFT,
  DEMO_STATE_GRASP,  
};

static uc demoState;

//prototype
static bl demoMove(void);
static bl demoLift(void);
static bl demoGrasp(void);

void demoInit(void){
  demoState = DEMO_STATE_MOVE;
}

void demoTick(void){
  bl endDemo;

  switch( demoState ){
      case DEMO_STATE_MOVE:
        endDemo = demoMove();

        if( endDemo == TRUE ){
          demoState = DEMO_STATE_LIFT;
        }
        break;
      case DEMO_STATE_LIFT:
        endDemo = demoLift();

        if( endDemo == TRUE ){
          demoState = DEMO_STATE_LIFT;
        }
        break;
      case DEMO_STATE_GRASP:
        endDemo = demoGrasp();

        if( endDemo == TRUE ){
          demoState = DEMO_STATE_MOVE;
        }
        break;
      default:
        break;
  }
}
  // 把持動作、車輪(両方), リフト(上下)を順番に動作させる
  // 把持動作：５秒Open、5秒Closeを３回繰り返す。 
  // 車両動作： ５秒前進、５秒後退、５秒旋回を３回繰り返す
  // リフト動作：1秒上動作、１秒下動作を３回繰り返す 

  // 把持動作
  // ３回繰り返し
    // サーボモータへOpen指示
  
    // 5秒wait
  
    // サーボモータへClose指示
  
    // ５秒wait

  // 把持動作を停止させる

  // 車両動作
  // ３回繰り返し
    // 前進指示

    // ５秒wait

    // 後退指示

    // ５秒wait

    // 旋回指示

    // ５秒wait

  // 停止指示

  // リフト動作
  // ３回繰り返し
    // リフトへ上動作指示

    // １秒wait

    // リフトへ下動作指示

    // １秒wait

  // リフトへ停止指示
