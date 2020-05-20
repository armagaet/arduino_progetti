//recupero questo sketch dal video https://www.youtube.com/watch?v=M5CYBHzMejo
//il quale connette quasi direttamente il modulo esp8266 ad arduino
//CAZZO FUNZIONA!!

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
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  You’ll need:
   - Blynk App (download from AppStore or Google Play)
   - Arduino Uno board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "nYBImSOguzaIc07J5K-iH_z6CkB4Amis"; //ligthled13

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PocketCube-2DC9";
char pass[] = "Q6Q1YH4F";

// Hardware Serial on Mega, Leonardo, Micro...
//#define EspSerial Serial1                   //<---------------------------------------------------------

// or Software Serial on Uno, Nano...
//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(2, 3); // RX, TX

// Your ESP8266 baud rate:
//#define ESP8266_BAUD 9600                     //<---------------------------------------------------------
#define ESP8266_BAUD 115200

//questo skecth temo usi le porte RX-TX classiche su Arudino.
//provo a riconfigurarle?
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2,3); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                            // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                            // and the RX line from the esp to the Arduino's pin 3
//ESP8266 wifi(&Serial); //forse se definisco RX/TX con SoftwareSerial devo commentare questa riga??  //<---------------------------------------------------------
ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  //Serial.begin(9600);                       //<---------------------------------------------------------

  // Set ESP8266 baud rate
  Serial.begin(ESP8266_BAUD);                 //<---------------------------------------------------------
  EspSerial.begin(115200);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
