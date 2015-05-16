# spark-socket-client-or-server
Attempt to test using the spark core or photon as a client or server for fast communication to light D7 LED


For my failed kickstarter at https://www.kickstarter.com/projects/rocksetta/rover-the-shopping-drone I made an internet rover that could go anywhere, but the time lag using the spark cloud was between 300 ms and 1200 ms, which is great for environmental data but really bad for driving a vehicle. I would like to try out direct communication using websockets but the present examples are either really confusing (voodoospark) and hence not very useful for trying to make your own programs, or the examples simply do not work or sort off work but the interface is not well explained. Voodoo spark is suppossed to easily work with telnet but I could not get it going.



May 16th, 2015

Trying a nodejs server with a test .ino but I am still far away from this one working. Some good node ideas but USB tethered here

https://github.com/GianlucaGuarini/nodejs-arduino-example



May 8, 2015
Making another attempt. Found out that serial information from the spark core was killing the core, so will try not to use it. trying Ajax now. kind of getting it working but need to get the core to reply back to the AJAX for the ajax to close. Have some ideas




April 22, 2015

Solved it and without using AJAX or Websockets. I just send the command in a regular http://x.x.x.x/?D7-ON request. I use the spark server running port 80 for regular http. I then read each character and extract the first 30 characters and compare if they contain D7-ON , if so I light the D7 LED. The http request expects a webpage to be returned I just ignore it by sending the response to an iFrame.

Flash the .ino file to your core and load the .html page either from a website, your own computer or make it into a phonegap App (not yet tested). When the page loads you have to enter your Core-ID and Access-token to get your cores IP from the cloud. Then you can enter that IP in the IP textbox and start activating Spark Core PINs. This is all setup to quickly send information to the core, not to get information back from the core. That will have to be another project, or simply use the cloud service.




April 14, 2015 First day: The two basic issues are:



Spark core as a server and use a regular websocket html page to connect

or

Spark core as a client and use a node server with a webbrowser interface (like a chat server) to connect

All I wish to do is send two strings to the spark core or photon


D7-ON


and


D7-OFF


Note: I do not wish to have any debug information in the code as the D7 LED on or off is proof that it is working.


Other Links (which I can not seem to get working):

https://github.com/rwaldron/spark-io

https://github.com/fitosegrera/sparkCoreNodeJS

https://community.spark.io/t/solved-voodoospark-setup-troubles/9091/10

https://community.spark.io/t/since-new-firmware-yesterday-i-am-unable-to-successfully-load-voodoospark/4260/3

https://community.spark.io/t/calling-functions-over-network/9067/5


https://community.spark.io/t/unable-to-connect-to-spark-cloud-404-error-from-spark-io-npm-module-trying-to-access-endpoint-solved/6038/2


https://community.spark.io/t/talk-to-core-photon-over-wifi-but-no-local-network-available/9060/9


https://community.spark.io/t/local-spark-core-tcp-server-or-client/7950/15




https://community.spark.io/t/how-to-divorce-spark-from-cloud/8143/2



https://community.spark.io/t/communication-between-nodejs-and-sparkcore-without-sparkcloud/10654



https://community.spark.io/t/sockets-from-a-web-page-multiple-analogwrites-per-second/10376/3



https://community.spark.io/t/making-a-game-w-spark-core-better-way-than-post-request/5875/9


http://docs.spark.io/firmware/#communication-tcpserver


http://docs.spark.io/firmware/#communication-tcpclient


http://socket.io/get-started/chat/



http://ahoj.io/nodejs-and-websocket-simple-chat-tutorial















