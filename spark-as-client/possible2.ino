#include <string.h>
char server[] = "bstolte.com";
TCPClient client;
 
int ledPin = D5;                 // choose the pin for the LED
int inputPin = D7;               // choose the input pin (for PIR sensor)
int pirState = LOW;              // we start, assuming no motion detected
int val = 0;                     // variable for reading the pin status
int count;  // print out to serial the number of times it's going through the loop
 
 
int getrequest();
 
void setup() {
    pinMode(ledPin, OUTPUT);     // set up the LED as an output, it will light up if motion is detected
    pinMode(inputPin, INPUT);    // read the input from the PIR sensor
    Spark.variable("inputPin", &inputPin, INT);  // Register the Spark variable for use with the API
    
    Serial.begin(9600);
    delay(1000);
    Serial.println("connecting...");
}
 
 
void loop() {
    
    val = digitalRead(inputPin);  // read the value from the PIR sensor
    if (val == HIGH) {    
        digitalWrite (ledPin, HIGH);  //Turn on the LED 
        delay(300);  // wait for 300ms
        getrequest(); //send to server
        
        if (pirState == LOW) {                     // we have turned on so let's let the serial monitor know
            Serial.println("Motion detected!");
            pirState = HIGH;                       // set it to high
        }
    }
    else {
        digitalWrite (ledPin, LOW);                // turn the LED off
        delay(300);                                // wait again for 300ms 
        if (pirState == HIGH) {                     // we have just turned off
            Serial.println("Motion ended!");
            pirState = LOW;
            count = 0;  // reset the counter
        }
    }
    
           
 
}
 
int getrequest(){
    client.connect(server, 80);
     
    if (client.connected()) {
            Serial.println("Connected");
            client.println("GET /motion_sms/sendsms/4154256133/home-alert HTTP/1.0");
            client.print("Host: ");
            client.println(server);
            client.println("Connection: close"); //just added
            client.println();
            client.flush();
            client.stop();
            return 1;
         }
        else {
            client.flush();
            client.stop();
            Serial.println("Not connected");
            return 0;
        }     
}
 
 
 /*
if (client.available()) {
client.flush();
}
*/
