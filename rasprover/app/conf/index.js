var config = {};

/***********************/
/* CONFIGURAZIONI APP */
/**********************/
config.web = {};


//porta della app
config.web.port = 3000;
//ip app per socket
config.web.host = 'http://localhost:3000';
//ip stream server
config.web.cam = 'http://192.168.1.12:9000';


/*******************************/
/* CONFIGURAZIONI RASPIARDUINO */
/*******************************/

config.raspi = {};
config.raspi.port = '/dev/ttyACM0';

//se true non vengono fatte le chiamate ad arduino
config.raspi.test = true;


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
