var config = require('../conf/');
var logger = require('../data/logger').logger();


var SerialPort = require("serialport").SerialPort;

var sp = new SerialPort(config.raspi.port, {
  baudRate: 9600,
  parser: require("serialport").parsers.readline('\n'),
});

sp.on("open", function (err) {
	if(err){
		logger.info('err open ' + err);
		return;
	}
});


sp.on('data',function(data) {
	logger.info('Data: '+ data)
});

exports.left = function(req, res) {
   	logger.info("cam left");
	sp.write('t', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});
};

exports.right = function(req, res) {
   	logger.info("cam right");
	sp.write('y', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});

};

exports.reset = function(req, res) {
   	logger.info("cam reset");
	sp.write('u', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});
};

