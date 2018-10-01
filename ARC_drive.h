// -----
// Abst : 車両を駆動させる
// -----

#ifndef ARC_DRIVE_H
#define ARC_DRIVE_H

#include "ARC_common.h"
#include "ARC_user_command.h"

extern void dr_init();
extern void dr_tick(userCmd_t);

#endif //ARC_DRIVE_H
