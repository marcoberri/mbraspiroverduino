


/*
Autor: Marco Berri marcoberri@gmail.com
 Web Author : http://tecnicume.blogspot.it
 Project: https://github.com/marcoberri/mbraspiroverduino
 */

#include <Servo.h>
#include <ctype.h>
#include <NewPing.h>
#include <I2Cdev.h>
#include <MPU6050.h>


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include <Wire.h>
#endif

const  short LEFT_FRONT_PWD = 3; //support analogwrite modulation
const  short LEFT_FRONT_DIR = 22;

const  short RIGHT_FRONT_PWD = 4; //support analogwrite modulation
const  short RIGHT_FRONT_DIR = 23;

const  short LEFT_REAR_PWD = 5; //support analogwrite modulation
const  short LEFT_REAR_DIR = 24;

const  short RIGHT_REAR_PWD = 6; //support analogwrite modulation
const  short RIGHT_REAR_DIR = 25;

//CAM TILT PAN
const  short CAM_LR = 26;
const  short CAM_UD = 27;

static short camLR = 90;
static short camUD = 90;


//PING CONF
const  short TRIGGER_PIN_FRONT = 7;
const  short ECHO_PIN_FRONT = 8;

const  short TRIGGER_PIN_BACK = 9;
const  short ECHO_PIN_BACK = 10;

const  short MAX_DISTANCE_FRONT = 200; //in cm
short cacheFront = 0;

NewPing sonar(TRIGGER_PIN_FRONT, ECHO_PIN_FRONT, MAX_DISTANCE_FRONT);



//MPU5060
MPU6050 accelgyro;
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}
int16_t ax, ay, az;
int16_t gx, gy, gz;
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU


//SERVO
Servo servoLR, servoUD;
static short velocity = 100;


void setup()
{
  Serial.begin(9600);


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  accelgyro.initialize();
 //   accelgyro.setXGyroOffset(220);
 //   accelgyro.setYGyroOffset(76);
 //   accelgyro.setZGyroOffset(-85);
 //   accelgyro.setZAccelOffset(1788); // 1688 factory default for my test chip

        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = accelgyro.getIntStatus();

    

  pinMode(LEFT_FRONT_PWD, OUTPUT);
  pinMode(LEFT_FRONT_DIR, OUTPUT);

  pinMode(RIGHT_FRONT_PWD, OUTPUT);
  pinMode(RIGHT_FRONT_DIR, OUTPUT);

  pinMode(LEFT_REAR_PWD, OUTPUT);
  pinMode(LEFT_REAR_DIR, OUTPUT);

  pinMode(RIGHT_REAR_PWD, OUTPUT);
  pinMode(RIGHT_REAR_DIR, OUTPUT);

  pinMode(CAM_LR, OUTPUT);
  servoLR.attach(CAM_LR);

  pinMode(CAM_UD, OUTPUT);
  servoUD.attach(CAM_UD);

  Serial.println("SETUP COMPLETE");
}



void check() {

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

void getVelocity() {
  sendMsg("" + velocity, true, "velocity");
}

void forward() {
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

void left() {
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

void right() {
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

void back() {
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

void stop() {
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

void sendMsg(String message, boolean r, String type) {
  String r_string = "true";
  if (r == false)
    r_string = "false";

  Serial.println("{\"type\":\"" + type + "\",\"result\":" + r_string + ", \"message\":\"" + message + "\"}");
}

short limitCamLR(short camLR) {

  if (camLR >= 180) {
    camLR = 180;
  }
  else if (camLR <= 0) {
    camLR = 0;
  }
  return camLR;
}

short limitCamUD(short camUD) {

  if (camUD >= 160) {
    camUD = 160;
  }
  else if (camUD <= 10) {
    camUD = 10;
  }

  return camUD;
}


void help() {
  String h = "{\"F\":\"Forward\",";
  h += "\"L\":\"Left\",";
  h += "\"R\":\"Right\",";
  h += "\"B\":\"Back\",";
  h += "\"S\":\"Stop\",";
  h += "\"+\":\"Acc\",";
  h += "\"-\":\"Dec\",";
  h += "\"V\":\"Vel Act\",";
  h += "\"M\":\"Cam max left\",";
  h += "\"T\":\"Cam left\",";
  h += "\"N\":\"Cam max right\",";
  h += "\"Y\":\"Cam right\",";
  h += "\"Q\":\"Cam down\",";
  h += "\"A\":\"Cam up\",";
  h += "\"U\":\"Cam reset\",";
  h += "\"C\":\"Check\",";
  h += "\"H\":\"Help\"}";
  sendMsg(h, true, "info");

}

short camLeft(short camLR) {
  sendMsg("Call Cam Left " + (String)camLR, true, "debug");
  camLR = camLR + 10;
  servoLR.write(camLR);
  return camLR;
}

short camRight(short camLR) {
  sendMsg("Call Cam Right " + (String)camLR, true, "debug");
  camLR = camLR - 10;
  servoLR.write(camLR);
  return camLR;
}

short camUp(short camUD) {
  sendMsg("Call Cam Up " + (String)camUD, true, "debug");
  camUD = camUD - 10;
  servoUD.write(camUD);
  return camUD;
}

short camDown(short camUD) {
  sendMsg("Call Cam Down " + (String)camUD, true, "debug");
  camUD = camUD + 10;
  servoUD.write(camUD);
  return  camUD;
}

void pingFront() {
  short uS = sonar.ping();
  if (cacheFront != uS) {
    cacheFront = uS;
    sendMsg((String)(uS / US_ROUNDTRIP_CM), true, "ping-front");
  }
}

void loop() {


  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);



  Serial.print("a/g:\t");
  
Serial.print(" ax:");  Serial.print(ax); Serial.print("\t");
  Serial.print(" ay:");  Serial.print(ay); Serial.print("\t");
  Serial.print(" az:");  Serial.print(az); Serial.print("\t");
  Serial.print(" gx:");  Serial.print(gx); Serial.print("\t");
  Serial.print(" gy:");  Serial.print(gy); Serial.print("\t");
  Serial.println();
  
  delay(1000);


  pingFront();
  camUD = limitCamUD(camUD);
  camLR = limitCamLR(camLR);

  if (Serial.available() > 0) {
    char ch = toupper(Serial.read());

    switch (ch) {

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
        if (velocity - 10 <= 0) {
          velocity = 0;
        }
        else {
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
