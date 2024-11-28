#include "display.h"
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);
void Display::init()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void Display::show()
{
    lcd.setCursor(0, 0);
    lcd.print("Smart Fishpond");
    lcd.setCursor(0, 1);
    lcd.print("IF ITERA");
    delay(1000);
    showLoading();
}
void Display::show(float data)
{

    if (currentDisplay == READ_PH)
    {
        lcd.setCursor(0, 0);
        lcd.print("Membaca pH");
        lcd.setCursor(0, 1);
        lcd.print("pH : ");
        lcd.print(data);
    }
    else if (currentDisplay == FEEDING)
    {
        lcd.setCursor(0, 0);
        lcd.print("Memberi Makan");
        lcd.setCursor(0, 1);
        lcd.print("Progress : ");
        lcd.print(data);
        lcd.print("%");
    }
}
void Display::show(float data1, float data2)
{
    lcd.setCursor(0, 0);
    lcd.print("Time : ");
    lcd.print("12:23:2");
    lcd.setCursor(0, 1);
    lcd.print("Server : ");
    lcd.print("Aktif");
}
void Display::showLoading()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Loading...    ");
}
void Display::setDisplay(DisplayType dp)
{
    currentDisplay = dp;
}
void Display::clearDisplay()
{
    lcd.clear();
}