#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <PubSubClient.h>


//Relays for switching appliances
#define Relay1            16  //D0
#define Relay2            5   //D1
#define Relay3            4   //D2
#define Relay4            0   //D3
#define Relay5            14  //D5
#define Relay6            12  //D6
#define Relay7            13  //D7
#define Relay8            15  //D8

#define btn               A0  //A0


// Update these with values suitable for your network.
const char* ssid = "Redmi Note 9 Pro Max";
const char* password = "12344322";
const char* mqtt_server = "broker.emqx.io";
//const char* username = "MQTT_USERNAME";
//const char* pass = "MQTT_PASSWORD";


// Subscribed Topics
#define sub1 "office/relay1"
#define sub2 "office/relay2"
#define sub3 "office/relay3"
#define sub4 "office/relay4"
#define sub5 "office/relay5"
#define sub6 "office/relay6"
#define sub7 "office/relay7"
#define sub8 "office/relay8"


WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE  (50)
char msg[MSG_BUFFER_SIZE];
int value = 0;


// Connecting to WiFi Router
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_BUILTIN, HIGH);
}

void callback(char* topic, byte* payload, unsigned int length) {
  //  Serial.print("Message arrived [");
  //  Serial.print(topic);
  //  Serial.print("] ");

  if (strstr(topic, sub1)) {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1')   {
      digitalWrite(Relay1, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(1, 1);
      Serial.print("Relay1 on");
    } else {
      digitalWrite(Relay1, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(1, 0);
      Serial.print("Relay1 off");
    }
  }
  else if ( strstr(topic, sub2))
  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay2, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(2, 1);
      Serial.print("Relay2 on");
    } else {
      digitalWrite(Relay2, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(2, 0);
      Serial.print("Relay2 off");
    }
  }
  else if ( strstr(topic, sub3))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay3, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(3, 1);
      Serial.print("Relay3 on");
    } else {
      digitalWrite(Relay3, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(3, 0);
      Serial.print("Relay3 off");
    }
  }
  else if ( strstr(topic, sub4))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay4, 0);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(4, 0);
      Serial.print("Relay4 on");
    } else {
      digitalWrite(Relay4, 1);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(4, 1);
      Serial.print("Relay4 off");
    }
  }
  else if ( strstr(topic, sub5))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay5, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(5, 1);
      Serial.print("Relay5 on");
    } else {
      digitalWrite(Relay5, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(5, 0);
      Serial.print("Relay5 off");
    }
  }
  else if ( strstr(topic, sub6))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay6, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(6, 1);
      Serial.print("Relay6 on");
    } else {
      digitalWrite(Relay6, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(6, 0);
      Serial.print("Relay6 off");
    }
  }
  else if ( strstr(topic, sub7))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay7, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(7, 1);
      Serial.print("Relay7 on");
    } else {
      digitalWrite(Relay7, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(7, 0);
      Serial.print("Relay7 off");
    }
  }
  else if ( strstr(topic, sub8))  {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1') {
      digitalWrite(Relay8, 1);   // Turn the LED on (Note that LOW is the voltage level
      EEPROM.write(8, 1);
      Serial.print("Relay8 on");
    } else {
      digitalWrite(Relay8, 0);  // Turn the LED off by making the voltage HIGH
      EEPROM.write(8, 0);
      Serial.print("Relay8 off");
    }
  }
  else {
    Serial.println("unsubscribed topic");
  }
  EEPROM.commit();
}

// Connecting to MQTT broker
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe(sub1);
      client.subscribe(sub2);
      client.subscribe(sub3);
      client.subscribe(sub4);
      client.subscribe(sub5);
      client.subscribe(sub6);
      client.subscribe(sub7);
      client.subscribe(sub8);
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 1 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}

void recall() {
  int flag1 = EEPROM.read(1);
  int flag2 = EEPROM.read(2);
  int flag3 = EEPROM.read(3);
  int flag4 = EEPROM.read(4);
  int flag5 = EEPROM.read(5);
  int flag6 = EEPROM.read(6);
  int flag7 = EEPROM.read(7);
  int flag8 = EEPROM.read(8);

  digitalWrite(Relay1, flag1);
  digitalWrite(Relay2, flag2);
  digitalWrite(Relay3, flag3);
  digitalWrite(Relay4, flag4);
  digitalWrite(Relay5, flag5);
  digitalWrite(Relay6, flag6);
  digitalWrite(Relay7, flag7);
  digitalWrite(Relay8, flag8);
}

void manual(int state) {
  digitalWrite(Relay1, state);
  digitalWrite(Relay2, state);
  digitalWrite(Relay3, state);
  digitalWrite(Relay4, 1 - state);
  digitalWrite(Relay5, state);
  digitalWrite(Relay6, state);
  digitalWrite(Relay7, state);
  digitalWrite(Relay8, state);
}

void setup() {
  EEPROM.begin(512);
  Serial.begin(115200);

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);

  pinMode(btn, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  if (analogRead(btn) > 800) {
    manual(1);
  } else{
    recall();
  }
  
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected())  {
    reconnect();
  }
  client.loop();
}
