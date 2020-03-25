//liberamente tratto da: https://win.adrirobot.it/sensori/37_in_1/KY-036-Metal-touch-sensor-module.htm

int max=250;
int buzzer = 12;
int touchPin = 2;
int led_R = 9;
int pin_A0 = A0;
int valore_A0 = 0;

void setup() {
  pinMode(led_R, OUTPUT); //colleghiamo il catodo del led, con resistenza intermedia
  pinMode(touchPin, INPUT); //pin digitale in uscita del sensore
  pinMode(buzzer, OUTPUT); //pin buzzer passivo
  digitalWrite(led_R, LOW);
  Serial.begin(9600);
}
void loop() {
  
  //if(analogRead(pin_A0)<=max){
  //meglio eggere il valore di touch sul pin digitale
  int touchState = digitalRead(touchPin);
  if (touchState == HIGH) {
    /*Serial.println("-- lettura su pin anaogico --");
    Serial.println(analogRead(pin_A0));
    Serial.println("-- lettura su pin digitale --");
    Serial.println(digitalRead(touchPin));*/

    //se invece vogliamo plottare solo il valore di A0 sul "plotter seriale", commenta i precedenti "Serial.println":
    valore_A0 = analogRead(pin_A0);
    Serial.println(valore_A0);
  
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
