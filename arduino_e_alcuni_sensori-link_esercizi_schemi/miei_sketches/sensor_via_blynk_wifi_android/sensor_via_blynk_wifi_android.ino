//OK dovrebbe funzionare col sensore DHT11, temperatura e umidità!

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

  WARNING :
  For this example you'll need Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App project setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
 *************************************************************/
//wiring schema: http://www.getmicros.net/wp-content/uploads/2013/12/Arduino-and-DHT11_bb.png
/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial

//#include <UnoWiFiDevEdSerial1.h>
//#include <Wire.h>
//#include <UnoWiFiDevEd.h>

//#include <SPI.h>
//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>
//#include <DHT.h>

//MODIFICATE LE LIBRERIE DA CHIAMARE PER USARE UNO WIFI DEVELOPER EDITION

     /* Comment this out to disable prints and save space */
     #define BLYNK_PRINT Serial
     #define BLYNK_DEBUG

     #include <SPI.h>
     #include <WiFiLink.h>
     #include <BlynkSimpleWiFiLink.h>
     #include <DHT.h>

     // You should get Auth Token in the Blynk App.
     // Go to the Project Settings (nut icon).
char auth[] = "egNaCJPajfAQH-i8iOA3_LEmJ3MkvcU0";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PocketCube-2DC9";
char pass[] = "Q6Q1YH4F";

int status = WL_IDLE_STATUS;     // the Wifi rad


#define W5100_CS  10
#define SDCARD_CS 4

#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(SDCARD_CS, OUTPUT);
  digitalWrite(SDCARD_CS, HIGH); // Deselect the SD card

  //Blynk.begin(auth);

  // Debug console
       Serial.begin(9600);

       //Blynk.begin(auth, ssid, pass);
       // You can also specify server:
       Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
       //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
       
  // You can also specify server:
  //Blynk.begin(auth, "blynk-cloud.com", 80);
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
