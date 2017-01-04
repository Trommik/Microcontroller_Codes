#include <ESP8266WiFi.h>

//gets time over wifi and displays it on 5 7seg displays which are controlled by 5 74HC595 shift registers.

const char* ssid = "ssid";
const char* password = "password";

byte minutes, seconds, hours;

byte Zahlen[10] = {119,65,110,109,89,61,63,97,127,125};


//Pin connected to ST_CP of 74HC595
int latchPin = 16;
//Pin connected to SH_CP of 74HC595
int clockPin = 14;
////Pin connected to DS of 74HC595
int dataPin = 12;

void setup() {
  Serial.begin(115200); 
  delay(10);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.println(WiFi.localIP()); 

  // Set pins as Output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  String theDate = getTime();

  hours = theDate.substring(17,19).toInt();
  hours == hours + 1; // UTC + 1 for German Time
  minutes = theDate.substring(20,22).toInt();
  seconds = theDate.substring(23,25).toInt();

  Serial.println(theDate);


  // take the latch pin low so we can update the LEDs
  digitalWrite(latchPin, LOW);

  // shift out the bits
  shiftOut(dataPin, clockPin, MSBFIRST, Zahlen[minutes-((minutes/10)*10)]);  
  shiftOut(dataPin, clockPin, MSBFIRST, Zahlen[minutes/10]);
  shiftOut(dataPin, clockPin, MSBFIRST, 8); // -
  shiftOut(dataPin, clockPin, MSBFIRST, Zahlen[hours-((hours/10)*10)]); 
  if(hours > 9){
    shiftOut(dataPin, clockPin, MSBFIRST, Zahlen[hours/10]);
  }else{
    shiftOut(dataPin, clockPin, MSBFIRST, 0); // nothing
  }

  // take the latch pin high so the LEDs will light up
  digitalWrite(latchPin, HIGH);

  
  // pause before next value
  delay(10000); // updates every minute
}
  
String getTime() {
  WiFiClient client;
  while (!!!client.connect("google.de", 80)) {
    Serial.println("connection failed, retrying...");
  }

  client.print("HEAD / HTTP/1.1\r\n\r\n");
 
  while(!!!client.available()) {
     yield();
  }

  while(client.available()){
    if (client.read() == '\n') {    
      if (client.read() == 'D') {    
        if (client.read() == 'a') {    
          if (client.read() == 't') {    
            if (client.read() == 'e') {    
              if (client.read() == ':') {    
                client.read();
                String theDate = client.readStringUntil('\r');
                client.stop();
                return theDate;
              }
            }
          }
        }
      }
    }
  }
}

