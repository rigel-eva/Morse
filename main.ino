// This #include statement was automatically added by the Particle IDE.
#include "morse.h"
String replay;
int button=D1;
int LED=D6;
bool toggle=FALSE;
void setup() {
 pinMode(button,INPUT);
 pinMode(LED, OUTPUT);
 pinMode(D7, OUTPUT);
 Particle.function("morse", webMorse);
 webMorse("Online");
 digitalWrite(LED,LOW);
}

int webMorse(String text){
  if(text==""){
    return morse(LED,replay);
  }
  replay=text;
  return morse(LED,text);
}
void loop() {
  if(digitalRead(button)==LOW){
    webMorse("");
  }
}
