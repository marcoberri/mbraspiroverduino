var config = require('../conf/');
var logger = require('../data/logger').logger();


var SerialPort = require("serialport").SerialPort;

var sp = new SerialPort("/dev/ttyACM0", {
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
   	logger.info("left");
	sp.write('l', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});
};

exports.right = function(req, res) {
   	logger.info("right");
	sp.write('r', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});

};

exports.forward = function(req, res) {
   	logger.info("forward");
	sp.write('f', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});
};

exports.back = function(req, res) {
   	logger.info("back");
	sp.write('b', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });

	});
};

exports.stop = function(req, res) {
   	logger.info("stop");
	sp.write('s', function(err, results) {
		if(err){
			console.log('err write ' + err);
		}  
		res.jsonp({ result: true, data: results });
	});

};
