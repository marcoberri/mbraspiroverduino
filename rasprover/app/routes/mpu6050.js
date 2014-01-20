require('../data/mpu6050');

  exports.getRotation = function(req){
    if(sleep == true){
      mpu.initialize();
      logger.info("gyro Init");
      sleep = false;
    }
	req.io.emit('mpu6050', {message: mpu.getRotation(), error : '',calling: '',type: 'mpu6050'});

  };

  exports.getMotion = function(req){
    if(sleep == true){
      mpu.initialize();
      logger.info("gyro Init");
      sleep = false;
    }
	req.io.emit('mpu6050', {message: mpu.getMotion6(), error : '',calling: '',type: 'mpu6050'});
  };
  
  
  exports.sleep = function(req){
    if(sleep == false){
      mpu.setSleepEnabled(1);
      logger.info("gyro Init");
    };
  };
      
