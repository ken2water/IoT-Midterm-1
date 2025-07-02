/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include <Encoder.h>
#include "Adafruit_SSD1306.h"
// //#include "Adafruit_GFX.h"
// #include "IoTClassroom_CNM.h"

 

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

Encoder myEnc(D8,D9);
const int OLED_RESET=-1;
Adafruit_SSD1306 display(OLED_RESET);


int wemoNum;
int hueNum;
int menu;
int bright;
int color;
int encoderButt;
int newPosition;
// void selection(int  menuNum);

// // Let Device OS manage the connection to the Particle Cloud



void setup() {

  Serial.begin(9600);
   Serial.printf("Encoder test ");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display(); // show splashscreen
  delay(500);
  display.clearDisplay();
  pinMode(D16,INPUT_PULLDOWN);
  WiFi.on();
    WiFi.clearCredentials();
    WiFi.setCredentials("IoTNetwork");
    WiFi.connect();
    while(WiFi.connecting()){
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("WE ARE WAITING\n");
      display.display();
    }
    display.printf("Connected");
    display.display();
    display.clearDisplay();
   

  }

// loop() runs over and over again, as quickly as it can execute.
void loop() {
 

   // if (newPosition %5==0){//Hue brightness configured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);


    bright = myEnc.read();

    display.printf("%i",bright);
}

//     display.printf("HUE #%i\n",hueNum);
//     display.setTextColor(BLACK,WHITE);
//     display.printf("Bright %i",bright);// need to set the encoder to be able to adjust brightness 
//     display.setTextColor(WHITE);
//     display.printf("\nColor  %i\nON/OFF\nRETURN",color);
//     encoderButt = digitalRead(D16);
//      if (encoderButt==1){
//       bright = myEnc.read();
//       }
// }
// //  // if (newPosition %5==1){//Color configured 
// //     display.setCursor(0,0);
// //     display.setTextSize(1);
// //     display.setTextColor(WHITE);
// //     display.printf("HUE #%i\nBright %i\n",hueNum,bright);
// //     display.setTextColor(BLACK,WHITE);
// //     display.printf("Color  %i",color); // need to set the encoder to be able to adjust color
// //     display.setTextColor(WHITE);
// //     display.printf("\nON/OFF\nRETURN");
// //     }
// //   if (newPosition %5==2){//ONconfigured 
// //     display.setCursor(0,0);
// //     display.setTextSize(1);
// //     display.setTextColor(WHITE);
// //     display.printf("HUE #%i\nBright %i\nColor  %i\n",hueNum,bright,color);
// //     display.setTextColor(BLACK,WHITE);
// //     display.printf("ON"); // need to set the encoder to be able to adjust color
// //     display.setTextColor(WHITE);
// //     display.printf("/OFF\nRETURN");
// //   }
// //   if (newPosition %5==3){//OFFconfigured 
// //     display.setCursor(0,0);
// //     display.setTextSize(1);
// //     display.setTextColor(WHITE);
// //     display.printf("HUE #%i\nBright %i\nColor  %i\nON/",hueNum,bright,color); 
// //     display.setTextColor(BLACK,WHITE);
// //     display.printf("OFF"); // need to set the encoder to be able to adjust color
// //     display.setTextColor(WHITE);
// //     display.printf("\nRETURN");
// //   }
// //   if (newPosition %5==4){//RETURN configured 
// //     display.setCursor(0,0);
// //     display.setTextSize(1);
// //     display.setTextColor(WHITE);
// //     display.printf("HUE #%i\nBright %i\nColor  %i\nON/OFF\n",hueNum,bright,color); 
// //     display.setTextColor(BLACK,WHITE);
// //     display.printf("RETURN"); 
// //     selection(3);
// //    }
// //     display.display();
// //     display.clearDisplay();

// // }
// case 7
// if(newPosition%2==0)
//     display.setCursor(0,0);
//     display.setTextSize(2);
//     display.setTextColor(WHITE);
//     display.print("Value is %i",bright)
//     bright = myEnc.read()
