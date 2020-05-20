/*
  AnalogReadSerial
  -- start from this basic example and then add components

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  From the center pin, attach laso a resistor and a led,
  in order to modulate the light of the led based on the potentionemter.
  

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

const unsigned int LED_PIN = 13;
const unsigned int BAUD_RATE = 9600;
float voltageValue; // variable to get a value from a voltage source (example)

// the setup routine runs once when you press reset:
void setup() {
  pinMode(LED_PIN, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  //Serial.println(sensorValue);
  // this sensorValue s a number between 0 and 1023.
  // if connected to +5V, 1023 is equal to this voltage.
  // So we can have in output the voltage provided bt the potentiometer:
  voltageValue = sensorValue * float(5) / float(1023);
  // dobbiamo dichiarare float() perche' l'operazione viene eseguita
  // usando il tipo dei dati degli operandi
  Serial.print ( voltageValue );
  Serial.println( " VDC" );
  delay(1000);        // delay in between reads for stability
}
