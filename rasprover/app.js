var config = require('./app/conf/');
var http = require('http');
var express = require('express');
var logger = require('./app/data/logger').logger();
var routesHome = require('./app/routes/');
var routesMove = require('./app/routes/move');

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
//app.use(require('express-minify')());
app.use(express.compress());

app.get('/', routesHome.index);

//MOVE
app.post('/move/left', routesMove.left);
app.post('/move/right', routesMove.right);
app.post('/move/back', routesMove.back);
app.post('/move/forward', routesMove.forward);
app.post('/move/stop', routesMove.stop);

app.use(function(err, req, res, next) {
	logger.error(err.stack);
	res.send(500, 'Error Page: ' + err.stack);
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

http.createServer(app).listen(app.get('port'), function() {
	logger.info('Rover server listening on port ' + app.get('port'));
});
