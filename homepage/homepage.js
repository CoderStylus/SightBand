// Prove that the homepage.js file is loaded (for debugging purposes)
console.log("homepage.js loaded");

// NOTE: HC-06 Bluetooth module must be paired with the computer before running this code
// Import necassary dependencies (these must be installed with npm first)
import serialPort from 'serialport';
import Readline from '@serialport/parser-readline';
// Create a new serial port object with the address of the bluetooth module, setting the baud rate to 9600
const port = new serialPort('/dev/tty.BLUETOOTH ARDUINO ADDRRESS', { baudRate: 9600 });
// Create a new parser object that reads the data from the serial port object and splits it by the delimiter '\r\n'
const parser = port.pipe(new Readline({ delimiter: '\r\n' }));
// Receive data from the serial port and log it to the console
parser.on('data', (data) => {
    console.log('Received data:', data);
  }); 


// Change the color of the connection status button based on the connection status
var connectionStatusText = document.getElementById("connectionStatusText");
var connectionStatusButton = document.getElementById("connectionStatusButton");

if (connectionStatusText.innerHTML == "Connected") {
    connectionStatusButton.className = "navbtnstatusConnected";
}

if (connectionStatusText.innerHTML == "Disconnected") {
    connectionStatusButton.className = "navbtnstatusDisconnected";
}



// Sliders for vibration intensity and volume
 //(Based on tutorial from: https://www.w3schools.com/howto/howto_js_rangeslider.asp) 
 var vibrationSlider = document.getElementById("vibrationSlider"); //converts slider into a variable
 var volumeSlider = document.getElementById("volumeSlider"); //converts slider into a variable 
 var vibrationOutput = document.getElementById("VibrationIntensity"); //allows the user to see the value of the slider 
 var volumeOutput = document.getElementById("Volume"); //allows the user to see the value of the slider 
 
 vibrationOutput.innerHTML = vibrationSlider.value; //sets the value outputted to the user to the value of the slider 
 volumeOutput.innerHTML = volumeSlider.value; //sets the value outputted to the user to the value of the slider 
 
 vibrationSlider.oninput = function() { //updates the value of the slider 
     volumeOutput.innerHTML = volumeSlider.value; //sets the value outputted to the user to the value of the slider 
     vibrationOutput.innerHTML = this.value; 
 } 
 
 volumeSlider.oninput = function() { //updates the value of the slider 
     volumeOutput.innerHTML = volumeSlider.value; //sets the value outputted to the user to the value of the slider 
     volumeOutput.innerHTML = this.value; 
 }