// リフト動作：1秒上動作、１秒下動作を３回繰り返す 

#include "demo_lift.h"

bl demoLift(void){
  // リフト動作
ul elapsedTime;
  // リフトへ上動作指示
//  liftMotorUp();
  // １秒wait
elapsedTime = millis();
  // リフトへ下動作指示


  // １秒wait

  // リフトへ停止指示

  
  return TRUE;
}
