// -----
// Abst : 上位モジュールからの要求に従いリフトを上下する
// ARC_lift.cpp[lf]
// -----
#include "ARC_lift.h"
#include "ARC_motor_driver.h"
#include "ARC_photo_sensor.h"

// リフト用
#define PIN_LIFT_VREF1 2  // DCモータ制御はPWMx2必要
#define PIN_LIFT_VREF2 5

//リフトを上下させる要求
typedef enum {
  eLfUp,    //上昇
  eLfDown,  //下降
  eLfStop,  //停止
  eLfBrake, //ブレーキ
  eLfNoReq, //リフトを駆動させる要求ではない
} liftReq_t;

Motor testMotorLift;

static liftReq_t lastLiftReq;  //前回の駆動要求

static liftReq_t lf_cvtLiftReq(userCmd_t userCmd);
static void lf_lift(liftReq_t lf_req);

void lf_init() {
  testMotorLift = Motor(PIN_LIFT_VREF1, PIN_LIFT_VREF2);
  ps_init();
}

void lf_tick(userCmd_t user_cmd){
  liftReq_t lf_req;

  lf_req = lf_cvtLiftReq(user_cmd);  //ユーザーからの命令を変換してから
  lf_lift(lf_req);                   //グリップを動かす
}

static liftReq_t lf_cvtLiftReq(userCmd_t userCmd){
  liftReq_t liftReq;  //リフトを駆動させる要求

  //ユーザーからの命令 → リフトを駆動させる要求
  switch(userCmd){
    case eUcLiftUp:
      liftReq = liftReq;
      break;
    case eUcLiftDown:
      liftReq = eLfDown;
      break;
    case eUcLiftStop:
      liftReq = eLfStop;
      break;
    case eUcLiftBrake:
      liftReq = eLfBrake;
      break;
    default:
      liftReq = eLfNoReq;  //グリップを開閉させる要求ではない場合
      break;
  }

  return liftReq;
}

static void lf_lift(liftReq_t lf_req) {
  //リフトの上下限に達したか、ターゲットの位置に到達した場合
  if(ps_photoSensor() == ePsDetected){
    //リフト停止
    testMotorLift.stop();
    Serial.println("Stop");
    Serial.println(testMotorLift.get_speed(), DEC);
    return;
  }
  
  //前回の駆動要求と今回の駆動要求が異なれば
  if(lastLiftReq != lf_req){
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
}
