#include <AFMotor.h>
AF_DCMotor right_motor(1, MOTOR12_8KHZ);
AF_DCMotor left_motor(2, MOTOR12_8KHZ);
AF_DCMotor left_motor1(3, MOTOR12_8KHZ);

String readString;

void setup() {
  Serial.begin(9600);
  right_motor.setSpeed(120);
  left_motor.setSpeed(120);
  left_motor1.setSpeed(250);
}

void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){
      right_motor.run (FORWARD);
      left_motor.run (FORWARD);
      left_motor1.run (RELEASE);
      delay(500);
    }
    if (readString =="BACKWARD"){
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);
      left_motor1.run (RELEASE);
      delay(500);
    }
    if (readString =="LEFT"){
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);
      left_motor1.run (RELEASE);
      delay(500);
    }
    if (readString =="RIGHT"){
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      left_motor1.run (RELEASE);
      delay(500);
    }
    if (readString =="STOP"){
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      left_motor1.run (FORWARD);
      delay(500);
    }

    readString="";
  }
}
