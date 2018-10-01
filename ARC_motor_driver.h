// -----
// Abst : モータを制御するためのクラス
// -----
#ifndef ARC_MOTOR_DRIVER_H
#define ARC_MOTOR_DRIVER_H

#include <Arduino.h>

class Motor{
  private:
    int pwmPin1, pwmPin2;
    int sp1, sp2;
    
  public:
    Motor();

    // -----
    // モータ
    // [入力引数]
    //   int _pwmPin1 : PWMの端子番号1
    //   int _pwmPin1 : PWMの端子番号2
    //
    Motor(int _pwmPin1, int _pwmPin2);

    void forward();
    void reverse();
    void stop();
    void brake();
    int get_speed();

  private:
    void move(int pwmPin, int sp);
    boolean isMoving(int sp);
};

#endif //ARC_MOTOR_DRIVER_H
