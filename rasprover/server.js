var cluster = require('cluster');

cluster.on('exit', function(worker) {
	console.log('Worker ' + worker.id + ' died :(');
	cluster.fork();
});

if (cluster.isMaster) {
	var cpuCount = require('os').cpus().length;
	
	for ( var i = 0; i < cpuCount; i += 1) {
		console.log('Worker ' + (i + 1) + '/' + cpuCount + " --> FORK");
		cluster.fork();
	}
	
} else {
	require('./app');
}
