var mpu6050 = require('mpu6050');

// Instantiate and initialize.
var mpu = new mpu6050();
mpu.initialize();


if(mpu.testConnection()){
for(var i=0; i<1000;i++){
// Test the connection before using.
  console.log(mpu.getMotion6());
}
  }
