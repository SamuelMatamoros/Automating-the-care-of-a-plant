#include <Arduino.h>

#define DTPin 21
#define CLKPin 19
#define button 22

int OldStateCLK;
int NewStateCLK;
int counter = 0;

int current_icon;
int previous_icon;
int next_icon;
int iconsArray_LEN = 5;

void setup() {

    Serial.begin(9600);

    pinMode(DTPin, INPUT);
    pinMode(CLKPin, INPUT);
    pinMode(button, INPUT);

    OldStateCLK = digitalRead(CLKPin);

}

void loop() {

    NewStateCLK = digitalRead(CLKPin);
    
    if (NewStateCLK != OldStateCLK) {
        
        // Serial.print("New CLK: ");
        // Serial.print(NewStateCLK);
        // Serial.print("  old CLK: ");
        // Serial.print(OldStateCLK);
        // Serial.print("  DT:");
        // Serial.print(digitalRead(DTPin));

        if (digitalRead(DTPin) == NewStateCLK) {
            counter ++;
        }
        else {
            counter --;
        }

 		if (counter < 0) {counter = iconsArray_LEN - 1;}
		if (counter > 4) {counter = 0;}
       
        current_icon = counter;

        previous_icon = current_icon - 1;
        if (previous_icon < 0) {
	    previous_icon = iconsArray_LEN - 1;
        }

	    next_icon = current_icon + 1;
	    if (next_icon >= iconsArray_LEN) {
    	next_icon = 0;
	    }

        Serial.print("Previous: ");
        Serial.print(previous_icon);
        Serial.print("  Current:    ");
        Serial.print(current_icon);
        Serial.print("  Next:   ");
        Serial.println(next_icon);

    }

    OldStateCLK = NewStateCLK;

    //Solucionar problema boton
}