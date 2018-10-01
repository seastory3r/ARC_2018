#include<stdlib.h>
#include"arduino.h"
#include "ARCGrasp.h"
#include<ARC_servo_driver.h>

Servo sv;

int saveInitValue; // 初期値を保存

ARCGrasp::ARCGrasp(){}

ARCGrasp::ARCGrasp(int _pwmPin, int _minValue, int _maxValue){
  this -> pwmPin = _pwmPin;
  this -> minValue = convert_value(_minValue);
  this -> maxValue = convert_value(_maxValue);

  // 初期値を設定
  this -> value = this -> maxValue;
  saveInitValue = this -> value;

  // サーボのピンへの割り当て
  sv.attach(this -> pwmPin);
}

void ARCGrasp::open(){
  int val = getValue();

  for(int i = val; i >= this -> maxValue; i--){
    this -> value = i;
    move();
  }
}

void ARCGrasp::close(){
  int val = getValue();

  // 開閉確認: 開いている場合は閉じる
  if(val < this -> minValue){
    for(int i = val; i < this -> minValue; i++){
      this -> value = i;
      move();
    }
  }
}

void ARCGrasp::reset(){
  int value = saveInitValue;
  sv.write(value);
}

int ARCGrasp::getValue(){
  return this -> value;
}

// Private
void ARCGrasp::move(){
  sv.write(this -> value);
}

int ARCGrasp::convert_value(int val){
  return (180 - val);
}
