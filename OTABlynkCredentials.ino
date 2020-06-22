#include "OTABlynkCredentials.h"

#ifdef ESP8266
#include <BlynkSimpleEsp8266.h>
#elif defined(ESP32)
#include <BlynkSimpleEsp32.h>
#else
#error "Board not found"
#endif
#include<DHT.h>
credentials Credentials;



//Variables
char auth_token[33];
bool connected_to_internet = 0;
const int Erasing_button = 0;


//Provide credentials for your ESP server
char* esp_ssid = "techiesms";
char* esp_pass = "";

#define Relay1            D0
#define Relay2            D1
#define Relay3            D2
#define Relay4            D3
#define Relay5            D4
#define Relay6            D5

int forwordmotor;
int reversemotor;
int solonoid1;
int solonoid2;
int solonoid3;
int solonoid4;

void setup()

{

  Serial.begin(115200);
  pinMode(Erasing_button, INPUT);


  for (uint8_t t = 4; t > 0; t--) {
    Serial.println(t);
    delay(1000);
  }

  // Press and hold the button to erase all the credentials
  if (digitalRead(Erasing_button) == LOW)
  {
    Credentials.Erase_eeprom();

  }

  String auth_string = Credentials.EEPROM_Config();
  auth_string.toCharArray(auth_token, 33);

  if (Credentials.credentials_get())
  {

    Blynk.config(auth_token);
    connected_to_internet = 1;

  }
  else
  {
    Credentials.setupAP(esp_ssid, esp_pass);
    connected_to_internet = 0;
  }


  if (connected_to_internet)
  {


  dht.begin();
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
 


void sendSensor()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, forwordmotor);
  Blynk.virtualWrite(V1, reversemotor);
  Blynk.virtualWrite(V2, solonoid1);
  Blynk.virtualWrite(V3, solonoid2);
  Blynk.virtualWrite(V4, solonoid3);
  Blynk.virtualWrite(V5, solonoid4);
}
  

void loop()
{
  Credentials.server_loops();

  if (connected_to_internet)
  {
// Now we can publish stuff!
  // Address 00
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);

 
// Address 01
  digitalWrite(D0, LOW);
  digitalWrite(D0, HIGH);
  forwordmotor = analogRead(analogpin);
  Serial.print("forwordmotor - "); Serial.println(forwordmotor);
  if (D0=1)
  {
    forwordmotor= 1;
    digitalWrite(forwordmotor, HIGH);
  }
  else
  {
    forwordmotor = 0;
    digitalWrite(forwordmotor, LOW); 
  }
  //ADDRESS 02
 digitalWrite(D1, LOW);
  digitalWrite(D1, HIGH);
  reversemotor = analogRead(analogpin);
  Serial.print("reversemotor - "); Serial.println(reversemotor);
  if (D1=1)
  {
    reversemotor= 1;
    digitalWrite(reversemotor, HIGH);
  }
  else
  {
    reversemotor = 0;
    digitalWrite(reversemotor, LOW); 
  }
   //ADDRESS 03
 digitalWrite(D2, LOW);
  digitalWrite(D2, HIGH);
  solonoid1 = analogRead(analogpin);
  Serial.print("solonoid1 - "); Serial.println(solonoid1);
  if (D2=1)
  {
    solonoid1= 1;
    digitalWrite(solonoid1, HIGH);
  }
  else
  {
    solonoid1 = 0;
    digitalWrite(solonoid1, LOW); 
  }

 //ADDRESS 04
 digitalWrite(D3, LOW);
  digitalWrite(D3, HIGH);
  solonoid2 = analogRead(analogpin);
  Serial.print("solonoid2 - "); Serial.println(solonoid2);
  if (D3=1)
  {
    solonoid2= 1;
    digitalWrite(solonoid2, HIGH);
  }
  else
  {
    solonoid2 = 0;
    digitalWrite(solonoid2, LOW); 
  }

 //ADDRESS 05
 digitalWrite(D4, LOW);
  digitalWrite(D4, HIGH);
  solonoid3 = analogRead(analogpin);
  Serial.print("solonoid3 - "); Serial.println(solonoid3);
  if (D4=1)
  {
    solonoid3= 1;
    digitalWrite(solonoid3, HIGH);
  }
  else
  {
    solonoid3 = 0;
    digitalWrite(solonoid3, LOW); 
  }
  
   //ADDRESS 06
 digitalWrite(D5, LOW);
  digitalWrite(D5, HIGH);
  solonoid4 = analogRead(analogpin);
  Serial.print("solonoid4 - "); Serial.println(solonoid4);
  if (D5=1)
  {
    solonoid4= 1;
    digitalWrite(solonoid4, HIGH);
  }
  else
  {
    solonoid4 = 0;
    digitalWrite(solonoid4, LOW); 
  }
    Blynk.run();
	timer.run();
  }
}
