#include <CapacitiveSensor.h>

#define rl1 10
#define rl2 11
#define rl3 12

#define led1 A0
#define led2 A1
#define led3 A2

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

/*
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
*/
CapacitiveSensor   cs_5_6 = CapacitiveSensor(5,6);
CapacitiveSensor   cs_5_7 = CapacitiveSensor(5,7);
bool stt1 = true;
bool stt2 = true;
long last = 0;

void setup()                    
{
   cs_5_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   cs_5_7.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
   pinMode(rl1, OUTPUT);
   pinMode(rl2, OUTPUT);
   pinMode(rl3, OUTPUT);
   pinMode(A0, OUTPUT);
   pinMode(A1, OUTPUT);
   pinMode(A2, OUTPUT);
}

void loop()                    
{
    long start = millis();

    long total1 =  cs_5_6.capacitiveSensor(30);
    long total2 =  cs_5_7.capacitiveSensor(30);

    long t = millis() - start;
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                 // print sensor output 1
    Serial.print("\t");
    Serial.println(total2);                  // print sensor output 2
    //Serial.print("\t");
    //Serial.println(total3);                // print sensor output 3
    delay(100);
    long delta1 = total1 - last;// arbitrary delay to limit data to serial port 
    long delta2 = total2 - last;
    if (delta1 > 5000 && delta1 < 80000) {
      digitalWrite(rl1, stt1);
      digitalWrite(led1, stt1);
      stt1 = !stt1;
    }
    if (delta2 > 7000 && delta2 < 80000) {
      digitalWrite(rl2, stt2);
      digitalWrite(led2, stt2);
      stt2 = !stt2;
    }
    
    last = total1;
}
