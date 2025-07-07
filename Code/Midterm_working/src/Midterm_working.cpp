// // /* 
// //  * Project Encoder troubleshoot
// //  * Author: Kenneth
// //  * Date: 6_30
// //  * For comprehensive documentation and examples, please visit:
// //  * https://docs.particle.io/firmware/best-practices/firmware-template/
// //  */

// // // Include Particle Device OS APIs
#include "Particle.h"
#include <Encoder.h>
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"
#include "IoTClassroom_CNM.h"
#include "Button.h"
#include "Adafruit_BME280.h"

Encoder myEnc(D8,D9);
const int OLED_RESET=-1;
Adafruit_SSD1306 display(OLED_RESET);
Button encBut(D16);


int wemoNum;
int hueNum;
int menu;
int bright;
int color;
int encoderButt;

int newPosition;
void selection(int  menuNum);
void ALLOFF ();
// // Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);


void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display(); // show splashscreen
  delay(500);
  display.clearDisplay();
  pinMode(D16,INPUT_PULLDOWN);
  WiFi.on();
  WiFi.clearCredentials();
  WiFi.setCredentials("IoTNetwork");//logging into the network
  WiFi.connect();
    while(WiFi.connecting()){
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("Logging into\n the Network...\n");
      display.display();
    }
  display.printf("Connected\n Welcome to the show");
  display.display();
  delay(500);
  display.clearDisplay();
}
void loop(){
  newPosition = myEnc.read()/4.0;// Encoder configuration, divided by four to synch one choice per click
  if(newPosition<=0){
    newPosition=0;
  }
  Serial.printf("%i   ", newPosition);//tracking encoder
  Serial.printf("%i\n",encoderButt);//tracking encoder button press
  switch (menu){//menu configuration for navigation and status set 
    case 0: //menu 0, manual or automatic selection
    if (newPosition %2 ==0){ //MANUAL
      display.setTextSize(2);
      display.setTextColor(BLACK,WHITE);
      display.setCursor(0,0);
      display.printf("Manual\n");
      display.setTextColor(WHITE);
      display.printf("Automatic");
      selection(1);// if button is pushed jump to MENU1 
    } 
    if (newPosition %2 ==1){//AUTOMATIC
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.printf("Manual\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("Automatic");
      selection(7);
    }
    display.display(); //reverse clear, reduced flashing when placed here in code
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
      selection(2);
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
      selection(3);
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
      selection(4);
      }
    if (newPosition %4==3){//RETURN Selected
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.printf("WEMO\nHUE LIGHT\nALL\n");
      display.setTextSize(2);
      display.setTextColor(BLACK,WHITE);
      display.printf(" Return");
      selection(0);
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
      selection(5);
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
      selection(5);
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
      selection(5);
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
      selection(5);
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
      selection(5);
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
      selection(1);
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
      selection(6);
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
      selection(6);
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
      selection(6);
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
      selection(6);
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
      selection(6);
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
      selection(6);
    }
    if (newPosition %7==6){//return
      display.setCursor(0,0);
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.printf("HUE LIGHT\n1,2,3,4,5,6\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("Return");
      selection(1);
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
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        for(wemoNum=0;wemoNum<=5;wemoNum++){
          wemoWrite(wemoNum,HIGH);
        }
        for(hueNum=0;hueNum<=6;hueNum++){
        setHue(hueNum,true,0x008080,255,255);// chose a great color to turn on with max brightness
        delay(500);
        }
      }
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
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        for(wemoNum=0;wemoNum<=5;wemoNum++){
          wemoWrite(wemoNum,LOW);
        }
        for(hueNum=1;hueNum<=6;hueNum++){
        setHue(hueNum,false,0x008080,255,255);// chose a great color, max brightness, usually paired with all on
        delay(500);
        }
      }
      
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
      selection(1);
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
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        wemoWrite(wemoNum,HIGH);
      }
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
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        wemoWrite(wemoNum,LOW);
      }
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
      selection(2);
    }
    display.display();
    display.clearDisplay();
    break;

    case 6: //MENU 6 HUE configure
    if (newPosition %6==0){//Hue brightness configured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\n",hueNum);
      display.setTextColor(BLACK,WHITE);
      display.printf("Bright %i",bright);// need to set the encoder to be able to adjust brightness 
      display.setTextColor(WHITE);
      display.printf("\nColor  %i\nON/OFF\nENTER\nRETURN",color);
      if (encBut.isClicked()){
        Serial.printf("change bright");
      while(!encBut.isClicked()){
        display.clearDisplay();
        display.setCursor(0,0);
        bright = myEnc.read();
        if (bright>=260){
          bright = 255;
        }
        if(bright<0){
          bright=0;
        }
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.printf("HUE #%i\n",hueNum);
        display.setTextColor(BLACK,WHITE);
        display.printf("Bright %i",bright);// need to set the encoder to be able to adjust brightness 
        display.setTextColor(WHITE);
        display.printf("\nColor  %i\nON/OFF\nENTER\nRETURN",color);
        display.display();
      }
    }
    }
    if (newPosition %6==1){//Color configured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\nBright %i\n",hueNum,bright);
      display.setTextColor(BLACK,WHITE);
      display.printf("Color  %i",color); // need to set the encoder to be able to adjust color
      display.setTextColor(WHITE);
      display.printf("\nON/OFF\nENTER\nRETURN");
      if (encBut.isClicked()){
        Serial.printf("change color");
        while(!encBut.isClicked()){
          display.setCursor(0,0);
          display.setTextSize(1);
          display.setTextColor(WHITE);
          color = myEnc.read();
          color = color *180;
          display.printf("HUE #%i\nBright %i\n",hueNum,bright);
          display.setTextColor(BLACK,WHITE);
          display.printf("Color  %i",color); // need to set the encoder to be able to adjust color
          display.setTextColor(WHITE);
          display.printf("\nON/OFF\nENTER\nRETURN");
          if(color < 0){
            color = 0;
          }
          if(color > 65500){
            color = 65500;
          }
          display.display();
          display.clearDisplay();
        }
      }
    } 
    if (newPosition %6==2){//ONconfigured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\nBright %i\nColor  %i\n",hueNum,bright,color);
      display.setTextColor(BLACK,WHITE);
      display.printf("ON"); // need to set the encoder to be able to adjust color
      display.setTextColor(WHITE);
      display.printf("/OFF\nENTER\nRETURN");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        Serial.printf("color %i, bright %i\n",color,bright);
        setHue(hueNum,true,color,bright,255);
      }
    }
    if (newPosition %6==3){//OFFconfigured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\nBright %i\nColor  %i\nON/",hueNum,bright,color); 
      display.setTextColor(BLACK,WHITE);
      display.printf("OFF"); 
      display.setTextColor(WHITE);
      display.printf("\nENTER\nRETURN");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        setHue(hueNum,false,color,bright,255);
      }
    }
    if (newPosition %6==4){//ENTER configured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\nBright %i\nColor  %i\nON/OFF\n",hueNum,bright,color); 
      display.setTextColor(BLACK,WHITE);
      display.printf("ENTER"); 
      display.setTextColor(WHITE);
      display.printf("\nRETURN");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        Serial.printf("color %i, bright %i\n",color,bright);
        setHue(hueNum,true,color,bright,255);
      }
    }
    if (newPosition %6==5){//RETURN configured 
      display.setCursor(0,0);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.printf("HUE #%i\nBright %i\nColor  %i\nON/OFF\nENTER\n",hueNum,bright,color); 
      display.setTextColor(BLACK,WHITE);
      display.printf("RETURN"); 
      selection(3);
      }
    display.display();
    display.clearDisplay();
    break; 
    case 7: //Automatic functions 
    if(newPosition %6==0){//start presentation
      display.setCursor(0,0);
      // display.setTextSize(2); 
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("   Start Presentation");
      display.setTextColor(WHITE);
      display.printf("   Cont.Presentation\n   End Presentation\nMorning Glory\nTemperature Read\nReturn");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        ALLOFF();
        setHue(6, true, 10000,255,255);
        }
    }
    if(newPosition %6==1){//continue presentation
      display.setCursor(0,0);
      // display.setTextSize(2);
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n   Start Presentation");
      display.setTextColor(BLACK,WHITE);
      display.printf("   Cont. Presentation");
      display.setTextColor(WHITE);
      display.printf("   End Presentation\nMorning Glory\nTemperature Read\nReturn");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        for(hueNum=0;hueNum<=6;hueNum++){
          setHue(hueNum, true, 10000,255,255);
          delay(1000);
        }
        for(wemoNum=0;wemoNum<=5;wemoNum++){
          wemoWrite(wemoNum,HIGH);
        }
      }
    }
    if(newPosition %6==2){//end presentation
      display.setCursor(0,0);
      // display.setTextSize(2);
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n   Start Presentation   Cont. Presentation");
      display.setTextColor(BLACK,WHITE);
      display.printf("   End Presentation");
      display.setTextColor(WHITE);
      display.printf("\nMorning Glory\nTemperature Read\nReturn");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        ALLOFF();
      }
      
    }
    if(newPosition %6==3){//morning glory presentation 
      display.setCursor(0,0);
      // display.setTextSize(2);
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n   Start Presentation   Cont. Presentation   End Presentation\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("Morning Glory");
      display.setTextColor(WHITE);
      display.printf("\nTemperature Read\nReturn");
      encoderButt = digitalRead(D16);
      if (encoderButt==1){
        ALLOFF();
        for(bright=1; bright <=255; bright+=50){
          setHue(1, true, 3000, bright, 255);// bulb 1 to orange reddish
          setHue(2, true, 1000, bright, 255); //bulb 2 redwine kinda color 
          setHue(3, true, 8000, bright, 255); //bulb 3 to orange  
          setHue(4, true,10000, bright, 255); //bulb 4 to carrotish 
          setHue(5, true, 5000, bright, 255); //bulb 5 to red 
          setHue(6, true, 2000, bright, 255); //bulb 6 to peach  
          delay(3000);
          }
        for(wemoNum=0;wemoNum<=5;wemoNum++){
          wemoWrite(wemoNum,HIGH);  
        }   
      }
    }
    if(newPosition %6==4){ //code in temperature read function 
      display.setCursor(0,0);
      // display.setTextSize(2);
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n   Start Presentation   Cont. Presentation   End Presentation\nMorning Glory\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("Temperature Read");
      display.setTextColor(WHITE);
      display.printf("\nReturn");
    }
    if(newPosition %6==5){
      display.setCursor(0,0);
      // display.setTextSize(2);
      display.setTextColor(WHITE);
      // display.printf("AUTO\n");
      display.setTextSize(1);
      display.printf("Presentation\n   Start Presentation   Cont. Presentation   End Presentation\nMorning Glory\nTemperature Read\n");
      display.setTextColor(BLACK,WHITE);
      display.printf("Return");
      selection(0);
    }
    display.display();
    display.clearDisplay();
    break;
  }




}
// //functions 
void selection(int menuNum){
  encoderButt = digitalRead(D16);
     if (encoderButt==1){
      menu = menuNum;
      }
}
void ALLOFF(){
  for(wemoNum=0;wemoNum<=5;wemoNum++){   // set all lights to off
    wemoWrite(wemoNum,LOW);
  }
  for(hueNum=1;hueNum<=6;hueNum++){
    setHue(hueNum,false,0x008080,255,255);// chose a great color, max brightness, usually paired with all on
    delay(100);
    }
}
// }
  

  