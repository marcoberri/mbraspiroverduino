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
    spwrite('T',req);
};

exports.right = function(req, res) {
    spwrite('Y',req);
};


exports.up = function(req, res) {
    spwrite('A',req);
};

exports.down = function(req, res) {
    spwrite('Q',req);
};


exports.reset = function(req) {
    spwrite('U',req);
};


spwrite = function(letter, req){
/*	var msg = 'msg';	
  var err = "errore";
	req.io.emit('log', {message: msg, error : err, calling: letter,type: 'hw'});
*/
	sp.write(letter, function(err, results) {
		if(err){
			logger.error('err write ' + err);
		}  
	
		req.io.emit('log', {message: results, error : err,calling: letter,type: 'hw'});
	});

}


