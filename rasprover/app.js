var config = require('./app/conf/');
var socketio = require("socket.io");
var http = require('http');
var express = require('express.io');
var logger = require('./app/data/logger').logger();
var routesHome = require('./app/routes/');
var routesMove = require('./app/routes/move');
var routesCam = require('./app/routes/cam');

var app = express();

app.set('port', config.web.port);

app.set('views', __dirname + '/app/views');
app.set('view engine', 'ejs');
app.use(express.cookieParser());
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.urlencoded());
app.use(express.json());
app.use(express.methodOverride());


app.use(app.router);
app.use(express.static(__dirname + '/public'));
app.use(express.compress());

app.get('/', routesHome.index);


app.http().io();
app.io.enable('browser client minification');  // send minified client
app.io.enable('browser client etag');          // apply etag caching logic based on version number
app.io.enable('browser client gzip');  
app.io.set('log level', 1);   


app.use(function(err, req, res, next) {
	logger.error(err.stack);
	res.jsonp(500, {errror :  err.stack});
});

app.configure('development', function() {
	app.use(express.errorHandler({
		dumpExceptions : true,
		showStack : true
	}));
});

app.configure('production', function() {
	app.use(express.errorHandler());
});


//MOVE
app.io.route('/move/left',routesMove.left);
app.io.route('/move/right', routesMove.right);
app.io.route('/move/back', routesMove.back);
app.io.route('/move/forward', routesMove.forward);
app.io.route('/move/stop', routesMove.stop);
//CAM
app.io.route('/cam/reset', routesCam.reset);
app.io.route('/cam/left', routesCam.left);
app.io.route('/cam/right', routesCam.right);
app.io.route('/cam/up', routesCam.up);
app.io.route('/cam/down', routesCam.down);


// Setup the ready route, and emit talk event.


app.io.sockets.on('connection', function (socket) {
    console.log('A socket connected!');
			socket.emit('log', {message: "A socket connected!", calling: "-", type: 'conn'});
});

app.listen(app.get('port'),function() {
	logger.info('Rover server listening on port ' + app.get('port'));
});


