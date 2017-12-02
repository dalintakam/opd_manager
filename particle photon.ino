// This #include statement was automatically added by the Particle IDE.
#include <clickButton.h>

// This #include statement was automatically added by the Particle IDE.
#include <MQTT.h>

byte server[] ={174,138,116,138};
const int buttonPin1 = 4;
ClickButton button1(buttonPin1, LOW, CLICKBTN_PULLUP);

// Button results 
int function = 0;
String tok="current token number is: ";
int token=0;
void callback(char* topic, byte* payload, unsigned int length);
MQTT client(server, 1883, callback);

void callback(char* topic, byte* payload, unsigned int length) 
{
char p[length + 1];
memcpy(p, payload, length);
p[length] = NULL;


//delay(1000);
}


void setup()
{
  Serial.begin(9600);
  pinMode(D4, INPUT_PULLUP);
  pinMode(D2, OUTPUT);
  digitalWrite(D2,LOW);
  // Setup button timers (all in milliseconds / ms)
  // (These are default if not set, but changeable for convenience)
  button1.debounceTime   = 20;   // Debounce timer in ms
  button1.multiclickTime = 250;  // Time limit for multi clicks
  button1.longClickTime  = 1000; // time until "held-down clicks" register
}


void loop()
{client.connect(System.deviceID());
  // Update button state
  button1.Update();

  // Save click codes in LEDfunction, as click codes are reset at next Update()
  if(button1.clicks != 0) function = button1.clicks;
  
  if(function == 1) {
      Serial.println("SINGLE click");
      token++;
       Particle.publish("token no is",String (token));
        client.publish("sensor1", String(token));
       digitalWrite(D2,HIGH);
       delay(1000);
       digitalWrite(D2,LOW);
}
  if(function == 2) Serial.println("DOUBLE click");

  if(function == 3) Serial.println("TRIPLE click");

  if(function == -1) Serial.println("SINGLE LONG click");

  if(function == -2) Serial.println("DOUBLE LONG click");

  if(function == -3) Serial.println("TRIPLE LONG click");
  
  function = 0;
  delay(5);
}

