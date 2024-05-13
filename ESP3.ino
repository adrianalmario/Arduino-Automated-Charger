#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "2MLTINC";  //wifi
const char* password = "ThankYouForAsking!"; //wifipassword
const char* serverAddress = "192.168.5.234"; // wifiserver  Ipv4
const int serverPort = 443; // serverlist

#define relay D2 //ESP8266 output pin

WiFiClient client;

void setup() {

  pinMode(relay,OUTPUT);
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // URL of the PHP script on your XAMPP server that interacts with the database
    String url = "http://" + String(serverAddress) + "/getData1.php";
    
    http.begin(client, url);
    
    int httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        String status = http.getString();
        
        if(status == "1"){

          Serial.println("Status: " + status + " ON");
          digitalWrite(relay,HIGH);
        }

        else{
          Serial.println("Status: " + status + " OFF");
          digitalWrite(relay,LOW);
        }
        }





        
      
    } else {
      Serial.println("Error in HTTP request");
    }
    
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
  
  delay(5000); // Wait for 5 seconds before making the next request
}
