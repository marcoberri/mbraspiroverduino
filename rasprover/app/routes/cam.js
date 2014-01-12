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
};