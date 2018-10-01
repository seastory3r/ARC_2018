// -----
// Abst : 透過型フォトセンサが物体を検知したかを取得する。
// Ref  :
// ARC_photo_sensor.cpp[ps] 
// -----
#include "ARC_photo_sensor.h"
#include <arduino.h>

#define PIN_PHOTO_SENSOR_UL 22 // リフト上限用フォトセンサのピン番号(Digital)
#define PIN_PHOTO_SENSOR_TGT 23 // ターゲット用フォトセンサのピン番号(Digital)
#define PIN_PHOTO_SENSOR_LL 24 // リフト下限用フォトセンサのピン番号(Digital)

void ps_init(void) {
  pinMode(PIN_PHOTO_SENSOR_UL, INPUT);
  pinMode(PIN_PHOTO_SENSOR_TGT, INPUT);
  pinMode(PIN_PHOTO_SENSOR_LL, INPUT);  
}

photoSensorRslt_t ps_photoSensor(void) {

  if((digitalRead(PIN_PHOTO_SENSOR_UL) == HIGH)
  || (digitalRead(PIN_PHOTO_SENSOR_TGT) == HIGH)
  || (digitalRead(PIN_PHOTO_SENSOR_LL) == HIGH)){
    Serial.println("Detected!!");
    return ePsDetected;
  }else{
    Serial.println("Not detected.");
    return ePsNotDetected;
  }
}
