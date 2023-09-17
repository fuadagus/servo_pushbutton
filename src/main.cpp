#include <Arduino.h>

#include <Servo.h>
const int buttonPin = 2;
int currentState = LOW;
int lastState = LOW;
int count = 0;
int targetPosition = 90;

Servo servo;
void setup() {
  servo.attach(11);
  pinMode(buttonPin, INPUT);
  Serial.begin(115200);
}
//
void loop() {
  currentState = digitalRead(buttonPin);
  digitalWrite(LED_BUILTIN, digitalRead(buttonPin));

  if (digitalRead(buttonPin)==HIGH){
    lastState = HIGH;
      delay(200);
     if (digitalRead(buttonPin)==LOW){
        lastState = LOW;
        
     }
  }
  
  if (currentState == HIGH && lastState == LOW){
    if (count < 4){
      count ++;
    } else {
      count = 0;
    }
    
    }
     switch (count) {
      case 1:
        targetPosition = 30;
        break;
      case 2:
        targetPosition = 60;
        break;
      case 3:
        targetPosition = 90;
        break;
      case 4:
        targetPosition = 180;
        break;
      default:
        targetPosition = 90;
        break;
    }
    Serial.println(count);
    servo.write(targetPosition);
}