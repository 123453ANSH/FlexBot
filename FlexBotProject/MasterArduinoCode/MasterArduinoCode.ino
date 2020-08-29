#include <Servo.h> // package to use servo function



const int analogInPin = A0; //A0 // EMG Data goes into here
const int L = 3; // first data output pin to motor controller
const int BP = A1; // first data input from button
const int BP2 = A2; // second data input form button
Servo LeftMotor; // giving variable access to all servo methods
Servo rightMotor;

int nval = 0;
int analogreadings = 0;

void setup() {
  Serial.begin(9600); // so can read values on serial motor to see if working
  pinMode(BP, INPUT_PULLUP); // input_pullup for data input from buttons allows the arduino to 
  //recognize if current going to the ports has increased
  pinMode(BP2, INPUT_PULLUP);
  LeftMotor.attach(11); // attaching pins which send data to motor controller when prompted
  rightMotor.attach(6);
}



void loop() {
  LeftMotor.write(1500);// 1500 value corresponds to motor not moving
  rightMotor.write(1500);
 digitalWrite(3,LOW);// always write low at beginning of loop to indicate the ports are not sending signal to motor controller
 digitalWrite(5,LOW);
  int R = digitalRead(BP);
  int R2 = digitalRead(BP2);
  int nval = analogRead(analogInPin);// read analog values
  Serial.println(nval);// print value on serial monitor
  int Back = nval;
  int Forward = nval;
  
  if (R2 == LOW and R == LOW) { // if both buttons are being pressed 
    Serial.println(333);  
    if (nval <230 or nval>380) { // if the EMG readings are out of a certain value 
      Serial.println(2); 
      LeftMotor.write(1000); // write both motors to turn one direction
      rightMotor.write(1000);
      delay(500);
     
  }
  }
  else if (R == LOW) { // if one button is being pressed
    Serial.println(111);
      if (nval <230 or nval>380) {
      Serial.println(2);
      LeftMotor.write(2000); // motors turn in opposite directions, indicating a turn
      rightMotor.write(1000);
      delay(500);
     
  }
  }
  else if (R2 == LOW) { // if one of the buttons is being pressed
    Serial.println(222);
    if (nval <230 or nval>380) { 
      Serial.println(2);
     LeftMotor.write(1000); // the motors turn in opposite directions, turning
      rightMotor.write(2000);
      delay(500);
     
  }
    }
    else{ // if none of the buttons are being pressed
       if (nval <230 or nval>380) {
      Serial.println(2);
     //digitalWrite(3, HIGH);
      LeftMotor.write(2000); // both motors turn in the same direction
      rightMotor.write(2000);
      delay(500);
      //digitalWrite(5, HIGH);
     
  }
    }
  }
