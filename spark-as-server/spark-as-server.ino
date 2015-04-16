
#include "application.h"

// allow use of itoa() in this scope  // what the heck is this and is it needed????
extern char* itoa(int a, char* buffer, unsigned char radix);

#define DEBUG 1
#define PORT 48879
#define MAX_DATA_BYTES 128






TCPServer server = TCPServer(23);
TCPClient client;

void setup() {
  
  pinMode(D7, OUTPUT);     // output means information out of the spark device


  server.begin();
  netapp_ipconfig(&ip_config);

  #if DEBUG
  Serial.begin(115200);
  #endif

  IPAddress ip = WiFi.localIP();
  static char ipAddress[24] = "";
  char octet[5];

  itoa(ip[0], octet, 10); strcat(ipAddress, octet); strcat(ipAddress, ".");
  itoa(ip[1], octet, 10); strcat(ipAddress, octet); strcat(ipAddress, ".");
  itoa(ip[2], octet, 10); strcat(ipAddress, octet); strcat(ipAddress, ".");
  itoa(ip[3], octet, 10); strcat(ipAddress, octet); strcat(ipAddress, ":");
  itoa(PORT, octet, 10);  strcat(ipAddress, octet);

  Spark.variable("endpoint", ipAddress, STRING);
  
  
     SPARK_WLAN_Loop();   // so cloud stuff can still happen
}

  // Make sure your Serial Terminal app is closed before powering your Core
  // Serial.begin(9600);
  // Now open your Serial Terminal, and hit any key to continue!
  // while(!Serial.available())  SPARK_WLAN_Loop();

  //Serial.println(WiFi.localIP());
  //Serial.println(WiFi.subnetMask());
  //Serial.println(WiFi.gatewayIP());
  //Serial.println(WiFi.SSID());
  
   //SPARK_WLAN_Loop();   // so cloud stuff can still happen
//}

void loop()
{
  if (client.connected()) {
    
       digitalWrite(D7, HIGH);  // send 1 high,,, 0 low 
    
    
    
    // echo all available bytes back to the client
    while (client.available()) {
      server.write(client.read());
    }
  } else {
    // if no client is yet connected, check for a new connection
    client = server.available();
  }
}
