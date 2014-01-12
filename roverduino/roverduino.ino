#include <Servo.h>
#include <ctype.h> 

static int LEFT_FRONT_PWD = 3; //support analogwrite modulation
static int LEFT_FRONT_DIR = 2;

static int RIGHT_FRONT_PWD = 5; //support analogwrite modulation
static int RIGHT_FRONT_DIR = 4;

static int LEFT_REAR_PWD = 6; //support analogwrite modulation
static int LEFT_REAR_DIR = 7;

static int RIGHT_REAR_PWD = 9; //support analogwrite modulation
static int RIGHT_REAR_DIR = 8;

static int CAM_LR = 13;
static int CAM_UD = 12;

static int camLR = 90;
static int camUD = 90;

Servo servoLR,servoUD;

static int velocity = 100;

void setup()
{

  Serial.begin(9600);  

  pinMode(LEFT_FRONT_PWD, OUTPUT);
  pinMode(LEFT_FRONT_DIR, OUTPUT);

  pinMode(RIGHT_FRONT_PWD, OUTPUT);
  pinMode(RIGHT_FRONT_DIR, OUTPUT);

  pinMode(LEFT_REAR_PWD, OUTPUT);
  pinMode(LEFT_REAR_DIR, OUTPUT);

  pinMode(RIGHT_REAR_PWD, OUTPUT);
  pinMode(RIGHT_REAR_DIR, OUTPUT);

  pinMode(CAM_LR,OUTPUT);
  servoLR.attach(CAM_LR);

  pinMode(CAM_UD,OUTPUT);
  servoUD.attach(CAM_UD);


  Serial.println("SETUP COMPLETE");
}



void check(){

  //check LEFT_FRONT
  Serial.println("start check LEFT_FRONT");
  analogWrite(LEFT_FRONT_PWD, velocity);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  
  analogWrite(LEFT_FRONT_PWD, LOW);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  


  analogWrite(LEFT_FRONT_PWD, velocity);  
  digitalWrite(LEFT_FRONT_DIR, HIGH);   
  delay(500);                  
  analogWrite(LEFT_FRONT_PWD, LOW);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  




  //check RIGHT_FRONT_PWD
  Serial.println("start check RIGHT_FRONT");
  analogWrite(RIGHT_FRONT_PWD, velocity);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  
  analogWrite(RIGHT_FRONT_PWD, LOW);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  


  analogWrite(RIGHT_FRONT_PWD, velocity);  
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   
  delay(500);                  
  analogWrite(RIGHT_FRONT_PWD, LOW);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  


  //check RIGHT_REAR
  Serial.println("start check RIGHT_REAR");
  analogWrite(RIGHT_REAR_PWD, velocity);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
  delay(500);                  
  analogWrite(RIGHT_REAR_PWD, LOW);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
  delay(500);                  


  analogWrite(RIGHT_REAR_PWD, velocity);  
  digitalWrite(RIGHT_REAR_DIR, HIGH);   
  delay(500);                  
  analogWrite(RIGHT_REAR_PWD, LOW);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
  delay(500);                  


  //check LEFT_REAR
  Serial.println("start check LEFT_REAR");
  analogWrite(LEFT_REAR_PWD, velocity);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  
  analogWrite(LEFT_REAR_PWD, LOW);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  


  analogWrite(LEFT_REAR_PWD, velocity);  
  digitalWrite(LEFT_REAR_DIR, HIGH);   
  delay(500);                  
  analogWrite(LEFT_REAR_PWD, LOW);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  




}

void forward(){

  //LEFT_FRONT
  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, HIGH);   

  //RIGHT_FRONT
  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   

  //LEFT_REAR
  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, LOW);   

  //RIGHT_REAR
  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   

  delay(50);                  

}

void left(){

  //LEFT_FRONT
  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, HIGH);   

  //RIGHT_FRONT
  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   

  //LEFT_REAR
  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, LOW);   

  //RIGHT_REAR
  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, HIGH);   

  delay(50);                

}

void right(){

  //LEFT_FRONT
  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   

  //RIGHT_FRONT
  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   

  //LEFT_REAR
  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, HIGH);   

  //RIGHT_REAR
  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   

  delay(50);                  

}

void back(){

  //LEFT_FRONT
  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   

  //RIGHT_FRONT
  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   

  //LEFT_REAR
  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, HIGH);   

  //RIGHT_REAR
  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, HIGH);   

  delay(50);                    

}

void stop(){

  //LEFT_FRONT
  digitalWrite(LEFT_FRONT_PWD, LOW);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   

  //RIGHT_FRONT
  digitalWrite(RIGHT_FRONT_PWD, LOW);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   

  //LEFT_REAR
  digitalWrite(LEFT_REAR_PWD, LOW);  
  digitalWrite(LEFT_REAR_DIR, LOW);   

  //RIGHT_REAR
  digitalWrite(RIGHT_REAR_PWD, LOW);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   

  delay(50);                    

}

void sendMsg(String message, boolean r, String type){
  Serial.println("{type:" + type + ",result:" + (String)r + ", message:'" +message+"'}");
}

int limitCamLR(int camLR){

  if(camLR >= 180){
    camLR = 180;
  } 
  else if(camLR <= 0){
    camLR = 0;
  }

  return camLR;

}

int limitCamUD(int camUD){


  if(camUD >= 160){
    camUD = 160;
  }
  else if(camUD <= 10){
    camUD = 10;
  }

  return camUD;
}


void help(){
  String h = "[F] Forward -";
  h += "[L] Left -";
  h += "[R] Right -";
  h += "[B] Back -";
  h += "[S] Stop -";
  h += "[T] Cam left -";
  h += "[Y] Cam right -";
  h += "[Q] Cam down -";
  h += "[A] Cam up -";
  h += "[U] Cam reset -";
  h += "[H] Help";
  sendMsg(h, true, "info");

}

int camLeft(int camLR){
  sendMsg("Call Cam Left " + (String)camLR, true, "debug");
  camLR = camLR +10;
  servoLR.write(camLR);
  return camLR;
}

int camRight(int camLR){
  sendMsg("Call Cam Right " + (String)camLR, true, "debug");
  camLR = camLR - 10;
  servoLR.write(camLR);
  return camLR;
}

int camUp(int camUD){
  sendMsg("Call Cam Up " + (String)camUD, true, "debug");
  camUD = camUD -10;
  servoUD.write(camUD);
  return camUD;
}

int camDown(int camUD){
  sendMsg("Call Cam Down " + (String)camUD, true, "debug");
  camUD = camUD + 10;
  servoUD.write(camUD);
  return  camUD;
}

void loop(){

  camUD = limitCamUD(camUD);
  camLR = limitCamLR(camLR);

  if (Serial.available() > 0) {
    char ch = toupper(Serial.read());
    //Serial.println(ch);
    
    switch(ch){
    
      case 'U' :
      camLR = camLeft(80);
      delay(50);                
      camUD = camUp(80);
      delay(50);                
      break;

    case 'T' :
      camLR = camLeft(camLR);
      delay(50);                
      break;

    case 'Y' :
      camLR = camRight(camLR);
      delay(50);
      break;

    case 'A' :
      camUD = camUp(camUD);
      delay(50);
      break;

    case 'Q' :
      camUD = camDown(camUD);
      delay(50);
      break;

    case 'C' :
      sendMsg("Call Check", true, "debug");
      check();
      break;

    case 'F' :    
      sendMsg("Call Forward", true, "debug");
      forward();
      break;
    
    case 'S' :    
      sendMsg("Call Stop", true, "debug");
      stop();
      break;
    
    case 'B' :    
      sendMsg("Call Back", true, "debug");
      back();
      break;
    
    case 'L' :    
      sendMsg("Call Left", true, "debug");
      left();
      break;
    
    case 'R' :    
      sendMsg("Call Right", true, "debug");
      right();
      break;
    
    case 'H' :    
      sendMsg("Call Help", true, "debug");
      help();
      break;
    }
  }
}








