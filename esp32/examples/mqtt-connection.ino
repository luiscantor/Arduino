#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "INFINITUM043F";
const char* password = "VdJ5NtfG4Q";
const char* mqttServer = "192.168.1.73";
const int mqttPort = 1883;
const char* mqttUser = "mqtt_user";
const char* mqttPassword = "mlatrleb#";

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
}

void loop()
  {  client.loop();
     char str[16];
     sprintf(str, "%u", random(15,40));

     client.publish("esp32/test", str);
     Serial.println(str);
     delay(3000);
 }
