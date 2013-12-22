int LEFT_FRONT_PWD = 2;
int LEFT_FRONT_DIR = 3;

int RIGHT_FRONT_PWD = 4;
int RIGHT_FRONT_DIR = 5;

int LEFT_REAR_PWD = 6;
int LEFT_REAR_DIR = 7;

int RIGHT_REAR_PWD = 8;
int RIGHT_REAR_DIR = 9;

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
  h += "[H] - Help";

  sendMsg(h, true, "info");

}

void loop(){

     
  if (Serial.available() > 0) {
  
    char ch = Serial.read();

  Serial.println(ch);

    
    if (ch == 'c' || ch == 'C') 
    {
      sendMsg("Call Check", true, "debug");
      check();
    }
    else if(ch == 'f' || ch=='F'){
      sendMsg("Call Forward", true, "debug");
      forward();
    }
    else if(ch == 's' || ch=='S'){
      sendMsg("Call Stop", true, "debug");

      stop();
    }
    else if(ch == 'b' || ch=='B'){
      sendMsg("Call Back", true, "debug");


      back();
    }
    else if(ch == 'l' || ch=='L'){
      sendMsg("Call Left", true, "debug");


      left();
    }
    else if(ch == 'r' || ch=='R'){
      sendMsg("Call Right", true, "debug");

      right();
    }

    else if(ch == 'h' || ch=='H'){
      sendMsg("Call Help", true, "debug");

      help();
    }

  }
}
