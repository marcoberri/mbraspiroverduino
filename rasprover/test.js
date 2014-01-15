var mpu6050 = require('mpu6050');

// Instantiate and initialize.
var mpu = new mpu6050();
mpu.initialize();

for(var i=0; i<1000;i++){
// Test the connection before using.
  console.log(mpu.getMotion6());
  console.log(mpu.getRotation());
}
  
  // Put the MPU6050 back to sleep.
  mpu.setSleepEnabled(1);