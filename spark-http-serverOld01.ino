

TCPServer server = TCPServer(80);
TCPClient client;

char   addr[16];
char   myInput[30];
char   myIncoming;
int    myLoop1;
String myInStr;


void setup()
{
    
   pinMode(D7, OUTPUT);
   digitalWrite(D7, HIGH); 
   delay(1000);
   digitalWrite(D7, LOW); 
   delay(1000); 
   digitalWrite(D7, HIGH); 
   delay(1000);
   digitalWrite(D7, LOW); 
   delay(1000); 
   delay(1000);
   delay(1000);  // give a few seconds to reflash the core if it gets unresponsive on startup
   digitalWrite(D7, HIGH); 
   delay(300);
   digitalWrite(D7, LOW); 
    
    
  server.begin();
  IPAddress localIP = WiFi.localIP();
  sprintf(addr, "%u.%u.%u.%u", localIP[0], localIP[1], localIP[2], localIP[3]);
  Spark.variable("Address", addr, STRING);
  Spark.variable("myIn",  myInput, STRING);  
  Spark.variable("myLoop1", &myLoop1, INT);
}


void loop() {
    // listen for incoming clients
    client = server.available();
    if (client) {

      
        myLoop1 = 0;
        myInput[0] = '\0';

        boolean currentLineIsBlank = true;
        while (client.connected()) {
            

            if (client.available()) {



          
                myIncoming = client.read();       // read from the http request

               if (myLoop1 < 29 ){                 // http request should be much longer than 29 characters!
                   myInput[myLoop1] = myIncoming; // put the character into an array
                   
                } else {                           // read enough information from the http request
               
                    myInput[myLoop1] = '\0';      // helps make a char array compatible with a string.
      
                    myInStr = myInput;
                    myInStr.toUpperCase();
                          
                   if (myInStr.indexOf("D7-ON") >= 0){   digitalWrite(D7, HIGH); }  
                   if (myInStr.indexOf("D7-OFF") >= 0){  digitalWrite(D7, LOW); }  
                   

                   
                   }
              
                 myLoop1++;
                
                       
                       
                      
                if (myIncoming == '\n' && currentLineIsBlank) {

                   
                    //client.println("<H1>Hello World.</h1>");   // use for debugging to check if http request can get returned
                    
        
                    delay(1);
                    break;
                }
                if (myIncoming == '\n') {          // you're starting a new line
                    currentLineIsBlank = true;
                }
                else if (myIncoming != '\r') {     // you've gotten a character on the current line
                    currentLineIsBlank = false;
                }
                

            }
        }
        // give the web browser time to receive the data
        delay(1);
    }
    client.flush();
    client.stop();
}










/*

MAKE THIS HTML PAGE TO COMMUNICATE WITH YOUR CORE




<a  target="myI" href="https://api.spark.io/v1/devices/{CORE-ID}/Address?access_token={ACCESS-TOKEN}" >Address</a><br>


<a  target="myI" href="http://192.145.1.65?D7-ON" >D7-ON</a>...
<a  target="myI" href="http://192.145.1.65?D7-OFF" >D7-OFF</a><br><br><br>

<iframe name="myI" width=500 height=400></iframe>


















The serial printout looks like

192.145.1.65
GET /?D7-ON HTTP/1.1
Host: 192.145.1.65
Connection: keep-alive
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,* / *;q=0.8
User-Agent: Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2231.0 Safari/537.36
Accept-Encoding: gzip, deflate, sdch
Accept-Language: en-US,en;q=0.8




*/


