var i2c = require('i2c');
var address = 0x18;
var wire = new i2c(address, {device: '/dev/i2c-1'}); 
// point to your i2c address, debug provides REPL interface

wire.scan(function(err, data) {
  console.log(err);
  console.log(data);
  // result contains an array of addresses
  });