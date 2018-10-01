#include<stdlib.h>
#include"arduino.h"
#include "ARC_motor_driver.h"

int initSp    = 0;  // 初期速度
int spUpStep  = 20; // 加速の回転速度の間隔
int spDwnStep = 10; // 減速の回転速度の間隔

Motor::Motor(){}

Motor::Motor(int _pwmPin1, int _pwmPin2){
  this -> pwmPin1 = _pwmPin1;
  this -> pwmPin2 = _pwmPin2;
  this -> sp1 = initSp;
  this -> sp2 = initSp;

  pinMode(this -> pwmPin1, OUTPUT);
  pinMode(this -> pwmPin2, OUTPUT);
}

void Motor::forward(){
  // sp2が止まっていなとsp1は動かさない
  if (!isMoving(this -> sp2)){
    if((this -> sp1 + spUpStep) <= 255) this -> sp1 += spUpStep;  
    move(this -> pwmPin1, this -> sp1);
  }
}

void Motor::reverse(){
  // sp1が止まっていないとsp2は動かさない
  if (!isMoving(this -> sp1)){
    if((this -> sp2 + spUpStep) <= 255) this -> sp2 += spUpStep;
    move(this -> pwmPin2, this -> sp2);
  }
}
  
void Motor::stop(){
  this -> sp1 = 0;
  this -> sp2 = 0;
  move(this -> pwmPin1, this -> sp1);
  move(this -> pwmPin2, this -> sp2);
}

void Motor::brake(){
  int sp, pwmPin;
  if (isMoving(sp1)){
    for(int i = this -> sp1; i >= 0; i -= spDwnStep){
      move(this -> pwmPin1, i);
      this -> sp1 = i;
    }
  }
  else if (isMoving(sp2)){
    for(int i = this -> sp2; i >= 0; i -= spDwnStep){
      move(this -> pwmPin2, i);
      this -> sp2 = i;
    }
  }
  
  stop();
}

int Motor::get_speed(){
  int sp = 0;
  if (isMoving(sp1)) sp = this -> sp1;
  else if (isMoving(sp2)) sp = this -> sp2;
  
  return sp;
}

// Private
void Motor::move(int pwmPin, int sp){
  // 速度を設定して回転させる
  analogWrite(pwmPin, sp);
}

boolean Motor::isMoving(int sp){
  if(sp == 0) return false;
  else return true;
}
