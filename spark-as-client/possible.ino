// SYNTAX
//form spark community https://community.spark.io/t/tcp-connection-to-private-server-spark-core-as-tcp-client/4823/9


//TCPClient client;
// EXAMPLE USAGE

TCPClient client;
byte server[] = { 192, 168, 164, 3 }; // Google
void setup()
{
Serial.begin(9600);
delay(1000);
Serial.println("connecting...");

if (client.connect(server, 2088))
{
Serial.println("connected");
client.println("GET /search?q=unicorn HTTP/1.0");
client.println("Host: www.google.com");
client.println("Content-Length: 0");
client.println();
}
else
{
Serial.println("connection failed");
}
}

void loop()
{
if (client.available())
{
Serial.println("connected");
char c = client.read();
Serial.print(c);
}

if (!client.connected())
{
Serial.println();
Serial.println("disconnecting.");
client.stop();
for(;;)
{
Serial.println("connection failed");
}
}
}
