var config = require('../conf/');
var logger = require('./logger').logger();

logger.info("config.raspi.mpu6050  ---> " + config.raspi.mpu6050);

exports.getMpu = function(){
  var mpu6050 = require('mpu6050');
  var mpu = new mpu6050();
  return mpu;
}
