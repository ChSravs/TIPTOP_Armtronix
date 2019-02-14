 //needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager


String rid = "";
String uid = "";
String pwd = "";
String cid = "";
String dname = "";

WiFiManager wifiManager;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  WiFiManagerParameter custom_rid("rid", "Resource ID", rid.c_str() , 40);
  WiFiManagerParameter custom_userid("uid", "Username", uid.c_str() , 40);
  WiFiManagerParameter custom_pwd("pwd", "Password", pwd.c_str() , 40);
  WiFiManagerParameter custom_cid("cid", "Company ID", cid.c_str() , 40);
  WiFiManagerParameter custom_dname("dname", "Device Friendly Name", dname.c_str() , 40);
  //WiFiManager
  //Local intialization. Once its business is done, there is no need to keep it around

  //reset settings - for testing
  //wifiManager.resetSettings();
  WiFiManagerParameter custom_text2("<p>User details</p>");
  wifiManager.addParameter(&custom_text2);
  wifiManager.addParameter(&custom_userid);
  wifiManager.addParameter(&custom_pwd);
  wifiManager.addParameter(&custom_cid);

  WiFiManagerParameter custom_text1("<p>Device details</p>");
  wifiManager.addParameter(&custom_text1);
  wifiManager.addParameter(&custom_rid);
  wifiManager.addParameter(&custom_dname);
  //sets timeout until configuration portal gets turned off
  //useful to make it all retry or go to sleep
  //in seconds
  //wifiManager.setTimeout(180);
  
  //fetches ssid and pass and tries to connect
  //if it does not connect it starts an access point with the specified name
  //here  "AutoConnectAP"
  //and goes into a blocking loop awaiting configuration
  if(!wifiManager.autoConnect("TipTopAP")) {
    Serial.println("failed to connect and hit timeout");
    delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.reset();
    delay(5000);
  } 

  Serial.println(WiFi.SSID());
  Serial.println(WiFi.psk());
}


void loop() {
  
}
