#include <ESP8266WiFi.h>
 
const char* ssid = "SSid";
const char* password = "Password";
 
int licht_tuer = 0; // GPIO0
int licht_raum = 2; // GPIO2

WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
  
 
  pinMode(licht_tuer, OUTPUT);
  digitalWrite(licht_tuer, LOW);
  pinMode(licht_raum, OUTPUT);
  digitalWrite(licht_raum, LOW);
  
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
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
    
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String request = client.readStringUntil('#');
  Serial.println(request);
  client.flush();
  
  // Match the request
  
  if(request.indexOf("both_on_") != -1){
    digitalWrite(licht_raum, HIGH);
    digitalWrite(licht_tuer, HIGH);
  }
  if(request.indexOf("both_off") != -1){
    digitalWrite(licht_tuer, LOW);
    digitalWrite(licht_raum, LOW);
  }
  if(request.indexOf("raum_on_") != -1){
    digitalWrite(licht_raum, HIGH);
  }
  if(request.indexOf("raum_off") != -1){
    digitalWrite(licht_raum, LOW);
  }
  if(request.indexOf("tuer_on_") != -1){
    digitalWrite(licht_tuer, HIGH);
  }
  if(request.indexOf("tuer_off") != -1){
    digitalWrite(licht_tuer, LOW);
  }
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
