// -----
// Abst : 車両を駆動させる
// -----

#ifndef ARC_DRIVE_H
#define ARC_DRIVE_H

#inlcude "ARC_common.h"

//車両を駆動させる要求
typedef enum {
  eDrForward, //前進
  eDrReverse, //後退
  eDrCCW,     //CounterClockWise 反時計回り
  eDrCW,      //CounterClock 時計回り
  eDrStop,    //停止
  eDrBrake,   //ブレーキ
} driveReq_t;

extern void dr_init();
extern void dr_move(driveReq_t);

#endif //ARC_DRIVE_H
