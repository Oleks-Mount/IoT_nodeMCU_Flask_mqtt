#include <ESP8266WiFi.h>
#include <PubSubClient.h>

int data  = D2;    //pin in nodeMCU
int set = D4;  //pin in nodeMCU
int clockPin = D3; //pin in nodeMCU

byte path[10] = { 0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110,
                  0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};

const char* ssid = "name your Wi-Fi ";
const char* password = "password your Wi-Fi";
const char* mqtt_server = "IP your Linux for install mqtt-server";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  
  Serial.println();
    switch((char)payload[i]){
        case '0':
         digitalWrite(set, LOW);
         show_numbers(path[0],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '1':
         digitalWrite(set, LOW);
         show_numbers(path[1],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '2':
         digitalWrite(set, LOW);
         show_numbers(path[2],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '3':
         digitalWrite(set, LOW);
         show_numbers(path[3],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '4':
         digitalWrite(set, LOW);
         show_numbers(path[4],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '5':
         digitalWrite(set, LOW);
         show_numbers(path[5],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '6':
         digitalWrite(set, LOW);
         show_numbers(path[6],true);
          digitalWrite(set, HIGH);
        break;
        case '7':
         digitalWrite(set, LOW);
         show_numbers(path[7],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '8':
         digitalWrite(set, LOW);
         show_numbers(path[8],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;
        case '9':
         digitalWrite(set, LOW);
         show_numbers(path[9],true);
          digitalWrite(set, HIGH);
          delay(250);
        break;}

}
  }


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
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
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  pinMode(set, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(data, OUTPUT);

}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 /* unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }*/
}

void show_numbers(byte number,  bool point){
  int point1;
  digitalWrite(data, LOW);
    digitalWrite(clockPin, LOW);
    for (int i=0; i<=7; i++) {
    digitalWrite(clockPin, LOW);
      if ( number & (1<<i) ) {
 point1 = HIGH;
 }
 else {
   point1 = LOW;
  }
      if(i==0&&point){ point1 = HIGH; }
   digitalWrite(data, point1);
  digitalWrite(clockPin, HIGH);
      
 }
}
