// -----
// Abst : 上位モジュールからの要求に従い、グリップをOpen/Closeする
// Ref  : 
// -----
#include "ARCGrasp.h"

#define PIN_IN_SERVO1 6 // 把持動作で利用するピン番号

ARCGrasp grasp1;

void gr_init() {
  grasp1 = ARCGrasp(PIN_IN_SERVO1, 30, 100);
}

void gr_grasp(graspReq_t gr_req) {
  case eGrOpen: // オープン
    Serial.println("o key(open) is clicked!");
    grasp1.open();
    break;
  case eGrClose: // クローズ
    Serial.println("p key(close) is clicked!");
    grasp1.close();
    break;
  case eGrReset: // リセット
    Serial.println("r key(reset) is clicked!");
    grasp1.reset();
    break;
  default:
    break;
}
