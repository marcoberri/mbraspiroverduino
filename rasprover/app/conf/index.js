var config = {};

/***********************/
/* CONFIGURAZIONI APP */
/**********************/
config.web = {};

//porta della app
config.web.port = 3000;
config.web.host = 'http://192.168.1.12:3000'


/**********************/
/* CONFIGURAZIONI LOG */
/**********************/
config.log = {};

//path dei log
config.log.path = '/opt/logs/rover.log';

//livello di loggin info/debug/error 
config.log.level = 'debug';
config.log.size = 5120000;

module.exports = config;
