// -----
// Ref  : 上位モジュールから受け取った要求に従い、車両を駆動させる。
// ARC_drive.cpp[dr]
// -----
#include "ARC_drive.h"
#include "ARC_motor_driver.h"

// 車輪1用のピン設定
#define PIN_WHEEL1_VREF1 9  // DCモータ制御はPWMx2必要
#define PIN_WHEEL1_VREF2 10

// 車輪2用のピン設定
#define PIN_WHEEL2_VREF1 11  // DCモータ制御はPWMx2必要
#define PIN_WHEEL2_VREF2 12

Motor testMotor1; //車輪1 右側モータ？？
Motor testMotor2; //車輪2 左側モータ？？

void dr_init() {
  testMotor1 = Motor(PIN_WHEEL1_VREF1, PIN_WHEEL1_VREF2);
  testMotor2 = Motor(PIN_WHEEL2_VREF1, PIN_WHEEL2_VREF2);

}

void dr_move(driveReq_t dr_req) {
  //受け取った要求に従い、車両を動かす
  switch(Serial.read()){
    case eDrForward: // 前進
      testMotor1.forward();
      testMotor2.forward();
      Serial.println("Forward");
      Serial.println(testMotor1.get_speed(), DEC);
      break;
    case eDrReverse: // 後退
      testMotor1.reverse();
      testMotor2.reverse();
      Serial.println("Reverse");
      Serial.println(testMotor1.get_speed(), DEC);
      break;
    case eDrCCW: // 反時計回り
      testMotor1.forward();
      testMotor2.reverse();
      Serial.println("Counter clockwise");
      Serial.println(testMotor1.get_speed(), DEC);
    case eDrCW: // 時計回り
      testMotor1.reverse();
      testMotor2.forward();
      Serial.println("Clockwise");
      Serial.println(testMotor1.get_speed(), DEC);
    case eDrStop: // 停止
      testMotor1.stop();
      testMotor2.stop();
      Serial.println("Stop");
      Serial.println(testMotor1.get_speed(), DEC);
      break;
    case eDrBrake: // ブレーキ
      testMotor1.brake();
      testMotor2.brake();
      Serial.println("Brake");
      break;
    default:
      break;
  }
}
