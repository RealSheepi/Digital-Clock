#include <Wire.h> 

#define RTCPCF8523 

#ifdef RTCDS3231
  #include <RTClib.h>
  RTCDS3231 rtc; 


#elif defined(RTC_PCF8523)
  #include <DS1307.h>
  DS1307 rtc(0x68); 

#endif

const int lcdRS = 12, lcdE = 11, lcdD4 = 5, lcdD5 = 4, lcdD6 = 3, lcdD7 = 2;
LiquidCrystal lcd(lcdRS, lcdE, lcdD4, lcdD5, lcdD6, lcdD7);



void setup() {
  lcd.begin(16, 2);
  Wire.begin();
  rtc.begin();
}



void loop() {
  DateTime now = rtc.now();

  String formattedTime = now.format("%H:%M:%S");



  String formattedDate = now.format("%d/%m/%Y");

  lcd.setCursor(0, 0);
  lcd.print(formattedTime);



  lcd.setCursor(0, 1);
  lcd.print(formattedDate);

  delay(1000);
}
