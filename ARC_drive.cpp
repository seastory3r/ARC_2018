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

//車両を駆動させる要求
typedef enum {
  eDrForward, //前進
  eDrReverse, //後退
  eDrCCW,     //CounterClockWise 反時計回り
  eDrCW,      //CounterClock 時計回り
  eDrStop,    //停止
  eDrBrake,   //ブレーキ
  eDrNoReq,   //車両を駆動させる要求ではない
} driveReq_t;

Motor testMotor1; //車輪1 右側モータ？？
Motor testMotor2; //車輪2 左側モータ？？

static driveReq_t lastDriveReq;  //前回の駆動要求

static driveReq_t dr_cvtDriveReq(userCmd_t);
static void dr_move(driveReq_t);

void dr_init() {
  testMotor1 = Motor(PIN_WHEEL1_VREF1, PIN_WHEEL1_VREF2);
  testMotor2 = Motor(PIN_WHEEL2_VREF1, PIN_WHEEL2_VREF2);
}

void dr_tick(userCmd_t user_cmd){
  driveReq_t dr_req;

  dr_req = dr_cvtDriveReq(user_cmd);  //ユーザーからの命令を変換してから
  dr_move(dr_req);                    //車両を動かす
}

static driveReq_t dr_cvtDriveReq(userCmd_t userCmd){
  driveReq_t driveReq;  //車両を駆動させる要求

  //ユーザーからの命令 → 車両を駆動させる要求
  switch(userCmd){
    case eUcDriveForward:
      driveReq = eDrForward;
      break;
    case eUcDriveReverse:
      driveReq = eDrReverse;
      break;
    case eUcDriveCCW:
      driveReq = eDrCCW;
      break;
    case eUcDriveCW:
      driveReq = eDrCW;
      break;
    case eUcDriveStop:
      driveReq = eDrStop;
      break;
    case eUcDriveBrake:
      driveReq = eDrBrake;
      break;
    default:
      driveReq = eDrNoReq;  //車両を駆動させる要求ではない場合
      break;
  }
  return driveReq;
}

static void dr_move(driveReq_t dr_req) {
  //前回の駆動要求と今回の駆動要求が異なれば
  if(lastDriveReq != dr_req){
    //受け取った要求に従い、車両を動かす
    switch(dr_req){
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
      case eDrNoReq:  //車両を動かす要求ではない場合
      default:
        break;
    }
  }
  lastDriveReq = dr_req;  //前回値の更新
}
