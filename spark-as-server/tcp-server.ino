

TCPServer server = TCPServer(23);
TCPClient client;

void setup()
{
  // start listening for clients
  server.begin();

  // Make sure your Serial Terminal app is closed before powering your Core
  Serial.begin(9600);
  // Now open your Serial Terminal, and hit any key to continue!
  while(!Serial.available()) SPARK_WLAN_Loop();

  Serial.println(WiFi.localIP());
  Serial.println(WiFi.subnetMask());
  Serial.println(WiFi.gatewayIP());
  Serial.println(WiFi.SSID());
}

void loop()
{
  if (client.connected()) {
    // echo all available bytes back to the client
    while (client.available()) {
      server.write(client.read());
    }
  } else {
    // if no client is yet connected, check for a new connection
    client = server.available();
  }
}
