// NOTE: HC-06 Bluetooth module must be paired with the computer before running this code

// Import necassary dependencies (these must be installed with npm first)
const serialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

// Create a new serial port object with the address of the bluetooth module, setting the baud rate to 9600
const port = new serialPort('/dev/tty.BLUETOOTH ARDUINO ADDRRESS', { baudRate: 9600 });

// Create a new parser object that reads the data from the serial port object and splits it by the delimiter '\r\n'
const parser = port.pipe(new Readline({ delimiter: '\r\n' }));

// Receive data from the serial port and log it to the console
parser.on('data', (data) => {
    console.log('Received data:', data);
  });



