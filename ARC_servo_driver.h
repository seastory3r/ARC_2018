// -----
// Abst : サーボモータを利用した把持動作用クラス
// -----
#ifndef ARC_SERVO_DRIVER_H
#define ARC_SERVO_DRIVER_H

class ARCGrasp{
  private:
    int pwmPin;
    int value;
    int minValue;
    int maxValue;

  public:
    ARCGrasp();

    // -----
    // 把持動作を行う
    // [入力引数]
    //   int _pwmPin   : PWMの端子番号
    //   int _minValue : 閉じている値(NULLを指定する場合は0を設定する)
    //   int _maxValue : 開いている値(100までを指定 ※100を越えると金具にぶつかる)
    //
    ARCGrasp(int _pwmPin, int _minValue, int _maxValue);

    void open();
    void close();
    void reset();
    int getValue();

  private:
    void move();
    int convert_value(int val);
};

#endif //ARC_SERVO_DRIVER_H
