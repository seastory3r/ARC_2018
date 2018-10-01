// -----
// Abst : ユーザーからの命令を取得する
// ARC_user_command.cpp[uc]
// -----
#include "ARC_user_command.h"
#include"arduino.h"

void uc_init(void){
  Serial2.begin(9600);
}

userCmd_t uc_tick(void){
  static userCmd_t userCmd = eUcDriveStop;

  // シリアルポートからデータを受ける場合1以上になる
  if(Serial2.available() > 0){
    switch(Serial2.read()){
      case 'w': // 前進
        userCmd = eUcDriveForward;
        break;
      case 'z': // 後退
        userCmd = eUcDriveReverse;
        break;
      case 'a': // 左まわり
        userCmd = eUcDriveCCW;
        break;
      case 'd': // 右まわり
        userCmd = eUcDriveCW;
        break;
      case 'q': // ストップ
        userCmd = eUcDriveStop;
        break;
      case 'x': // ブレーキ
        userCmd = eUcDriveBrake;
        break;
      case 'o': // オープン
        userCmd = eUcGraspOpen;
        break;
      case 'p': // クローズ
        userCmd = eUcGraspClose;
        break;
      case 'r': // リセット
        userCmd = eUcGraspReset;
        break;
      case 'u': // 上昇
        userCmd = eUcLiftUp;
        break;
      case 'h': // 下降
        userCmd = eUcLiftDown;
        break;
      case 'j': // ストップ
        userCmd = eUcLiftStop;
        break;
      case 'n': // ブレーキ
        userCmd = eUcLiftBrake;
        break;
      default:
        break;
    }
  }
}
