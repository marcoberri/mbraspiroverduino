var config = require('../conf/');
var logger = require('./logger').logger();


logger.info("config.raspi.mpu6050  ---> " + config.raspi.mpu6050);

if(config.raspi.mpu6050){

  var mpu6050 = require('mpu6050');
  var mpu = new mpu6050();
  var sleep = true;
  

  exports.getRotation = function(){
    if(sleep == true){
      mpu.initialize();
      logger.info("gyro Init");
      sleep = false;
    }
    return mpu.getRotation();
  };

  exports.getMotion = function(){
    if(sleep == true){
      mpu.initialize();
      logger.info("gyro Init");
      sleep = false;
    }

    return mpu.getMotion6();
  };
  
  
  exports.sleep = function(){
    if(sleep == false){
      mpu.setSleepEnabled(1);
      logger.info("gyro Init");
    };
  };
  
}//if(config.rapsi.mpu6050){