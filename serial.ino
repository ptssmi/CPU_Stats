// Serial test script
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


String InBytes;

void setup()
{

  Serial.begin(115200);  // initialize serial communications at 9600 bps
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
}

void loop()
{
  
  // // serial read section
  if (Serial.available()>0){
    InBytes = Serial.readStringUntil('\n');
  }
      String temp = InBytes.substring(0,2);
      String power = InBytes.substring(2,6);
      String usage = InBytes.substring(6,8);
      display.clearDisplay();
      display.setTextSize(2);             
      display.setTextColor(WHITE);        
      display.setCursor(0,0);             
      display.println("Temp: " + temp);
      display.println("Usage:" + usage + "%");
      display.println("Power:" + power);
      display.display();

}
