#include<Servo.h>
#define inPin0 0
#define inPin1 1
#define Bot 2
#define Top 3
Servo spinny;
enum State {START, BOTH_ON, BOT_OFF, BOTH_OFF};
int pin = 3;
void setup() {
 // put your setup code here, to run once:
 spinny.attach(3);
 pinMode(Bot, INPUT);
 pinMode(Top, INPUT);
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  int pinRead1 = analogRead(inPin1);
  int pinRead0 = analogRead(inPin0);
  float pVolt0 = pinRead0 / 10;
  float pVolt1 = pinRead1 / 10;// 1024.0;// + 5.0;
  int sensorBot = digitalRead(Bot);
  int sensorTop = digitalRead(Top);
  enum State s = start;
  switch(s){
    case START:
 
      if(sensorBot && sensorTop){
        s = BOTH_ON;
        }
       else if(sensorBot && !sensorTop){
          spinny.write(89);
          
       }
       else{
        spinny.write(91);
       }
      break;
     case BOTH_ON:
      if(!sensorBot){
        s = BOT_OFF;
      }
      break;
      case BOT_OFF:
        if(sensorBot){
          s = BOTH_ON;
        }
        if(!sensorBot){
          spinny.write(89);
        }
        if(!sensorTop){
          s = BOTH_OFF;
        }
        break;
       case BOTH_OFF:
        s = start;
        break;
  }
  //Serial.print(pVolt0);
  //Serial.print(" ");
  //Serial.print(pVolt1);
  //Serial.println();

  delay(10000);
  // put your main code here, to run repeatedly:

}
