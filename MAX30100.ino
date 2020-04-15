
#include<Wire.h>
#include "MAX30100_PulseOximeter.h"

#define REPORTING_PERIOD_MS    1000

/*
I have used Arduino Mega
Arduino mega                  MAX30100 
GND                             GND
SDA-20                           SDA
SCL-21                           SCL
3.3V                             Vin
*/



PulseOximeter pox;

uint32_t tsLastReport = 0;


void onBeatDetected()
{
  //  Serial.println("Beat!");
}


void setup() {
  // put your setup code here, to run once:
  //  Serial.begin(115200);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  //  Serial.print("Initalizing sucess!!!!!!");
  //  Serial.print("Hello");
  if (!pox.begin()) {
    //    Serial.println("Falied");
    for (;;);
  } else {
    //    Serial.println("Sucess");
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);

}

void loop() {
  // put your main code here, to run repeatedly:

  pox.update();
  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    //    Serial.print("Heart rate : ");
    float a = pox.getHeartRate();
    if (a > 0) {
      a = a - 0.5;
      Serial.print(a);
    }
    else {
      Serial.print(a);
    }

    Serial.print(" ");
    //    Serial.print("bpm / Spo2 : ");
    float b = pox.getSpO2();
    if (b > 0) {
      b = b - 0.5;
      Serial.println(b);
    } else {
      Serial.println(b);
    }

    //    Serial.println("%");

    tsLastReport = millis() - 100;
    ////    buzzer(a);
  }
}

//
//void buzzer(int bpm_val){
//  Serial.print(bpm_val);
//  if (bpm_val == 0) {
//      digitalWrite(6, HIGH);
//      delay(100);
//      digitalWrite(6, LOW);
//      delay(200);
//    }
//    else if (bpm_val < 30) {
//      digitalWrite(6, HIGH);
//      delay(100);
//      digitalWrite(6, LOW);
//      delay(100);
//    }
//    else if (bpm_val > 66 || bpm_val < 100) {
//      digitalWrite(6, HIGH);
//      delay(100);
//      digitalWrite(6, LOW);
//      delay(1000);
//    }
//  }
