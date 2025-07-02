/* 
 * Project Completed Menus need troubleshoting
 * Author: Kenneth 
 * Date: 7-1
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
void setup() {
  // Put initialization like pinMode and begin functions here
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  //Menu 0 choice Manual
    case 0: //menu 0, manual or automatic selection
  if (newPosition %2 ==0){ //MANUAL
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf("Manual\n");
    display.setTextColor(WHITE);
    display.printf("Automatic");
   
                  // encoderButt = digitalRead(D17);// if button is pushed jump to MENU1 
                  // if (encoderButt==1){
                  //   menu = 1;
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
 // case 1: // Manual menu 1 WEMO HUE or ALL and RETURN Menu


  if (newPosition %4==0){
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.setCursor(0,0);
    display.printf(" WEMO\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("HUE LIGHTS\nALL\nRETURN");
    }
  if (newPosition %4==1){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf(" HUE LIGHT\n");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.printf("ALL\nRETURN");

  }
  if (newPosition %4==2){
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
  }
    if (newPosition %4==3){
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.printf("WEMO\nHUE LIGHT\nALL\n");
    display.setTextSize(2);
    display.setTextColor(BLACK,WHITE);
    display.printf(" Return");
   
}
 display.display();
display.clearDisplay();


 //Menu 2 wemo selection 
  if (newPosition %6==0){
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
    wemoNum=0;
 }

  if (newPosition %6==1){
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

  
 }
  if (newPosition %6==2){
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

 }
  if (newPosition %6==3){
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


 }
  if (newPosition %6==4){
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
 
  }
    if (newPosition %6==5){
    display.setCursor(0,0);
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.printf("WEMO\n");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.printf("0,1,2,4,5\n");
    display.setTextColor(BLACK,WHITE);
    display.printf("Return");

 }
 display.display();
 display.clearDisplay();

 Case 4: //MENU 4 ALL ON/OFF/RETURN
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

 // case 5: //Menu 5 WEMO ON/OFF return 
//   if (newPosition %3 ==0){//wemo on 
//     display.setTextSize(2);
//     display.setTextColor(WHITE);
//     display.setCursor(0,0);
//     display.printf("Wemo %i\n", wemoNum);
//     display.setTextColor(BLACK,WHITE);
//     display.printf("ON");
//     display.setTextColor(WHITE);
//     display.printf("/OFF\nReturn");
//     }
//   if (newPosition %3 ==1){//wemo off
//     display.setTextSize(2);
//     display.setTextColor(WHITE);
//     display.setCursor(0,0);
//     display.printf("Wemo %i\n", wemoNum);
//     display.setTextColor(WHITE);
//     display.printf("ON/");
//     display.setTextColor(BLACK,WHITE);
//     display.printf("OFF");
//     display.setTextColor(WHITE);
//     display.printf("\nReturn");
//     }
//   if (newPosition %3 ==2){ //RETURN
//     display.setTextSize(2);
//     display.setTextColor(WHITE);
//     display.setCursor(0,0);
//     display.printf("Wemo %i\n", wemoNum);
//     display.setTextSize(2);
//     display.setTextColor(WHITE);
//     display.printf("ON/OFF");
//     display.setTextColor(BLACK,WHITE);
//     display.printf("\nReturn");
//     }
//     display.display();
//     display.clearDisplay();
// break;

//case 6: //MENU 6 HUE configure
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
