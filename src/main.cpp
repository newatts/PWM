#include <Arduino.h>

int but2 = 2;  // 20%
//int but3 = 3;     //potential PWM   
int but4 = 4;   //40%
//int but5 = 5;  //potential PWM   
//int but6 = 6;   //potential PWM   
int but7 = 7;  //60%
int but8 = 8;  //80%
//int but9 = 9;  //100%
//int butA = 10;    //potential PWM   
//int butB = 11;   //potential PWM   
int butC = 12;   //100%

//int analogInPin = A4; // potentiometer wiper (middle terminal) connected to analog pin 3

const int pwmOutPin = 11;  //digital Pin 11 //can use 10,9,6,5,3

int val =0;

int PWMfinal = 0;
int PWMout = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(pwmOutPin, OUTPUT); ///plug your control line into pin 11.

  //outputs
  pinMode(but2, INPUT_PULLUP);   //LOW is on. 
  //pinMode(but3, INPUT_PULLUP);
  pinMode(but4, INPUT_PULLUP);
 // pinMode(but5, INPUT_PULLUP);
 // pinMode(but6, INPUT_PULLUP);
  pinMode(but7, INPUT_PULLUP);
  pinMode(but8, INPUT_PULLUP);
  //pinMode(but9, INPUT_PULLUP);
  //pinMode(butA, INPUT_PULLUP);
}

void loop()
{
  Serial.println("Hello");
  
  //
    if (digitalRead(but2) == LOW)       //not 
    {
    // turn LED on:
      PWMfinal = 20;
      Serial.println("20%");
    }else if(digitalRead(but4) == LOW)     //working
    {
    // turn LED on:
      PWMfinal = 40;
      Serial.println("40%");
    }else if(digitalRead(but4) == LOW)     //not
    {
      // turn LED on:
      PWMfinal = 60;
      Serial.println("60%");
    }else if(digitalRead(but7) == LOW)   //not
    {
    // turn LED on:
      PWMfinal = 80;
      Serial.println("80%");
    }else if(digitalRead(butC) == LOW)   //not
    {
    // turn LED on:
      PWMfinal = 100;
      Serial.println("100%");
    }
   
delay(1000);
  //if analog pin connected instead
 /*
  val = analogRead(analogPin);  // read the input pin    nano has 0 to 1023
  Serial.println(val);          // debug value
   
  PWMfinal = (val/1023)*100;   //convert to 'percentage' to match the digital version. 

*/
  PWMout = (PWMfinal/100)*255;         //convert to PWM suitable code. 
  Serial.println("PWMout");
  Serial.println(PWMout);

  analogWrite(pwmOutPin, PWMout);   //write the code
}