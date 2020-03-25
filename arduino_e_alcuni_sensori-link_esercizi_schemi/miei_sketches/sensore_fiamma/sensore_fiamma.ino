//liberamente tratto da: https://www.progettiarduino.com/12-arduino-antincendio-sensore-fiamma.html#
//come alternare suono del buzzer e accensione del led??

int max=50;
int buzzer = 12;
int flamePin = 2;
int led_R = 9;
int pin_A0 = A0;
int valore_A0 = 0;

void setup() {
  pinMode(led_R, OUTPUT); //colleghiamo il catodo del led, con resistenza intermedia
  pinMode(flamePin, INPUT); //pin digitale in uscita del sensore
  pinMode(buzzer, OUTPUT); //pin buzzer passivo
  digitalWrite(led_R, LOW);
  Serial.begin(9600);
}
void loop() {
  valore_A0 = analogRead(pin_A0);
  if (valore_A0 <= max) {
  //oppure leggere il valore di fiamma sul pin digitale 
  //int flameState = digitalRead(flamePin);
  //if (flameState == HIGH) {
    Serial.println("-- lettura su pin anaogico --");
    Serial.println( valore_A0 );
    Serial.println("-- lettura su pin digitale --");
    Serial.println(digitalRead(flamePin));

    //se invece vogliamo plottare solo il valore di A0 sul "plotter seriale", commenta i precedenti "Serial.println":
    //Serial.println(valore_A0);
  
    alarm_and_flash();
    alarm();
    flash();
    digitalWrite(led_R, HIGH);
  }
  else {
    digitalWrite(led_R, LOW);
  }
}
void alarm_and_flash() {
  tone(buzzer,400,500);
  digitalWrite(led_R, HIGH);
  delay(500);
  digitalWrite(led_R, LOW);
  tone(buzzer,650,500);
  digitalWrite(led_R, HIGH);
  delay(500);
  digitalWrite(led_R, LOW);
}
void alarm() {
  tone(buzzer,400,500);
  delay(500);
  tone(buzzer,650,500);
  delay(500);
}
void flash() {
  digitalWrite(led_R, HIGH);
  delay(50);
  digitalWrite(led_R, LOW);
}
