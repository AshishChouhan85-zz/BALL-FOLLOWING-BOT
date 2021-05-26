#include<SoftwareSerial.h>

SoftwareSerial mySerial(A3,A4); //RX,TX


int PWM1=3; //MOTOR 1 PWM
int PWM2=5; //MOTOR 2 PWM
int M1F=2; //MOTOR 1 FORWARD PIN
int M1B=4; //MOTOR 1 BACKWARD PIN
int M2F=7; //MOTOR 2 FORWARD PIN
int M2B=8; // MOTOR 2 BACKWARD PIN


char Data;

void setup() {
mySerial.begin(9600);

pinMode(A1,OUTPUT);  
pinMode(A2,OUTPUT); 

pinMode(M1F,OUTPUT);  
pinMode(M1B,OUTPUT); 
pinMode(M2F,OUTPUT); 
pinMode(M2B,OUTPUT);

digitalWrite(A1,HIGH);
digitalWrite(A2,LOW);

}


    // 0 - STAY
    // 1 - FORWARD
    // 2 - LEFT
    // 3 - RIGHT



void loop() {
if(mySerial.available()!=0)
{Data=mySerial.read();


 if(Data=='0')
  {digitalWrite(M1F,LOW);
  digitalWrite(M1B,LOW);
  digitalWrite(M2F,LOW);
  digitalWrite(M2B,LOW);
  analogWrite(PWM1,0);
  analogWrite(PWM2,0);
 }


  if(Data=='1')
  {digitalWrite(M1F,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2F,HIGH);
  digitalWrite(M2B,LOW);
  analogWrite(PWM1,100);
  analogWrite(PWM2,110);
 }
 
 


 if(Data=='2')
 {digitalWrite(M1F,LOW);
  digitalWrite(M1B,HIGH);
  digitalWrite(M2F,HIGH);
  digitalWrite(M2B,LOW);  
  analogWrite(PWM2,0);
  analogWrite(PWM1,98);
 }
 
 if(Data=='3')
{digitalWrite(M1F,HIGH);
  digitalWrite(M1B,LOW);
  digitalWrite(M2F,LOW);
  digitalWrite(M2B,HIGH); 
  analogWrite(PWM1,98);
 analogWrite(PWM2,0);
  
  }


  
}

}
