// -----
// Abst : グリップをOpen/Closeする
// Ref  : 
// -----

#ifndef ARC_GRASP_H
#define ARC_GRASP_H

#inlcude "ARC_common.h"

//グリップを開閉させる要求
typedef enum {
  eGrOpen,  //オープン
  eGrClose, //クローズ
  eGrReset, //リセット
} graspReq_t;

extern void gr_init();
extern void gr_grasp(graspReq_t);

#endif //ARC_GRASP_H
