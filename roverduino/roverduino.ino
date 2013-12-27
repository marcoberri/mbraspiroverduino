#include <Servo.h>
#include <ctype.h> 

static int LEFT_FRONT_PWD = 2;
static int LEFT_FRONT_DIR = 3;

static int RIGHT_FRONT_PWD = 4;
static int RIGHT_FRONT_DIR = 5;

static int LEFT_REAR_PWD = 6;
static int LEFT_REAR_DIR = 7;

static int RIGHT_REAR_PWD = 8;
static int RIGHT_REAR_DIR = 9;

static int CAM_LR = 13;

static int camLR = 90;
Servo servoLR;

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


  Serial.println("SETUP COMPLETE");
}



void check(){


  //check LEFT_FRONT
  Serial.println("start check LEFT_FRONT");
  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  
  digitalWrite(LEFT_FRONT_PWD, LOW);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  


  digitalWrite(LEFT_FRONT_PWD, HIGH);  
  digitalWrite(LEFT_FRONT_DIR, HIGH);   
  delay(500);                  
  digitalWrite(LEFT_FRONT_PWD, LOW);  
  digitalWrite(LEFT_FRONT_DIR, LOW);   
  delay(500);                  




  //check RIGHT_FRONT_PWD
  Serial.println("start check RIGHT_FRONT");
  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  
  digitalWrite(RIGHT_FRONT_PWD, LOW);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  


  digitalWrite(RIGHT_FRONT_PWD, HIGH);  
  digitalWrite(RIGHT_FRONT_DIR, HIGH);   
  delay(500);                  
  digitalWrite(RIGHT_FRONT_PWD, LOW);  
  digitalWrite(RIGHT_FRONT_DIR, LOW);   
  delay(500);                  



  //check LEFT_REAR
  Serial.println("start check LEFT_REAR");
  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  
  digitalWrite(LEFT_REAR_PWD, LOW);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  


  digitalWrite(LEFT_REAR_PWD, HIGH);  
  digitalWrite(LEFT_REAR_DIR, HIGH);   
  delay(500);                  
  digitalWrite(LEFT_REAR_PWD, LOW);  
  digitalWrite(LEFT_REAR_DIR, LOW);   
  delay(500);                  



  //check RIGHT_REAR
  Serial.println("start check RIGHT_REAR");
  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
  delay(500);                  
  digitalWrite(RIGHT_REAR_PWD, LOW);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
  delay(500);                  


  digitalWrite(RIGHT_REAR_PWD, HIGH);  
  digitalWrite(RIGHT_REAR_DIR, HIGH);   
  delay(500);                  
  digitalWrite(RIGHT_REAR_PWD, LOW);  
  digitalWrite(RIGHT_REAR_DIR, LOW);   
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


void help(){


  String h = "[F] - Forward";
  h += "[L] - Left";
  h += "[R] - Right";
  h += "[B] - Back";
  h += "[S] - Stop";
  h += "[T] - Cam left";
  h += "[Y] - Cam right";
  h += "[U] - Cam reset";
  h += "[H] - Help";


  sendMsg(h, true, "info");

}

void loop(){

  if(camLR >= 180){
    camLR = 180;
  }

  if(camLR <= 0){
    camLR = 0;
  }

  if (Serial.available() > 0) {


    char ch = toupper(Serial.read());

    Serial.println(ch);

    switch(ch){



    case 'U' :
      sendMsg("Call Cam Reset", true, "debug");
      camLR = 90;
      servoLR.write(v);
      break;

    case 'T' :
      sendMsg("Call Cam Left", true, "debug");
      camLR = camLR +10;
      servoLR.write(camLR);
      break;

    case 'Y' :
      sendMsg("Call Cam Right", true, "debug");
      camLR = camLR - 10;
      servoLR.write(camLR);
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





