require('../data/serialBinder');


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

exports.acc = function(req) {
	spwrite('+', req);
};

exports.dec = function(req) {
	spwrite('-', req);
};

