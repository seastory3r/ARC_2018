// -----
// Abst : 透過型フォトセンサが物体を検知したかを取得する。
// Ref  :
// ARC_photo_sensor.cpp[ps] 
// -----
#include "ARC_photo_sensor.h"

#define PIN_PHOTO_SENSOR1 22 // フォトセンサのピン番号(Digital)

void ps_init() {
  pinMode(PIN_PHOTO_SENSOR1, INPUT);
}

photoSensorRslt_t ps_photoSensor() {

  if(digitalRead(PIN_PHOTO_SENSOR1) == HIGH){
    Serial.println("Detected!!");
    return ePsDetected;
  }else{
    Serial.println("Not detected.");
    return ePsNotDetected;
  }
}
