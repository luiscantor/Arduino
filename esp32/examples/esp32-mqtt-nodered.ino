#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>

const char* ssid = "<SSID>";
const char* password = "<Modem_password>";
const char* mqttServer = "<raspberry_pi_ip>";
const int mqttPort = 1883;
const char* mqttUser = "<mqtt_user>";
const char* mqttPassword = "<mqtt_password>";

int pinDHT = 15;
DHTesp dht;

WiFiClient espClient;
PubSubClient client(espClient);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("...................................");

  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED)
       {  delay(500);
          Serial.print(".") ;
       }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  while (!client.connected())
  {      
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword ))
      Serial.println("connected");
    else
    {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  dht.setup(pinDHT, DHTesp::DHT22);
}

void loop(){
  client.loop();  
  char tempstr[16];
  char humstr[16];
  
  float temp = dht.getTemperature();
  float hum = dht.getHumidity();

  dtostrf(temp,1,2,tempstr);
  dtostrf(hum,1,2,humstr);

  //Serial.println("Temperatura: " + String(temp) + "°C");
  //Serial.println("Humedad: " + String(hum) + "%");

  //Serial.println("---");
  client.publish("sensor/room-1/temperature", tempstr);
  client.publish("sensor/room-1/humidity", humstr);
  //Serial.println(tempstr);
  //Serial.println(humstr);
  //Serial.println("---");
  delay(3000);
}
