// -----
// Abst : ユーザーからの命令を取得する
// -----
#ifndef ARC_USER_COMMAND_H
#define ARC_USER_COMMAND_H

//ユーザーからの命令群、キーボードからの入力をこれらに変換し外部モジュールへ公開する
typedef enum {
  eUcDriveForward,
  eUcDriveReverse,
  eUcDriveCCW,
  eUcDriveCW,
  eUcDriveStop,
  eUcDriveBrake,
  eUcGraspOpen,
  eUcGraspClose,
  eUcGraspReset,
  eUcLiftUp,
  eUcLiftDown,
  eUcLiftStop,
  eUcLiftBrake,
} userCmd_t;

extern void uc_init(void);
extern userCmd_t uc_tick(void);

#endif //ARC_USER_COMMAND_H
