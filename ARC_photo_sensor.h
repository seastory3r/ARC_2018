// -----
// Abst : 透過型フォトセンサが物体を検知したかを取得する。
// Ref  : 
// -----

#ifndef ARC_PHOTO_SENSOR_H
#define ARC_PHOTO_SENSOR_H

#include "ARC_common.h"

//センサの検知結果
typedef enum {
  ePsDetected,    //検知
  ePsNotDetected, //非検知
} photoSensorRslt_t;

extern void ps_init();
extern photoSensorRslt_t ps_photoSensor(void);

#endif //ARC_PHOTO_SENSOR_H
