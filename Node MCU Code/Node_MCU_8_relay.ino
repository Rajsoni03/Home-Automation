#include <ESP8266WiFi.h>
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


// Update these with values suitable for your network.
const char* ssid = "Redmi Note 9 Pro Max";
const char* password = "--------";
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


void RunRelay(byte* payload, int Relay, unsigned int length) {
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  if ((char)payload[0] == '1')   {
    digitalWrite(Relay, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  } else {
    digitalWrite(Relay, LOW);  // Turn the LED off by making the voltage HIGH
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  if (strstr(topic, sub1)) {
    RunRelay(payload, Relay1, length);
  }
  else if ( strstr(topic, sub2)) {
    RunRelay(payload, Relay2, length);
  }
  else if ( strstr(topic, sub3)) {
    RunRelay(payload, Relay3, length);
  }
  else if ( strstr(topic, sub4)) {
    RunRelay(payload, Relay4, length);
  }
  else if ( strstr(topic, sub5)) {
    RunRelay(payload, Relay5, length);
  }
  else if ( strstr(topic, sub6)) {
    RunRelay(payload, Relay6, length);
  }
  else if ( strstr(topic, sub7)) {
    RunRelay(payload, Relay7, length);
  }
  else if ( strstr(topic, sub8)) {
    RunRelay(payload, Relay8, length);
  }
  else  {
    Serial.println("unsubscribed topic");
  }


  /*
    if (strstr(topic, sub1)) {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    if ((char)payload[0] == '1')   {
      digitalWrite(Relay1, HIGH);   // Turn the LED on (Note that LOW is the voltage level
    } else {
      digitalWrite(Relay1, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }

    else if ( strstr(topic, sub2))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay2, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay2, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub3))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay3, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay3, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub4))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay4, LOW);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay4, HIGH);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub5))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay5, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay5, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub6))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay6, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay6, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub7))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay7, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay7, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }
    else if ( strstr(topic, sub8))
    {
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
    }
    Serial.println();
    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '1') {
      digitalWrite(Relay8, HIGH);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(Relay8, LOW);  // Turn the LED off by making the voltage HIGH
    }
    }

    else
    {
    Serial.println("unsubscribed topic");
    }
  */
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
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
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
