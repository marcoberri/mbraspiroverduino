var config = require('../conf/');
var logger = require('./logger').logger();


logger.info("config.raspi.test  ---> " + config.raspi.test);

if(!config.raspi.test){
	
        var SerialPort = require("serialport").SerialPort;

        var sp = new SerialPort(config.raspi.port, {
  	        baudRate: 9600,
          	parser: require("serialport").parsers.readline('\n'),
        });

        sp.on("open", function (err) {
	        if(err){
                  	req.io.emit('log', {message: '', error : err, calling: '-',type: 'hw'});
                  	logger.error('err open ' + err);
        	}
        });

        sp.on('data',function(data) {
	        logger.info('Data: '+ data)
        });

        spwrite = function(letter, req){

	        sp.write(letter, function(err, results) {

		        if(err){
			        logger.error('err write ' + err);
        		}  
	
	        	req.io.emit('log', {message: results, error : err,calling: letter,type: 'hw'});
        	});
	};

}else{
        spwrite = function(letter, req){
   		var msg = 'testing mode';	
  		var err = "errore";
		req.io.emit('log', {message: msg, error : err, calling: letter,type: 'hw'});
	}

}
