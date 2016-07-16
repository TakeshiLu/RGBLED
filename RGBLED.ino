#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */


CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10 megohm resistor between pins 2 & 3, pin 3 is sensor pin, add wire, foil
CapacitiveSensor   cs_4_5 = CapacitiveSensor(4,5);        // 10 megohm resistor between pins 4 & 5, pin 5 is sensor pin, add wire, foil
CapacitiveSensor   cs_6_7 = CapacitiveSensor(6,7);        // 10 megohm resistor between pins 6 & 7, pin 7 is sensor pin, add wire, foil

//RGB brightness
int p9=1;
int p10=1;
int p11=1;

void setup()                    
{

   cs_4_5.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);     
   cs_6_7.set_CS_AutocaL_Millis(0xFFFFFFFF);    

   //RGB LED
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);
   
   Serial.begin(9600);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_2_3.capacitiveSensor(30);
    long total2 =  cs_4_5.capacitiveSensor(30);
    long total3 =  cs_6_7.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print(", ");                    // tab character for debug window spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print(", ");
    Serial.print(total2);                  // print sensor output 2
    Serial.print(", ");
    Serial.println(total3);                // print sensor output 3

    if(total1>55){
      if(p9<20)
        p9++;
    }else{
      if(p9>0)
        p9--;
    }
    
    if(total2>55){
       if(p10<25)
        p10++;
    }else{
      if(p10>0)
        p10--;
    } 
    
    if(total3>55){
       if(p11<25)
        p11++;
    }else{
      if(p11>0)
        p11--;
    }
    
    analogWrite(9,p9);
    analogWrite(10,p10);
    analogWrite(11,p11);
    delay(10);                             // arbitrary delay to limit data to serial port 
}
