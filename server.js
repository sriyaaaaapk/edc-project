const express = require('express');
const serialport = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const app = express();
const PORT = 3000;
const COM_PORT = 'COM7'; // change this if your Arduino uses another port

app.use(express.static('public'));

// Serial setup
const port = new serialport.SerialPort({ path: COM_PORT, baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

let latestData = { moisture: 0, status: "Waiting for data..." };

parser.on('data', (line) => {
  const parts = line.trim().split(',');
  if (parts.length === 2) {
    const moisture = parseInt(parts[0]);
    const watering = parseInt(parts[1]);
    latestData = {
      moisture,
      status: watering === 1 ? "💧 Motor ON" : "🌿 Motor OFF"
    };
  }
});

app.get('/data', (req, res) => {
  res.json(latestData);
});

app.listen(PORT, () => {
  console.log(`✅ Server running on http://localhost:${PORT}`);
  console.log(`📡 Reading from ${COM_PORT}`);
});