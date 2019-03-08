#include <Servo.h>

#define inPin0 0  // Defining analog pin 0 as an input
#define inPin1 1  // Defining analog pin 1 as an input

Servo spinny;     // Declaration of servo

void setup() {
		spinny.attach(3);
		Serial.begin(9600);
		Serial.println();
}

void loop() {
	
		int diode1 = analogRead(inPin1);  // Servo 1
		int diode0 = analogRead(inPin0);  // Servo 0

		if (diode1 != 0 || diode0 != 0) {
			Serial.println(diode1);
			Serial.println(diode0);
		}

		if (diode1 > diode0) {
			diode1 = map(diode1, 0, 1023, 94.5, 180);
			spinny.write(diode1);
		}

		else if (diode1 < diode0) {
			diode0 = map(diode0, 0, 1023, 94.5, 0);
			spinny.write(diode0);
		}

		else {
			spinny.write(90);
			delay(100);
		}
}
