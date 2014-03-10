#include "MTADRL293D.h"

MTADRL293D l293d;

void setup(){
  Serial.begin(115200);
  
  delay(5000);
  
  Serial.println("=== setup() ===");

  Serial.println("=== setup() === init MTADRL293D");
  //l293d.enableDbg(true);
  l293d.begin();

  l293d.setMotorDir(MTADRL293D_M1, MTADRL293D_DIR_POS);
  l293d.setMotorDir(MTADRL293D_M2, MTADRL293D_DIR_POS);
  l293d.setMotorDir(MTADRL293D_M3, MTADRL293D_DIR_POS);
  l293d.setMotorDir(MTADRL293D_M4, MTADRL293D_DIR_POS);

  l293d.setMinMotorSpeed(MTADRL293D_M1, 100);
  l293d.setMinMotorSpeed(MTADRL293D_M2, 100);
  l293d.setMinMotorSpeed(MTADRL293D_M3, 100);
  l293d.setMinMotorSpeed(MTADRL293D_M4, 100);

  l293d.setMotorSpeed(MTADRL293D_M1, 0);
  l293d.setMotorSpeed(MTADRL293D_M2, 0);
  l293d.setMotorSpeed(MTADRL293D_M3, 0);
  l293d.setMotorSpeed(MTADRL293D_M4, 0);
  
  
  Serial.println("=== setup() === init BT module");
  Serial1.begin(38400);
  
}

void processCmd(char c){
  Serial.println("=== processCmd() === cmd: " + String(c));
  switch(c){
    case '^':
      l293d.setMotorDir(MTADRL293D_M1, MTADRL293D_DIR_NEG);
      l293d.setMotorDir(MTADRL293D_M3, MTADRL293D_DIR_NEG);
      l293d.setMotorSpeed(MTADRL293D_M1, 255);
      l293d.setMotorSpeed(MTADRL293D_M3, 255);
      break;
    case '<':
      l293d.setMotorDir(MTADRL293D_M1, MTADRL293D_DIR_NEG);
      l293d.setMotorDir(MTADRL293D_M3, MTADRL293D_DIR_POS);
      l293d.setMotorSpeed(MTADRL293D_M1, 255);
      l293d.setMotorSpeed(MTADRL293D_M3, 255);
      break;
    case '>':
      l293d.setMotorDir(MTADRL293D_M1, MTADRL293D_DIR_POS);
      l293d.setMotorDir(MTADRL293D_M3, MTADRL293D_DIR_NEG);
      l293d.setMotorSpeed(MTADRL293D_M1, 255);
      l293d.setMotorSpeed(MTADRL293D_M3, 255);
      break;
    case 'v':
      l293d.setMotorDir(MTADRL293D_M1, MTADRL293D_DIR_POS);
      l293d.setMotorDir(MTADRL293D_M3, MTADRL293D_DIR_POS);
      l293d.setMotorSpeed(MTADRL293D_M1, 255);
      l293d.setMotorSpeed(MTADRL293D_M3, 255);
      break;
    case '-':
      l293d.setMotorSpeed(MTADRL293D_M1, 0);
      l293d.setMotorSpeed(MTADRL293D_M3, 0);
      break;
  }
}

#define CMD_MAX 256
void loop(){
//  Serial.println("=== loop() ===");

  while(Serial1.available()){
    processCmd(Serial1.read());
  }

}



