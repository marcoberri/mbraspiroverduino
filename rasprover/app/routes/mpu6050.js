var config = require('../conf/');
var mpu6050 = require('mpu6050');

    var mpu = new mpu6050();
    mpu.initialize();

  exports.getRotation = function(req){
    if(!config.raspi.mpu6050) {
      req.io.emit('mpu6050', {message:[100,100,100,100], error : '',calling: '',type: 'mpu6050'});  
    }else{
     // var mpu = new mpu6050();
     // mpu.initialize();
      if(mpu.testConnection()){
      req.io.emit('mpu6050', {message: mpu.getRotation(), error : '',calling: '',type: 'mpu6050'});
    //  mpu.setSleepEnabled(1);
      }
    }

  };

  exports.getMotion = function(req){
    if(!config.raspi.mpu6050) {
      req.io.emit('mpu6050', {message:[100,100,100,100,100,100], error : '',calling: 'Motion',type: 'mpu6050'});  
    }else{  
     //var mpu = new mpu6050();
     // mpu.initialize();
      if(mpu.testConnection()){
      req.io.emit('mpu6050', {message: mpu.getMotion6(), error : '',calling: '',type: 'mpu6050'});
       //     mpu.setSleepEnabled(1);
      }
    }
  };
  
  
  exports.sleep = function(req){
      mpu.setSleepEnabled(1);
  };
      
