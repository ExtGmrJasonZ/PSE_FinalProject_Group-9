#include <SoftwareSerial.h>
#include <dht.h>
#define DHT_PIN 11
#define DHTTYPE DHT11
SoftwareSerial mySerial(2, 3);

dht DHT;


const int led = 7;
String statusLed = "OFF";
int sensorPin = A0;
int sensorValue;
const int relay = 13;
const int soundPin = A0; //sound sensor attach to A0 
int threshold = 70; //Set minimum threshold for LED lit 


String data = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  mySerial.begin (115200);
  DHT.read11(DHT_PIN);
  pinMode(led, OUTPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay,HIGH);

}

void loop() {
  int value =  analogRead(soundPin);
    Serial.println(value);//print the value 
   if(value > threshold) //if the value is greater than 600 
  { 
    digitalWrite(led,HIGH);//turn on the led 
    delay(200);//delay 200ms 
  } 
  else 
  { 
    digitalWrite(led,LOW);//turn off the led 
  } 
  delay(50); 
  int m = analogRead(sensorPin);
  m = map(m, 1023, 165, 0, 100);
  int h = DHT.humidity;
  int t = DHT.temperature;
  // put your main code here, to run repeatedly:
  while (mySerial.available() > 0) {
    char c = mySerial.read();
    data += c;
  }

  if (data.length() > 0) {
    Serial.println("Data Inputted :" + data);

    if (data == "FAN ON") {
      digitalWrite(relay,LOW);
      Serial.println("FAN ON");
      mySerial.print("FAN is ON");
    }
    else if(data == "FAN OFF") {
      digitalWrite(relay,HIGH);
      Serial.println("FAN OFF");
      mySerial.print("FAN is OFF");
    }
    else if(data == "TEMPERATURE") {
      mySerial.print ("TEMPERATURE: " + String(t));
    }
    else if(data == "HUMIDITY") {
      mySerial.print ("HUMIDITY: " + String(h) + "%");
    }
     else if(data == "MOISTURE") {
      mySerial.print ("MOISTURE: " + String(m) + "%");
    }
    else if(data == "STATUS") {
      mySerial.print(String("LED Condition: " + statusLed + '#'
                            + "TEMPERATURE: " + t + '#'
                            + "HUMIDITY: " + h + '#'
                            + "MOISTURE: " + m));
    }
    
    data = "";
  }

}
