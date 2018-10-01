// -----
// Abst : グリップをOpen/Closeする
// Ref  : 
// -----

#ifndef ARC_GRASP_H
#define ARC_GRASP_H

#include "ARC_common.h"
#include "ARC_user_command.h"



extern void gr_init();
extern void gr_tick(userCmd_t);

#endif //ARC_GRASP_H
