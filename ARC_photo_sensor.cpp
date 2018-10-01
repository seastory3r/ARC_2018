// -----
// Abst : ���ߌ^�t�H�g�Z���T�̓���m�F
// Ref  : 
// -----
#define PIN_PHOTO_SENSOR1 22 // �t�H�g�Z���T�̃s���ԍ�(Digital)

void ps_init() {
  pinMode(PIN_PHOTO_SENSOR1, INPUT);
  
  Serial.begin(9600); // �V���A���ʐM�̓]�����x��9600bps�Ɏw��
}

void ps_photoSensor() {
  if(digitalRead(PIN_PHOTO_SENSOR1) == HIGH){
    Serial.println("Detected!!");
  }else{
    Serial.println("Not detected.");
  }
  delay(1000);
}
