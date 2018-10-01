// -----
// Abst : リフトを上下する
// Ref  : 
// -----

#ifndef ARC_LIFT_H
#define ARC_LIFT_H

#inlcude "ARC_common.h"

//リフトを上下させる要求
typedef enum {
  eLfUp,    //上昇
  eLfDown,  //下降
  eLfStop,  //停止
  eLfBrake, //ブレーキ
} liftReq_t;

extern void lf_init();
extern void lf_lift(liftReq_t);

#endif //ARC_LIFT_H
