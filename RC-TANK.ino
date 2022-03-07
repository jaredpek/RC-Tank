#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include  <Servo.h>

Servo servo1;
Servo servo2;

//Motor A
const int inputPin1  = 5;    // Pin 15 of L293D IC, D1 Pin of NodeMCU
const int inputPin2  = 16;    // Pin 10 of L293D IC, D0 Pin of NodeMCU

//Motor B
const int inputPin3  = 4;    // Pin  7 of L293D IC, D2 Pin of NodeMCU
const int inputPin4  = 0;    // Pin  2 of L293D IC, D3 Pin of NodeMCU

//Speed Controls
int EN1 = 12;                 // Pin 15 of L293D IC, D6 Pin of NodeMCU
int EN2 = 14;                 // Pin 9 of L293D IC, D5 Pin of NodeMCU

// Go to the Project Settings
char auth[] = <BYLNK AUTH KEY>;
char ssid[] = <PHONE HOTSPOT SSID>; 
char pass[] = <HOTSPOT PASSWORD>; 

BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();

  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);

// Joystick Movement
  if (x==0 && y==1)
    {
    Serial.print("forward");
    forward();
    }

  if (x==0 && y==-1) 
    {
      Serial.print("backward");
      backward();
    }

   if (x==-1 && y==0)
    {
      Serial.print("left");
      left();
    }
 
  if (x==1 && y==0) 
    {
      Serial.print("right");
      right();
    }

  if (x==0 && y==0)
    {
      Serial.print("stop");
      stop();
     }

  if (x==1 && y==1)
    {
      Serial.print("forwardright");
      forwardright();
     }
     
  if (x==1 && y==-1)
    {
      Serial.print("backwardright");
      backwardright();
     }
     
  if (x==-1 && y==1)
    {
      Serial.print("forwardleftt");
      forwardleft();
     }
     
  if (x==-1 && y==-1)
    {
      Serial.print("backwardleft");
      backwardleft();
     }
}

BLYNK_WRITE(V2){
  servo1.write(param.asInt());
}

BLYNK_WRITE(V3){
  servo2.write(param.asInt());
}


void setup()
{
    pinMode(EN1, OUTPUT);   // where the motor is connected to
    pinMode(EN2, OUTPUT);   // where the motor is connected to
    analogWrite(EN1, 900);
    analogWrite(EN2, 900);
    pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);  
    servo1.attach(13,1100,1900); //D7
    servo1.write(90);
    servo2.attach(15,600,2400); //D8
    servo2.write(90);
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

void left(void)
{
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);  
}

void right(void)
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH); 
}

void stop(void)
{ 
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW); 
}

void backward(void)
{   
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW); 
}

void forward(void)
{ 
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH); 
}

void forwardright(void)
{ 
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, HIGH); 
}

void backwardright(void)
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, HIGH);
    digitalWrite(inputPin4, LOW);  
}

void backwardleft(void)
{
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);  
}

void forwardleft(void)
{
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    digitalWrite(inputPin3, LOW);
    digitalWrite(inputPin4, LOW);  
}
