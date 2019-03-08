#include<Servo.h>
#define inPin0 0
#define inPin1 1
Servo spinny;
enum State {START, BOTH_ON, BOT_OFF, BOTH_OFF};
int pin = 3;
void setup() {
 // put your setup code here, to run once:
 spinny.attach(3);
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  int pinRead1 = analogRead(inPin1);
  int pinRead0 = analogRead(inPin0);
  float pVolt0 = pinRead0;//bottom
  float pVolt1 = pinRead1;// top
  enum State s = START;
  switch(s){
    case START:
    Serial.println(pVolt0);
    Serial.println(pVolt1);
 
      if(pVolt0 > 10 && pVolt1 > 10){
        s = BOTH_ON;
        }
       else if(pVolt0 > 10 && pVolt1 < 10){
          spinny.write(100);
          
       }
       else{
        spinny.write(80);
       }
      break;
     case BOTH_ON:
      if(pVolt0 < 10){
        s = BOT_OFF;
      }
      break;
      case BOT_OFF:
        if(pVolt0 > 10){
          s = BOTH_ON;
        }
        if(pVolt0 < 10){
          spinny.write(100);
        }
        if(pVolt1 < 10){
          s = BOTH_OFF;
        }
        break;
       case BOTH_OFF:
        s = START;
        break;
  }
  //Serial.print(pVolt0);
  //Serial.print(" ");
  //Serial.print(pVolt1);
  //Serial.println();

  delay(500);
  // put your main code here, to run repeatedly:

}
