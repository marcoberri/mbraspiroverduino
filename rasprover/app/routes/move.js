require('../data/serialBinder');
var logger = require('../data/logger').logger();

exports.right = function(req) {
	spwrite('R', req);
};

exports.left = function(req) {
	spwrite('L', req);
};

exports.forward = function(req) {
	spwrite('F', req);
};

exports.back = function(req) {
	spwrite('B', req);
};

exports.stop = function(req) {
	logger.warn("Call S");
	spwrite('S', req);
};

exports.acc = function(req) {
	spwrite('+', req);
};

exports.dec = function(req) {
	spwrite('-', req);
};

