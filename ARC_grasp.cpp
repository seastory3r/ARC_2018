// -----
// Abst : �T�[�{���[�^�����삷�邩�m�F���鏈��
//        5�b���Ƃ�0�x, 90�x, 180�x�ɂ���
//       ���p���Ă�T�[�{���[�^: GWServo SO3T 2BB
// Ref  : 
// -----
#include "ARCGrasp.h"

#define PIN_IN_SERVO1 6 // �c������ŗ��p����s���ԍ�

ARCGrasp grasp1;

void gr_init() {
  grasp1 = ARCGrasp(PIN_IN_SERVO1, 30, 100);

  Serial.begin(9600); // �V���A���ʐM�̓]�����x��9600bps�Ɏw��
}

void gr_grasp() {
  if(Serial.available() > 0){
    switch(Serial.read()){
      case 'o': // �J��
        Serial.println("o key(open) is clicked!");
        grasp1.open();
        break;
      case 'p': // ����
        Serial.println("p key(close) is clicked!");
        grasp1.close();
        break;
      case 'r': // ���Z�b�g
        Serial.println("r key(reset) is clicked!");
        grasp1.reset();
        break;
      default:
        break;
    }
  }
}
