// -----
// Abst : 上位モジュールからの要求に従い、グリップをOpen/Closeする
// Ref  : 
// -----
#include "ARC_grasp.h"
#include "ARC_servo_driver.h"
#include <Arduino.h>

#define PIN_IN_SERVO1 6 // 把持動作で利用するピン番号

//グリップを開閉させる要求
typedef enum {
  eGrOpen,  //オープン
  eGrClose, //クローズ
  eGrReset, //リセット
  eGrNoReq, //グリップを開閉させる要求ではない
} graspReq_t;

ARCGrasp grasp1;

static graspReq_t lastGraspReq;  //前回の開閉要求

static graspReq_t gr_cvtGraspReq(userCmd_t);
static void gr_grasp(graspReq_t);

void gr_init() {
  grasp1 = ARCGrasp(PIN_IN_SERVO1, 30, 100);
}

void gr_tick(userCmd_t user_cmd){
  graspReq_t gr_req;

  gr_req = gr_cvtGraspReq(user_cmd);  //ユーザーからの命令を変換してから
  gr_grasp(gr_req);                   //グリップを動かす
}

static graspReq_t gr_cvtGraspReq(userCmd_t userCmd){
  graspReq_t graspReq;  //グリップを開閉させる要求

  //ユーザーからの命令 → グリップを開閉させる要求
  switch(userCmd){
    case eUcGraspOpen:
      graspReq = eGrOpen;
      break;
    case eUcGraspClose:
      graspReq = eGrClose;
      break;
    case eUcGraspReset:
      graspReq = eGrReset;
      break;
    default:
      graspReq = eGrNoReq;  //グリップを開閉させる要求ではない場合
      break;
  }

  return graspReq;
}

static void gr_grasp(graspReq_t gr_req) {
  //前回の駆動要求と今回の駆動要求が異なれば
  if(lastGraspReq != gr_req){
    switch(gr_req){
      case eGrOpen: // オープン
        Serial.println("o key(open) is clicked!");
        grasp1.open();
        break;
      case eGrClose: // クローズ
        Serial.println("p key(close) is clicked!");
        grasp1.close();
        break;
      case eGrReset: // リセット
        Serial.println("r key(reset) is clicked!");
        grasp1.reset();
        break;
      case eGrNoReq:  //グリップを開閉させる要求ではない場合
      default:
        break;
    }
  }
  lastGraspReq = gr_req;
}
