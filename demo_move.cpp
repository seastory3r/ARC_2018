// 車両動作： ５秒前進、５秒後退、５秒旋回を３回繰り返す
//demo_move.cpp[dm]

#include "demo_move.h"

enum {
  DM_STATE_STOP = 0,
  DM_STATE_RUN,
};

enum {
  DM_TYPE_FORWORD = 0,
  DM_TYPE_BACK,
  DM_TYPE_CLOCK_WISE,
  DM_TYPE_COUNTER_CLOCK_WISE,
};

#define DM_TIME_DEMO 5000

static us dmDemoTimer;
static uc dmState;
static uc dmType;

//prototype
static uc dmCvtDemoType(uc dmType);
static bl dmNextDemoType(uc* dmType);

vd demoMoveInit(void){
  dmType = DM_TYPE_FORWORD;
  dmState = DM_STATE_STOP;
}

bl demoMove(void){
  bl endDemo;
  uc drct;

  endDemo = FALSE;

  switch(dmState){
    case DM_STATE_STOP:
      if( TRUE ){
//      if( motorDrvStop() ){
        dmState = DM_STATE_RUN;
        dmDemoTimer = DM_TIME_DEMO;
      }
      break;

    case DM_STATE_RUN:
      //During
      drct = dmCvtDemoType(dmType);
      //モータを動かすための関数　モータドライバ.cppの。
      //motorDrvMove(drct);

      //TransitionEvent？
      //一定時間経過？
      if(--dmDemoTimer == 0){
        //exit
        dmState = DM_STATE_STOP;
        endDemo = dmNextDemoType(dmType);
      }
      break;
  }
  return endDemo;
}

static uc dmCvtDemoType(uc dmType){
  uc drct;
  switch(dmType){
    case DM_TYPE_FORWORD:
      drct = 0;
      break;
    case DM_TYPE_BACK:
      drct = 0;
      break;
    case DM_TYPE_CLOCK_WISE:
      drct = 0;
      break;
    case DM_TYPE_COUNTER_CLOCK_WISE:
      drct = 0;
      break;
    default:
      drct = 0;
      break;
  }
  return drct;
}

static bl dmNextDemoType(uc* dmType){
  if( ++(*dmType) > DM_TYPE_COUNTER_CLOCK_WISE ){
    *dmType = DM_TYPE_FORWORD;
    return TRUE;
  }

  return FALSE;
}
