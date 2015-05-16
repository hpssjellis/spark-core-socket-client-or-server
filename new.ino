TCPClient client;



char server[] = "my-node-url.com";





int connectToMyServer(String nothing) {

  digitalWrite(D7, HIGH);
  if (client.connect(server, 80)) {
      client.write("GET / HTTP/1.1\r\n");
      client.write("Host: my-node-url.com\r\n");
      client.write("\r\n");
    digitalWrite(D7, LOW);
    return 1; // successfully connected
  } else {
    digitalWrite(D7, LOW);
    return -1; // failed to connect
  }

}

void setup() {

      pinMode(D7, OUTPUT);
      
      Spark.function("connect", connectToMyServer);
      digitalWrite(D7, HIGH);
      delay(25000);
      digitalWrite(D7, LOW);


}

void loop() {
  if (client.connected()) {
    if (client.available()) {
    // char pin = client.read() - '0' + D0;
      //char level = client.read();
      if (client.read()) {
        digitalWrite(D7, HIGH);
      } else {
        digitalWrite(D7, LOW);
      }
    }
  }
}
