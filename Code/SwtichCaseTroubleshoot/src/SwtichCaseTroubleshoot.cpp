/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "encoder.h"


// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

int menu;

void setup() {
  // Im trying to figure out the logic to use in switch cases. used for menu selection with smart device
  //encoder is used to navigate and select values for menu  

}
void loop() {
  //enocder is set to odd and even, even set to manual odd is set to automatic 
  switch (menu)
  {
  case 0:
    if (myEnc) encoder is set to even (%=0)
    //serial print Manual highlighted with reverse text 
    //print automatic not highlighted 

    //if encoder is set to Even (%=0) && switch is pressed 
      //serial print 1. wemo
      //serial print 2. Hue
      //serial print 3. All

  
    
    break;

  case automatic: 
    //If encoder is set to automatic 
    //print manual not highlighted 
    //print automatic highlighted 
  
  default:
    break;
  }
}
 if 