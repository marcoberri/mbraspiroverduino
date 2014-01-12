var config = require('../conf/');

exports.index = function(req, res) {
	var obj = {
		config : config
	};

	res.render('index', obj);
};

