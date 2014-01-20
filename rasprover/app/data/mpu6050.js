var config = require('../conf/');
var logger = require('./logger').logger();

logger.info("config.raspi.mpu6050  ---> " + config.raspi.mpu6050);

if(config.raspi.mpu6050){

  var mpu6050 = require('mpu6050');
  var mpu = new mpu6050();
  var sleep = true;
  
}//if(config.rapsi.mpu6050){

