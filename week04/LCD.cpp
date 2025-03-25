#include <Wire.h> 				      // I2C 통신 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h> 	// I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();	    	// I2C LCD 초기화
  lcd.backlight();	// 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(16, 0);
  lcd.print("Hello World!");
  
  for(int position = 0; position < 16; position++){
  	lcd.scrollDisplayLeft();
    delay(150);
  }
}
