/* 
 * Project Encoder troubleshoot
 * Author: Kenneth
 * Date: 6_30
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include <Encoder.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

Encoder myEnc(D8,D9);
const int OLED_RESET=-1;
Adafruit_SSD1306 display(OLED_RESET);
int menu;
int encoderButt;

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);


void setup() {

  Serial.begin(9600);
  Serial.printf("Encoder test ");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();
  pinMode(D17,INPUT);
   

}
long oldPosition = -999;
// loop() runs over and over again, as quickly as it can execute.
void loop(){
 long newPosition = myEnc.read();
if (newPosition != oldPosition)
{
  oldPosition = newPosition;
}
switch (menu){
  case 0: //menu 0, manual or automatic selection
  if (newPosition %2 ==0){
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf("Manual\n");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("Automatic");
    display.display();
    encoderButt = digitalRead(D17);// if button is pushed jump to menu 1
    if (encoderButt==1){
      menu 1;
    }    
    display.clearDisplay();
  }
  if (newPosition %2 !=0){
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Manual\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf("Automatic");
    // Menu to displayed later 
    display.display();
    display.clearDisplay();
  }
  break;
  
  case 1:
  if (newPosition %4 ==0){
    display.setTextSize(1);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("ALL\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("Return\n");
    display.display();
  }
  if (newPosition %4 ==1){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(1);
    display.setTextColor(BLACK,WHITE);
    display.printf("HUE\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("ALL\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("Return\n");
    display.display();    
  }
  if (newPosition %4 ==2){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(BLACK,WHITE);
    display.printf("ALL\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("Return\n");
    display.display();
  }
    if (newPosition %4 ==3){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("ALL\n");
    display.display();
    display.setTextSize(1);
    display.setTextColor(BLACK,WHITE);
    display.printf("Return\n");
    display.display();
}
}
}

// if (newPosition != oldPosition)
// {
//   oldPosition = newPosition;
//   Serial.printf("%i\n",newPosition);
//   display.setTextSize(1);
//   display.setTextColor(WHITE);
//   display.setCursor(0,0);
//   display.printf("%i\n",newPosition);
//   display.display();
//   display.clearDisplay();


//   if (newPosition %2 == 0){
//   Serial.printf("Even %i \n" ,newPosition);
// }
// else {
//   Serial.printf("odd %i \n",newPosition);
//   display.printf("%i\n",newPosition);
//   display.display();
//   display.clearDisplay();





// if (newPosition %2 == 0){
//   Serial.printf("Even %i \n" ,newPosition);
// }
// else {
//   Serial.printf("odd %i \n" ,newPosition);
// }




