
exports.logger = function() {

	var config = require('../conf/');
	var winston = require('winston');

	var logger =  new (winston.Logger)({

		transports : [ new (winston.transports.Console)(),
				new (winston.transports.File)({
					filename : config.log.path,
					level: config.log.level
					//,maxsize : config.log.size
				}) ]
	});
	
	
	return logger;

};
