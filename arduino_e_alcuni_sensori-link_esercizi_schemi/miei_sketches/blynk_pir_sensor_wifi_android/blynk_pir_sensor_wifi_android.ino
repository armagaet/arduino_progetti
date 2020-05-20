//scopo è far accendere un led virtuale sul cellulare tramite blynk
//quando il sensore ad infrarosi PIR intercetta un movimento
//aggiungere al nuovo progetto blynk un led associandolo al virtual pin V1

/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  This example shows how value can be pushed from Arduino to
  the Blynk App.
 *************************************************************/

//MODIFICATE LE LIBRERIE DA CHIAMARE PER USARE UNO WIFI DEVELOPER EDITION

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#include <SPI.h>
#include <WiFiLink.h>
#include <BlynkSimpleWiFiLink.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "VTumGTn60iMUIRhFIeLDZg7Hsf1k3UHl";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PocketCube-2DC9";
char pass[] = "Q6Q1YH4F";
int status = WL_IDLE_STATUS;     // the Wifi rad

const int pir=2;
WidgetLED led1(V1);

void setup()
{
  //Blynk.begin(auth);
  // Debug console
  Serial.begin(9600);
  delay(10);
  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

  pinMode(pir, INPUT);
}

void loop()
{
  Blynk.run();
  if (digitalRead(pir)) {
    f_alarm(1500);
  }
}

void f_alarm(unsigned char delayms) {
  led1.on();
  delay(delayms);
  led1.off();
  delay(delayms);
}
