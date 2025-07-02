// /* 
//  * Project Encoder troubleshoot
//  * Author: Kenneth
//  * Date: 6_30
//  * For comprehensive documentation and examples, please visit:
//  * https://docs.particle.io/firmware/best-practices/firmware-template/
//  */

// // Include Particle Device OS APIs
#include "Particle.h"
#include <Encoder.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

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
// // Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);


void setup() {

  Serial.begin(9600);
  Serial.printf("Encoder test ");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display(); // show splashscreen
  delay(1000);
  display.clearDisplay();
  pinMode(D16,INPUT_PULLDOWN);
   

  }

// // loop() runs over and over again, as quickly as it can execute.
void loop(){



 newPosition = myEnc.read()/4.0;
 if(newPosition<=0){
  newPosition=0;
 }
Serial.printf("%i   ", newPosition);
Serial.printf("%i",encoderButt);
switch (menu){
  case 0: //menu 0, manual or automatic selection
  if (newPosition %2 ==0){ //MANUAL
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf("Manual\n");
    display.setTextColor(WHITE);
    display.printf("Automatic");
    encoderButt = digitalRead(D16);// if button is pushed jump to MENU1 
    if (encoderButt==1){
      menu = 1;
      }
   } 
  if (newPosition %2 ==1){//AUTOMATIC
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Manual\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("Automatic");
    // Menu to displayed later JUMP TO AUTOMATIC MENU
  }
  display.display();
  display.clearDisplay();
break;
  
case 1: // menu 1 MANUAL -WEMO, HUE, ALL, OR,RETURN Menu
  if (newPosition %4==0){//wemo selected
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf(" WEMO\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHTS\nALL\nRETURN");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 2;
      }
    }
  if (newPosition %4==1){//HUE LIGHT selected
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf("HUE LIGHT\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("ALL\nRETURN");
     encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 3;
      }
    }
  if (newPosition %4==2){//ALL selected
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\nHUE LIGHT\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf(" ALL\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("Return");
     encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 4;
      }  
    }
  if (newPosition %4==3){//RETURN Selected
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\nHUE LIGHT\nALL\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf(" Return");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 0;
      }
    }
display.display();
display.clearDisplay();
break; 

case 2: //MENU 2 Wemo selection 0-5 
  if (newPosition %6==0){//wemo 0
    wemoNum=0;
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf("0");    
    display.setTextColor(WHITE);
    display.printf(",1,2,4,5\nReturn");  
     encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 5;
      }
    }
  if (newPosition %6==1){//wemo 1
    wemoNum=1;
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("0,");
    display.setTextColor(BLACK,WHITE);
    display.printf("1");
    display.setTextColor(WHITE);
    display.printf(",2,4,5\nReturn");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 5;
      }
    }
  if (newPosition %6==2){ //wemo 2
    wemoNum=2;
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.printf("0,1,");
    display.setTextColor(BLACK,WHITE);
    display.printf("2");
    display.setTextColor(WHITE);
    display.printf(",4,5\nReturn");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 5;
      }
    }
  if (newPosition %6==3){//wemo 4
    wemoNum=4;
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.printf("0,1,2,");
    display.setTextColor(BLACK,WHITE);
    display.printf("4");
    display.setTextColor(WHITE);
    display.printf(",5\n");
    display.printf("Return");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 5;
      }
    }
  if (newPosition %6==4){//wemo 5
    wemoNum=5;
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.printf("0,1,2,4,"); 
    display.setTextColor(BLACK,WHITE);
    display.printf("5");
    display.setTextColor(WHITE);
    display.printf("\nReturn");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 5;
      }
    }
  if (newPosition %6==5){//RETURN
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("0,1,2,4,5\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("Return");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 1;
      }
      }
   display.display();
   display.clearDisplay();
break;

case 3: //MENU 3 HUE LIGHT selection 1-6
  if (newPosition %7==0){//HUE 1
    hueNum=1;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("1");
    display.setTextColor(WHITE);
    display.printf(",2,3,4,5,6\nReturn");
    }
  if (newPosition %7==1){//HUE 2
    hueNum=2;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,");
    display.setTextColor(BLACK,WHITE);
    display.printf("2");
    display.setTextColor(WHITE);
    display.printf(",3,4,5,6\nReturn");
    }
  if (newPosition %7==2){//HUE 3
    hueNum=3;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,2,");
    display.setTextColor(BLACK,WHITE);
    display.printf("3");
    display.setTextColor(WHITE);
    display.printf(",4,5,6\nReturn");
    }
  if (newPosition %7==3){//HUE 4
    hueNum=4;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,2,3,");
    display.setTextColor(BLACK,WHITE);
    display.printf("4");
    display.setTextColor(WHITE);
    display.printf(",5,6\nReturn");
  }
  if (newPosition %7==4){//HUE 5
    hueNum=5;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,2,3,4,");
    display.setTextColor(BLACK,WHITE);
    display.printf("5");
    display.setTextColor(WHITE);
    display.printf(",6\nReturn");
  }
  if (newPosition %7==5){//HUE 6
    hueNum=6;
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,2,3,4,5,");
    display.setTextColor(BLACK,WHITE);
    display.printf("6");
    display.setTextColor(WHITE);
    display.printf(",\nReturn");
  }
  if (newPosition %7==6){//return
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHT\n1,2,3,4,5,6\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("Return");
  }
  display.display();
  display.clearDisplay();
break;

//case 5: //Menu 5 Wemo # ON/OFF RETURN
  if (newPosition %3 ==0){//wemo on
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextColor(BLACK,WHITE);
    display.printf("ON");
    display.setTextColor(WHITE);
    display.printf("/OFF\nReturn");
    }
  if (newPosition %3 ==1){//wemo off
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextColor(WHITE);
    display.printf("ON/");
    display.setTextColor(BLACK,WHITE);
    display.printf("OFF");
    display.setTextColor(WHITE);
    display.printf("\nReturn");
    }
  if (newPosition %3 ==2){//RETURN
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("ON/OFF");
    display.setTextColor(BLACK,WHITE);
    display.printf("\nReturn");
    }
    display.display();
    display.clearDisplay();
break;

case 4: //MENU 4 ALL ON/OFF/RETURN
  if (newPosition %3 ==0){//ALL on 
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("ALL\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf("ON");
    display.setTextColor(WHITE);
    display.printf("/OFF\nReturn");
    }
  if (newPosition %3 ==1){//ALL OFF 
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("ALL\n");
    display.setTextSize(2);
    display.printf("ON/");
    display.setTextColor(BLACK,WHITE);
    display.printf("OFF");
    display.setTextColor(WHITE);
    display.printf("\nReturn");
    }
  if (newPosition %3 ==2){//ALL RETURN
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("ALL\n");
    display.setTextSize(2);
    display.printf("ON/OFF\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("RETURN");
    }
  display.display();
  display.clearDisplay();
break;

case 5: //Menu 5 WEMO ON/OFF return 
  if (newPosition %3 ==0){//wemo on 
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextColor(BLACK,WHITE);
    display.printf("ON");
    display.setTextColor(WHITE);
    display.printf("/OFF\nReturn");
    }
  if (newPosition %3 ==1){//wemo off
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextColor(WHITE);
    display.printf("ON/");
    display.setTextColor(BLACK,WHITE);
    display.printf("OFF");
    display.setTextColor(WHITE);
    display.printf("\nReturn");
    }
  if (newPosition %3 ==2){ //RETURN
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("Wemo %i\n", wemoNum);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("ON/OFF");
    display.setTextColor(BLACK,WHITE);
    display.printf("\nReturn");
    encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = 2;
      }
    }
    display.display();
    display.clearDisplay();
break;
//HUE lights selection menu 4

case 6: //MENU 6 HUE configure
  if (newPosition %5==0){//Hue brightness configured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE #%i\n",hueNum);
    display.setTextColor(BLACK,WHITE);
    display.printf("Bright %i",bright);// need to set the encoder to be able to adjust brightness 
    display.setTextColor(WHITE);
    display.printf("\nColor  %i\nON/OFF\nRETURN",color);
    }
  if (newPosition %5==1){//Color configured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE #%i\nBright %i\n",hueNum,bright);
    display.setTextColor(BLACK,WHITE);
    display.printf("Color  %i",color); // need to set the encoder to be able to adjust color
    display.setTextColor(WHITE);
    display.printf("\nON/OFF\nRETURN");
    }
  if (newPosition %5==2){//ONconfigured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE #%i\nBright %i\nColor  %i\n",hueNum,bright,color);
    display.setTextColor(BLACK,WHITE);
    display.printf("ON"); // need to set the encoder to be able to adjust color
    display.setTextColor(WHITE);
    display.printf("/OFF\nRETURN");
  }
  if (newPosition %5==3){//OFFconfigured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE #%i\nBright %i\nColor  %i\nON/",hueNum,bright,color); 
    display.setTextColor(BLACK,WHITE);
    display.printf("OFF"); // need to set the encoder to be able to adjust color
    display.setTextColor(WHITE);
    display.printf("\nRETURN");
  }
  if (newPosition %5==4){//RETURN configured 
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE #%i\nBright %i\nColor  %i\nON/OFF\n",hueNum,bright,color); 
    display.setTextColor(BLACK,WHITE);
    display.printf("RETURN"); 
   }
    display.display();
    display.clearDisplay();
break;



}
}