#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
 
TMRpcm tmrpcm;   // create an object for use in this sketch
int SW1; 
boolean isPlaying = false;

void setup(){
 Serial.begin(9600);
 Serial.print("Logging");
 pinMode(14,INPUT);  //Define A0 as digital input.
 digitalWrite(14,HIGH);
 
 tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
 if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
 Serial.print("SD card not initialised"); 
 return;   // don't do anything more if not
 }
 tmrpcm.volume(1);
 tmrpcm.play("1.wav"); //the sound file "1" will play each time the arduino powers up, or is reset
}
 
void loop(){  
  SW1=digitalRead(14);
  
 if (SW1 == LOW) { //if SW1 pressed then play file "6.wav"
  if(isPlaying){
    tmrpcm.disable();
    }
  else{
    tmrpcm.play("wn.wav");
    }
 isPlaying = !isPlaying;   
 }
  delay(1000);
}
