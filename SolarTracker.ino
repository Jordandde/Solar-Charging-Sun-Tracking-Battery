#include <Servo.h>
#include <math.h>

#define inPin0 0  // Defining analog pin 0 as an input
#define inPin1 1  // Defining analog pin 1 as an input
#define inPin2 2 // Defining analog pin 2 as an input

Servo spinny; // Declaration of servo

///////// Speed and calibration adjustments

float scale = 0.15;
float center = 94.5;
float range = (180-center) * scale;
float min = center - range;
float max = center + range;

/***********************************************/

void setup() {
    spinny.attach(3);
    Serial.begin(1200);
    Serial.println();
}


void loop() {
  
    int diode2 = analogRead(inPin1) * 1.2;  // Diode 2
    int diode1 = analogRead(inPin0);  // Diode 1
    int diode3 = analogRead(inPin2); // Diode 3 (MIDDLE)

    diode2 = log(diode2);
    diode3 = log(diode3);

    if (diode2 < 30) {
      diode2 *= diode2;
    }
    if (diode1 < 30) {
      diode1 *= diode;
    }

    if (diode2 != 0 || diode1 != 0 || diode3 != 0) {
      Serial.println(diode1);
      Serial.println(diode2);
      Serial.println(diode3);
    }

    int diff = diode2 - diode1;

    if (diff > 5) {
      diff = map(diff, -100, 100, min, max);
    }

    else if (diode3 > diode1 && diode3 > diode2) {
      diff = map(diff, min, max, min/2, max/2);  
    }

    else {
      diff = 90;
    }

    spinny.write(diff);

}












// #include <Servo.h>

// #define inPin0 0  // Defining analog pin 0 as an input
// #define inPin1 1  // Defining analog pin 1 as an input

// Servo spinny;     // Declaration of servo

// void setup() {
// 		spinny.attach(3);
// 		Serial.begin(9600);
// 		Serial.println();
// }

// void loop() {
	
// 		int diode1 = analogRead(inPin1);  // Servo 1
// 		int diode0 = analogRead(inPin0);  // Servo 0

// 		if (diode1 != 0 || diode0 != 0) {
// 			Serial.println(diode1);
// 			Serial.println(diode0);
// 		}

// 		if (diode1 > diode0) {
// 			diode1 = map(diode1, 0, 1023, 94.5, 180);
// 			spinny.write(diode1);
// 		}

// 		else if (diode1 < diode0) {
// 			diode0 = map(diode0, 0, 1023, 94.5, 0);
// 			spinny.write(diode0);
// 		}

// 		else {
// 			spinny.write(90);
// 			delay(100);
// 		}
// }
