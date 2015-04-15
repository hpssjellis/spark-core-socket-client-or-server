# spark-socket-client-or-server
Attempt to test using the spark core or photon as a client or server for fast communication to light D7 LED


For my failed kickstarter at https://www.kickstarter.com/projects/rocksetta/rover-the-shopping-drone I made an internet rover that could go anywhere, but the time lag using the spark cloud was between 300 ms and 1200 ms, which is great for environmental data but really bad for driving a vehicle. I would like to try out direct communication using websockets but the present examples are either really confusing (voodoospark) and hence not very useful for trying to make your own programms, or the examples simply do not work or sort off work but the interface is not well explained. Voodoo spark is suppossed to easily work with telnet but I could not get it going.



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















