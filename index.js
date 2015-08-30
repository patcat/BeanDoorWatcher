var SerialPort = require("serialport").SerialPort,
    serialPort = new SerialPort("/dev/cu.LightBlue-Bean", {
      baudrate: 57600
    }),
    request = require('request');

serialPort.on("open", function () {
	console.log("Connected to LightBlue Bean serial port");

	serialPort.on("data", function(data) {
		console.log("Data: " + data);
    data = data + "";

    if (data == "CLOSED") {
      request.post({
        url: "http://maker.ifttt.com/trigger/bean_door_closed/with/key/YOURKEYHERE"
      }, function(error, response, body) {
        console.log(body);
        if (error) console.log("Error was ", error);
      });
    } else if (data == "OPEN") {
      request.post({
        url: "http://maker.ifttt.com/trigger/bean_door_open/with/key/YOURKEYHERE"
      }, function(error, response, body) {
        console.log("Body response was ", body);
        if (error) console.log("Error was ", error);
      });
    }
	});
});