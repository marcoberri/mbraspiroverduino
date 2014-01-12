require('../data/serialbinder');

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
<<<<<<< HEAD
};
=======
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


>>>>>>> a239e262329c49070342744d63509450d4fcc6d8
