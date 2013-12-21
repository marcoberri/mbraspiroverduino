var config = require('../conf/');

exports.index = function(req, res) {
	var obj = {
		title : 'test',
		proxy : config.web.pagetestproxy
	};
	res.render('index', obj);
};

