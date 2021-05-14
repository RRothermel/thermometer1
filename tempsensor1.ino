#include <dht.h>


#define dht_apin A0 // Analog Pin sensor is connected to
#define segA 2//connecting segment A to PIN2
#define segB 3// connecting segment B to PIN3
#define segC 4// connecting segment C to PIN4
#define segD 5// connecting segment D to PIN5
#define segE 6// connecting segment E to PIN6
#define segF 7// connecting segment F to PIN7
#define segG 8// connecting segment G to PIN8

int COUNT=0;//count integer for 0-9 increment
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  for (int i=2;i<9;i++)
  {
    pinMode(i, OUTPUT);// taking all pins from 2-8 as output
  }
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
  DHT.read11(dht_apin);
  
  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("Celsius Temperature = ");
  Serial.print(DHT.temperature); 
  Serial.print(" C  ");
  int ftemp = (DHT.temperature) * 1.8 + 32;
  Serial.print("Approximate Farenheit Temperature = ");
  Serial.print(ftemp);
  Serial.println(" F ");

  if (ftemp >= 100)
  {
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    Serial.println("Warning: This temperature may be out of the sensor's range and could overheat the sensor.");
  }

  else if (ftemp >= 90 and ftemp <= 99)
  {
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segG, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segC, HIGH);
  }

  else if (ftemp >= 80 and ftemp <= 89)
  {
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segG, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
  }

  else if (ftemp >= 70 and ftemp <= 79)
  {
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
  }

  else if (ftemp >= 60 and ftemp <= 69)
  {
    digitalWrite(segA, HIGH);
    digitalWrite(segG, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
  }

  else if (ftemp >= 50 and ftemp <= 59)
  {
    digitalWrite(segA, HIGH);
    digitalWrite(segG, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
  }

  else if (ftemp >= 40 and ftemp <= 49)
  {
    digitalWrite(segB, HIGH);
    digitalWrite(segG, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segC, HIGH);
  }

  else
  {
    Serial.println("This temperature is most likely below the range of the sensor and could damage the sensor.");
  }
  
  delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.

}// end loop(
