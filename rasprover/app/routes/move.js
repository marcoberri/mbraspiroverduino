require('../data/serialbinder');


exports.right = function(req) {
	spwrite('R', req);
};

exports.forward = function(req) {
	spwrite('F', req);
};

exports.back = function(req) {
	spwrite('B', req);
};

exports.stop = function(req) {
	spwrite('S', req);
};
<<<<<<< HEAD
=======

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
>>>>>>> a239e262329c49070342744d63509450d4fcc6d8
