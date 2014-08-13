var config = require('../conf/');
var logger = require('./logger').logger();



var cachePingFront = 0;
var emitTime = 0;

var SerialPort = require("serialport").SerialPort;

var sp = new SerialPort(config.raspi.port, {
        baudRate: 9600,
        parser: require("serialport").parsers.readline('\n'),
});

exports.initConnection = function(socket) {
	
        sp.on("open", function (err) {
	        if(err){
                  	socket.emit('log', {message: '', error : err, calling: '-',type: 'hw'});
                  	logger.error('err open ' + err);
        	}
        });

        sp.on('data',function(data) {
        
        try{ 
        
                var json = JSON.parse(data);
                if(json.type == 'ping-front'){
                        if(emitTime > 10){
                                emitTime=0;
                                if(json.message != cachePingFront){
                                        //logger.info('data.type= ' + json.type);
                                        //logger.info('data.message = ' + json.message);
                                        cachePingFront = json.message;                
                                        socket.emit(json.type,{ 'message' : cachePingFront});
                                }
                        } else {
                                emitTime = emitTime + 1;
                        }	
                
                }
                
	  } catch(e) {
	          logger.error("error" + e);
	  }      
	  
        });
        
}



spwrite = function(letter, req){

        sp.write(letter, function(err, results) {

        if(err){
	       logger.error('err write ' + err);
		}  
	
		req.io.emit('log', {message: results, error : err,calling: letter,type: 'hw'});
       	});
};

/*}else{
        spwrite = function(letter, req){
   		var msg = 'testing mode';	
  		var err = "errore";
		req.io.emit('log', {message: msg, error : err, calling: letter,type: 'hw'});
	}

}*/
