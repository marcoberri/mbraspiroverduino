var mpu = require('../data/mpu6050').getMpu();
var config = require('../conf/');


  exports.getRotation = function(req){
    if(!config.raspi.mpu6050) {
      req.io.emit('mpu6050', {message:[100,100,100,100], error : '',calling: '',type: 'mpu6050'});  
    }else{
      req.io.emit('mpu6050', {message: mpu.getRotation(), error : '',calling: '',type: 'mpu6050'});
    }

  };

  exports.getMotion = function(req){
    if(!config.raspi.mpu6050) {
      req.io.emit('mpu6050', {message:[100,100,100,100,100,100], error : '',calling: 'Motion',type: 'mpu6050'});  
    }else{  
      req.io.emit('mpu6050', {message: mpu.getMotion6(), error : '',calling: '',type: 'mpu6050'});
    }
  };
  
  
  exports.sleep = function(req){
      mpu.setSleepEnabled(1);
  };
      
