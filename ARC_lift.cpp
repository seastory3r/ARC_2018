// -----
// Abst : 上位モジュールからの要求に従いリフトを上下する
// ARC_lift.cpp[lf]
// -----
#include "ARC_motor_driver.h"

// リフト用
#define PIN_LIFT_VREF1 2  // DCモータ制御はPWMx2必要
#define PIN_LIFT_VREF2 5

Motor testMotorLift;

void lf_init() {
  testMotorLift = Motor(PIN_LIFT_VREF1, PIN_LIFT_VREF2);
}

void lf_lift(liftReq_t lf_req) {
  switch(lf_req){
    case eLfUp: // 上昇
      testMotorLift.forward();
      Serial.println("Up");
      Serial.println(testMotorLift.get_speed(), DEC);
      break;
    case eLfDown: // 下降
      testMotorLift.reverse();
      Serial.println("Reverse");
      Serial.println(testMotorLift.get_speed(), DEC);
      break;
    case eLfStop: // 停止
      testMotorLift.stop();
      Serial.println("Stop");
      Serial.println(testMotorLift.get_speed(), DEC);
      break;
    case eLfBrake: // ブレーキ
      testMotorLift.brake();
      Serial.println("Brake");
      break;
    default:
      break;
  }
}
