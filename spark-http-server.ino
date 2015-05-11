
// By Jeremy Ellis twitter @rocksetta or http://www.rocksetta.com
TCPServer server = TCPServer(80);
TCPClient client;

char   addr[16];
char   myInput[30];
char   myIncoming;
int    myLoop1;
String myInStr;

void setup()
{
   myInStr.reserve(30);  //reserves 30 chars of String space 
   pinMode(D7, OUTPUT);

   IPAddress localIP = WiFi.localIP();
   sprintf(addr, "%u.%u.%u.%u", localIP[0], localIP[1], localIP[2], localIP[3]);
   Spark.variable("Address", addr, STRING);
   
   // call this from a web page using
   //<a  target="myI" href="https://api.spark.io/v1/devices/{CORE-ID}/Address?access_token={ACCESS-TOKEN}" >Address</a><br>
   // or from you browser using
   //https://api.spark.io/v1/devices/{CORE-ID}/Address?access_token={ACCESS-TOKEN}
   

   pinMode(D7, OUTPUT);
   digitalWrite(D7, HIGH); 
   delay(15000);                 // a little bit of time to re-flash core, check cloud etc.
   digitalWrite(D7, LOW); 
    
   server.begin();

}

void loop() {
   if (client.connected()) {     
        myLoop1 = 0;
        myInput[0] = '\0';

        while (client.available()) {
            myIncoming = client.read();         // read from the http request
            if (myLoop1 < 29 ){                 // http request should be much longer than 29 characters!
                myInput[myLoop1] = myIncoming;  // put the character into an array
                } else {                        // have read enough information from the http request
               
                    myInput[myLoop1] = '\0';    // helps make a char array compatible with a string.
                    myInStr = myInput;
                    myInStr.toUpperCase();
                          
                    if (myInStr.indexOf("D7-ON")  >= 0){ digitalWrite(D7, HIGH); }  
                    if (myInStr.indexOf("D7-OFF") >= 0){ digitalWrite(D7, LOW);  }  
                    if (myInStr.indexOf("DARK")   >= 0){ RGB.brightness(1);      }  
                    if (myInStr.indexOf("BRIGHT") >= 0){ RGB.brightness(250);    }  
                   
                    while(client.read() >= 0);    // ignore the rest of the http request
                    client.stop();                // shut down the client for next connection
                   }
                 myLoop1++;
        }  
    } else {     
        client = server.available();        // if no client is yet connected, check for a new connection
      }
}   




/*

--Cut this into a web page only for your computer. Use the localStorage webpage for anything on the actual web.
What is really cool is that you can call this line directly from your browser to check something on your Spark Core or Photon

http://192.168.1.2?D7-ON





So your web page simply needs, to find your IP using <br>

<a  target="myI" href="https://api.spark.io/v1/devices/{CORE-ID}/Address?access_token={ACCESS-TOKEN}" >Address</a><br>



And change the IP in the following javascript<br>

<a id="myOn" target="myI" href="http://192.168.1.2?D7-ON" >D7-ON</a>...
<a id="myOff" target="myI" href="http://192.168.1.2?D7-OFF" >D7-OFF</a>...<br>

<iframe id="myIframe" name="myI" width=200 height=100></iframe>





For a bit fancier<br>
<input id="myOn2" type=button value="D7-ON-2" onclick="{
   document.getElementById('myIframe').src = 'http://192.168.1.2?D7-ON'
   setTimeout(function(){ document.getElementById('myIframe').src = 'generic.html' }, 17); 

}"><br>

<input id="myOff2" type=button value="D7-Off-2" onclick="{
    document.getElementById('myIframe').src = 'http://192.168.1.2?D7-OFF'
    setTimeout(function(){ document.getElementById('myIframe').src = 'generic.html' }, 17); 
}"><br><br>

Note: you need to make a simple web page called generic.html for the above to work.

*/






