void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // 把持動作、車輪(両方), リフト(上下)を順番に動作させる
  // 把持動作：５秒Open、5秒Closeを３回繰り返す。 
  // 車両動作： ５秒前進、５秒後退、５秒旋回を３回繰り返す
  // リフト動作：1秒上動作、１秒下動作を３回繰り返す 

  // 把持動作
  // ３回繰り返し
    // サーボモータへOpen指示
  
    // 5秒wait
  
    // サーボモータへClose指示
  
    // ５秒wait

  // 把持動作を停止させる

  // 車両動作
  // ３回繰り返し
    // 前進指示

    // ５秒wait

    // 後退指示

    // ５秒wait

    // 旋回指示

    // ５秒wait

  // 停止指示

  // リフト動作
  // ３回繰り返し
    // リフトへ上動作指示

    // １秒wait

    // リフトへ下動作指示

    // １秒wait

  // リフトへ停止指示
  
  // put your main code here, to run repeatedly:

}
