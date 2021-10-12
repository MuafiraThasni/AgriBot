#include <LiquidCrystal.h> 
#define Left_Motor_Pin_1 9 
#define Left_Motor_Pin_2 10
#define Right_Motor_Pin_1 11 
#define Right_Motor_Pin_2 12 
#define Pump_Motor_Relay 8 
#define Seed_Motor_Pin_1 A2 
#define Seed_Motor_Pin_2 A3 
#define Plough_Motor_Pin_1 A4 #define Plaugh_Motor_Pin_2 A5 

int Received_char; 
long duration,distance; 
int forward=0; 
void setup() 
{ 
Serial.begin(9600); 
pinMode(Left_Motor_Pin_1,OUTPUT);
pinMode(Left_Motor_Pin_2,OUTPUT);
pinMode(Right_Motor_Pin_1,OUTPUT); 
pinMode(Right_Motor_Pin_2,OUTPUT);
pinMode(Plough_Motor_Pin_1 ,OUTPUT); 
pinMode(Plaugh_Motor_Pin_2,OUTPUT); 
pinMode(Seed_Motor_Pin_1,OUTPUT); 
pinMode(Seed_Motor_Pin_2,OUTPUT);
pinMode(Pump_Motor_Relay,OUTPUT);

digitalWrite(Left_Motor_Pin_1,HIGH); 
digitalWrite(Left_Motor_Pin_2,HIGH); 
digitalWrite(Right_Motor_Pin_1,HIGH);
digitalWrite(Right_Motor_Pin_2,HIGH);
digitalWrite(Seed_Motor_Pin_1,HIGH); 
digitalWrite(Seed_Motor_Pin_2,HIGH);
digitalWrite(Plough_Motor_Pin_1,HIGH); 
digitalWrite(Plaugh_Motor_Pin_2,HIGH); 
digitalWrite(Pump_Motor_Relay,LOW); 
}
void loop() 
{ 
if (Serial.available()) 
{ 
Received_char=Serial.read();
if(Received_char=='F')
{ digitalWrite(Left_Motor_Pin_1,LOW);
digitalWrite(Left_Motor_Pin_2,HIGH);
digitalWrite(Right_Motor_Pin_1,LOW);
digitalWrite(Right_Motor_Pin_2,HIGH); 
} 
else if(Received_char=='R') 
{ 
digitalWrite(Left_Motor_Pin_1,HIGH);
digitalWrite(Left_Motor_Pin_2,LOW); 
digitalWrite(Right_Motor_Pin_1,HIGH);
digitalWrite(Right_Motor_Pin_2,HIGH);
Serial.println("Going Right"); 
} 
else if(Received_char=='L')
{ digitalWrite(Left_Motor_Pin_1,HIGH);
digitalWrite(Left_Motor_Pin_2,HIGH);
digitalWrite(Right_Motor_Pin_1,HIGH); 
digitalWrite(Right_Motor_Pin_2,LOW); 
Serial.println("Going Left");
} 
else if(Received_char=='S')
{
digitalWrite(Left_Motor_Pin_1,HIGH); 
digitalWrite(Left_Motor_Pin_2,HIGH); 
digitalWrite(Right_Motor_Pin_1,HIGH);
digitalWrite(Right_Motor_Pin_2,HIGH); 
Serial.println("Stop moving"); 
}
else if(Received_char=='B')
{ 
digitalWrite(Left_Motor_Pin_1,HIGH); 
digitalWrite(Left_Motor_Pin_2,LOW); 
digitalWrite(Right_Motor_Pin_1,HIGH); 
digitalWrite(Right_Motor_Pin_2,LOW); 
Serial.println("Going Backward"); 
}
else if(Received_char=='P') 
{
digitalWrite(Plough_Motor_Pin_1,HIGH);
digitalWrite(Plaugh_Motor_Pin_2,LOW);
delay(2000); 
digitalWrite(Plough_Motor_Pin_1,HIGH); 
digitalWrite(Plaugh_Motor_Pin_2,HIGH); 
Serial.println("Ploughing Started");
} 
else if(Received_char=='p')
{ 
digitalWrite(Plough_Motor_Pin_1,LOW);
digitalWrite(Plaugh_Motor_Pin_2,HIGH); 
delay(1000); 
digitalWrite(Plough_Motor_Pin_1,HIGH);
digitalWrite(Plaugh_Motor_Pin_2,HIGH);
Serial.println("Ploughing Stops");
} 
else if(Received_char=='W')
{
digitalWrite(Pump_Motor_Relay,HIGH);
Serial.println("Watering Started"); 
} 
else if(Received_char=='w')
{ 
digitalWrite(Pump_Motor_Relay,LOW); 
Serial.println("Watering Stops");
} 
else if(Received_char=='D')
{ 
digitalWrite(Seed_Motor_Pin_1,LOW);
digitalWrite(Seed_Motor_Pin_2,HIGH);
delay(800); 
digitalWrite(Seed_Motor_Pin_1,HIGH);
digitalWrite(Seed_Motor_Pin_2,HIGH);
Serial.println("Seeding Started");
} 
else if(Received_char=='d')
{ 
digitalWrite(Seed_Motor_Pin_1,HIGH); 
digitalWrite(Seed_Motor_Pin_2,LOW); 
delay(800); 
digitalWrite(Seed_Motor_Pin_1,HIGH);
digitalWrite(Seed_Motor_Pin_2,HIGH); 
Serial.println("Seeding Stops");
} 
} 
}
