// 把持動作：５秒Open、5秒Closeを３回繰り返す。 
//demo_grasp.cpp[dg]

#include "demo_grasp.h"

static us dgDemoTimer;

vd demoGraspInit(void){
  dgDemoTimer = 0;
  
}

bl demoGrasp(void){
  // 把持動作
  // サーボモータへOpen指示
  
  // 5秒wait
  
  // サーボモータへClose指示
  
  // ５秒wait

  // 把持動作を停止させる

  
  return TRUE;
}
