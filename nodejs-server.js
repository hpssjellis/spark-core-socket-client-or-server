
var net = require('net');




var server = net.createServer(function(socket){
  console.log("Someone connected from " + socket.remoteAddress + ":" + socket.remotePort + "!");
  process.stdout.write('>> ');
  process.stdin.on('data', function(d) {
    d = d.toString('utf8', 0, d.length - 1);
    if (/^[0-7][lh]$/i.test(d)) {
      socket.write(d.toLowerCase());
    } else if ('x' === d) {
      process.exit(0);
    } else {
      console.log("Commands: 0h  Set pin D0 high");
      console.log("          7l  Set pin D7 low");
      console.log("              Any pin 0-7 may be set high or low");
      console.log("          x   Exit");
    }
    process.stdout.write('>> ');
  });
});
server.listen(process.env.PORT );
console.log("Server running at "+process.env.IP+":"+process.env.PORT);
