#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#include<SoftwareSerial.h>


/*

PIN DIAGRAM
WE have used arduino uno
ARDUINO UNO            TFT LCD
9                      A0
10                     CS
11                     SDA
12                     RESET
13                     SCK
3.3V                   LED
5V                     VCC
GND                    GND

*/



SoftwareSerial uno_to_mega(6, 5);   //rx,tx
// All wiring required, only 3 defines for hardware SPI on 328P
#define __DC 9
#define __CS 10
// MOSI --> (SDA) --> D11
#define __RST 12
// SCLK --> (SCK) --> D13

//#define __DC A2
//#define __CS A3
//// MOSI --> (SDA) --> D11
//#define __RST 12
//// SCLK --> (SCK) --> D13



// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC, __RST);

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(4,HIGH);  //vcc
  digitalWrite(3,LOW); // gnd
  tft.begin();
  uno_to_mega.begin(9600);

}

void loop() {


  //  testLines(random(0x00ff, 0xffff));
  //  delay(100);
  testText();
  delay(600);
}


unsigned long testText() {
  tft.fillScreen();
  unsigned long start = micros();
  // long rand_bpm = random(80, 85);
  // long rand_spo2 = random(90, 97);
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.println();
  tft.print("BPM :");
  // tft.println(rand_bpm);
  //  tft.println();
  tft.setTextColor(YELLOW);
  tft.setTextSize(3);
  tft.print("SpO2:");
  // tft.println(rand_spo2);
  //  tft.setTextColor(RED);
  //  tft.setTextSize(3);
  //  tft.println(0xDEAD, HEX);
  //  tft.println();
  //  tft.setTextColor(GREEN);
  //  tft.setTextSize(2);
  //  tft.println("IDRIS MITHAIWALA");
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  delay(90);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  delay(800);
  return micros() - start;

}



