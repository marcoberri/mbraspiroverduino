
/*
Autor: Marco Berri marcoberri@gmail.com 
 Web Author : http://tecnicume.blogspot.it
 Project: https://github.com/marcoberri/mbraspiroverduino 
 */

#include <Servo.h>
#include <ctype.h> 
#include <NewPing.h>

const  short LEFT_FRONT_PWD = 3; //support analogwrite modulation
const  short LEFT_FRONT_DIR = 2;

const  short RIGHT_FRONT_PWD = 5; //support analogwrite modulation
const  short RIGHT_FRONT_DIR = 4;

const  short LEFT_REAR_PWD = 6; //support analogwrite modulation
const  short LEFT_REAR_DIR = 7;

const  short RIGHT_REAR_PWD = 9; //support analogwrite modulation
const  short RIGHT_REAR_DIR = 8;

const  short CAM_LR = 13;
const  short CAM_UD = 12;

static short camLR = 90;
static short camUD = 90;

const  short TRIGGER_PIN = 11;
const  short ECHO_PIN = 10;
const  short MAX_DISTANCE = 200;

Servo servoLR,servoUD;
static short velocity = 100;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

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

void getVelocity(){
  sendMsg(""+velocity, true, "velocity");
}

void forward(){
  sendMsg("Call Forward", true, "debug");

  //LEFT_FRONT
  analogWrite(LEFT_FRONT_PWD, velocity);  
  digitalWrite(LEFT_FRONT_DIR, HIGH);   

  //RIGHT_FRONT
  analogWrite(RIGHT_FRONT_PWD, velocity);
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   

  //LEFT_REAR
  analogWrite(LEFT_REAR_PWD, velocity);
  digitalWrite(LEFT_REAR_DIR, LOW);   

  //RIGHT_REAR
  analogWrite(RIGHT_REAR_PWD, velocity);
  digitalWrite(RIGHT_REAR_DIR, LOW);   

  delay(50);                  

}

void left(){
  sendMsg("Call Left", true, "debug");

  //LEFT_FRONT
  analogWrite(LEFT_FRONT_PWD, velocity);
  digitalWrite(LEFT_FRONT_DIR, HIGH);   

  //RIGHT_FRONT
  analogWrite(RIGHT_FRONT_PWD, velocity);
  digitalWrite(RIGHT_FRONT_DIR, LOW);   

  //LEFT_REAR
  analogWrite(LEFT_REAR_PWD, velocity);
  digitalWrite(LEFT_REAR_DIR, LOW);   

  //RIGHT_REAR
  analogWrite(RIGHT_REAR_PWD, velocity);
  digitalWrite(RIGHT_REAR_DIR, HIGH);   

  delay(50);                

}

void right(){
  sendMsg("Call Right", true, "debug");

  //LEFT_FRONT
  analogWrite(LEFT_FRONT_PWD, velocity);
  digitalWrite(LEFT_FRONT_DIR, LOW);   

  //RIGHT_FRONT
  analogWrite(RIGHT_FRONT_PWD, velocity);
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   

  //LEFT_REAR
  analogWrite(RIGHT_REAR_PWD, velocity);
  digitalWrite(LEFT_REAR_DIR, HIGH);   

  //RIGHT_REAR
  analogWrite(RIGHT_REAR_PWD, velocity);
  digitalWrite(RIGHT_REAR_DIR, LOW);   

  delay(50);                  

}

void back(){
  sendMsg("Call Back", true, "debug");

  //LEFT_FRONT
  analogWrite(LEFT_FRONT_PWD, velocity);
  digitalWrite(LEFT_FRONT_DIR, LOW);   

  //RIGHT_FRONT
  analogWrite(RIGHT_FRONT_PWD, velocity);
  digitalWrite(RIGHT_FRONT_DIR, LOW);   

  //LEFT_REAR
  analogWrite(LEFT_REAR_PWD, velocity);
  digitalWrite(LEFT_REAR_DIR, HIGH);   

  //RIGHT_REAR
  analogWrite(RIGHT_REAR_PWD, velocity);
  digitalWrite(RIGHT_REAR_DIR, HIGH);   

  delay(50);                    

}

void stop(){
  sendMsg("Call Stop", true, "debug");

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
  String r_string = "true";
  if(r == false)
    r_string = "false"; 
    
  Serial.println("{\"type\":\"" + type + "\",\"result\":" + r_string + ", \"message\":\"" +message+"\"}");
}

short limitCamLR(short camLR){

  if(camLR >= 180){
    camLR = 180;
  } 
  else if(camLR <= 0){
    camLR = 0;
  }
  return camLR;
}

short limitCamUD(short camUD){

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
  h += "[+] Acc -";
  h += "[-] Dec -";
  h += "[V] Vel Act";
  h += "[M] Cam max left -";
  h += "[T] Cam left -";
  h += "[N] Cam max right -";
  h += "[Y] Cam right -";
  h += "[Q] Cam down -";
  h += "[A] Cam up -";
  h += "[U] Cam reset -";
  h += "[H] Help";
  sendMsg(h, true, "info");

}

short camLeft(short camLR){
  sendMsg("Call Cam Left " + (String)camLR, true, "debug");
  camLR = camLR +10;
  servoLR.write(camLR);
  return camLR;
}

short camRight(short camLR){
  sendMsg("Call Cam Right " + (String)camLR, true, "debug");
  camLR = camLR - 10;
  servoLR.write(camLR);
  return camLR;
}

short camUp(short camUD){
  sendMsg("Call Cam Up " + (String)camUD, true, "debug");
  camUD = camUD -10;
  servoUD.write(camUD);
  return camUD;
}

short camDown(short camUD){
  sendMsg("Call Cam Down " + (String)camUD, true, "debug");
  camUD = camUD + 10;
  servoUD.write(camUD);
  return  camUD;
}

void pingFront(){
  short uS = sonar.ping(); 
  sendMsg((String)(uS / US_ROUNDTRIP_CM), true, "ping-front");
}

void loop(){

  pingFront(); 
  camUD = limitCamUD(camUD);
  camLR = limitCamLR(camLR);

  if (Serial.available() > 0) {
    char ch = toupper(Serial.read());

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

    case 'M' :
      camLR = camLeft(10);
      delay(50);                
      break;

    case 'Y' :
      camLR = camRight(camLR);
      delay(50);
      break;

    case 'N' :
      camLR = camRight(170);
      delay(50);                
      break;

    case 'A' :
      camUD = camUp(camUD);
      delay(50);
      break;

    case '+' :
      velocity += 10;
      break;

    case '-' :
      if(velocity-10 <=0){
        velocity = 0;
      }
      else{
        velocity -= 10;
      }
      break;

    case 'V' :
      getVelocity();
      break;

    case 'Q' :
      camUD = camDown(camUD);
      delay(50);
      break;


    case 'C' :
      check();
      break;

    case 'F' :    
      forward();
      break;

    case 'S' :    
      stop();
      break;

    case 'B' :    
      back();
      break;

    case 'L' :    
      left();
      break;

    case 'R' :    
      right();
      break;

    case 'H' :    
      help();
      break;
    }
  }
}
