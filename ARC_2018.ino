#include "ARC_cycle.h"
#include "ARC_user_command.h"
#include "ARC_drive.h"
#include "ARC_grasp.h"
#include "ARC_lift.h"

void setup() {
  Serial.begin(9600); // デバッグ用。シリアル通信の転送速度を9600bpsに指定。
  cycleInit();
  uc_init();
  dr_init();
  gr_init();
  lf_init();
}

void loop() {
  bl isElapsed;
  userCmd_t userCmd;

  noInterrupts();
  isElapsed = isElapsed10ms();
  interrupts();

  if( isElapsed ){
    userCmd = uc_tick();
    dr_tick(userCmd);
    gr_tick(userCmd);
    lf_tick(userCmd);
  }
  
}
