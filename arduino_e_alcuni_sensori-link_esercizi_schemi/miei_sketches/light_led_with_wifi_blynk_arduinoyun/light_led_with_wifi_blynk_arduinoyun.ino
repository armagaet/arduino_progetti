//provo ad accendere un led tramite un pulsante su smartphone
//basta definire un pulsante switch sull'app associata al in digital 13 e in automatico arduino riconosce l'accensione
//poi uno slider sul digital pin 10, e collegando un led al D10 si accende variandone l'intensità..figo!
//scheda usata: arduino yun

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

#include <Bridge.h>
#include <YunClient.h>
#include <YunServer.h>
#include <BlynkSimpleYun.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "63ghs1-Tos461fYchuF1qEoruie7u71l";

void setup()
{
  Blynk.begin(auth);
  //Debug console
  //Serial.begin(9600);
  //delay(10);
  //Blynk.begin(auth, ssid, pass);
  //You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();
}
