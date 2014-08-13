var config = {};

/***********************/
/* CONFIGURAZIONI APP */
/**********************/
config.web = {};


//porta della app
//config.web.port = 3001; //test
config.web.port = 3000; //prod

//ip app per socket
config.web.host = 'http://192.168.1.12:' + config.web.port; //prod
//config.web.host = 'http://localhost:' + config.web.port; //test

//ip stream server
config.web.cam = 'http://192.168.1.12:9000';


/*******************************/
/* CONFIGURAZIONI RASPIARDUINO */
/*******************************/

config.raspi = {};
config.raspi.port = '/dev/ttyAMA0';

//se true non vengono fatte le chiamate ad arduino
config.raspi.test = false; //prod
//config.raspi.test = true; //test

//abilita o meno la ricezione del gyroscopio
config.raspi.mpu6050 = true; //prod
//config.raspi.mpu6050 = false; //test


/**********************/
/* CONFIGURAZIONI LOG */
/**********************/
config.log = {};

//path dei log
config.log.path = '/opt/logs/rover.log';

//livello di loggin info/warn/error 
config.log.level = 'info';
config.log.size = 5120000;

module.exports = config;
