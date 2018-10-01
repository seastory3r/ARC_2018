// -----
// Abst : 2018 ARC DC���[�^�𐧌䂷�邽�߂ɗ��p���郂�[�^�h���C�o�p�̏���
//        �L�[�{�[�h������͂����f�[�^��Arduino�ɑ��M���ă��[�^�𐧌䂷��
//        'w': ���] / 'z': ���]
//        'a': ����� / 'd': �E���
//        'q': �X�g�b�v  / 'x': �u���[�L
// Ref  : 
// -----
#include "ARC_motor_driver.h"

// �ԗ�1�p�̃s���ݒ�
#define PIN_WHEEL1_VREF1 9  // DC���[�^�����PWMx2�K�v
#define PIN_WHEEL1_VREF2 10

// �ԗ�2�p�̃s���ݒ�
#define PIN_WHEEL2_VREF1 11  // DC���[�^�����PWMx2�K�v
#define PIN_WHEEL2_VREF2 12

Motor testMotor1;
Motor testMotor2;

void lf_init() {
  testMotor1 = Motor(PIN_WHEEL1_VREF1, PIN_WHEEL1_VREF2);
  testMotor2 = Motor(PIN_WHEEL2_VREF1, PIN_WHEEL2_VREF2);

  Serial.begin(9600); // �V���A���ʐM�̓]�����x��9600bps�Ɏw��
}

void lf_lift() {
  // �V���A���|�[�g����f�[�^���󂯂�ꍇ1�ȏ�ɂȂ�
  if(Serial.available() > 0){
    switch(Serial.read()){
      case 'w': // ���]
        testMotor1.forward();
        testMotor2.forward();
        Serial.println("Forward");
        Serial.println(testMotor1.get_speed(), DEC);
        break;
      case 'z': // ���]
        testMotor1.reverse();
        testMotor2.reverse();
        Serial.println("Reverse");
        Serial.println(testMotor1.get_speed(), DEC);
        break;
      case 'a': // ���܂��
        testMotor1.forward();
        testMotor2.reverse();
        Serial.println("Counter clockwise");
        Serial.println(testMotor1.get_speed(), DEC);
      case 'd': // �E�܂��
        testMotor1.reverse();
        testMotor2.forward();
        Serial.println("Clockwise");
        Serial.println(testMotor1.get_speed(), DEC);
      case 'q': // �X�g�b�v
        testMotor1.stop();
        testMotor2.stop();
        Serial.println("Stop");
        Serial.println(testMotor1.get_speed(), DEC);
        break;
      case 'x': // �u���[�L
        testMotor1.brake();
        testMotor2.brake();
        Serial.println("Brake");
        break;
      default:
        break;
    }
  }

}
