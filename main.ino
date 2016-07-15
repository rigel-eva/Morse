// This #include statement was automatically added by the Particle IDE.
#include "morse.h"
String playback;
int button=D0;
int LED=D6;
bool play =false;
void setup() {
 pinMode(button,INPUT);
 pinMode(LED, OUTPUT);
 pinMode(D7, OUTPUT);
 Particle.function("morse", webMorse);
 Particle.function("replay",replay);
 webMorse("Online");
 digitalWrite(LED,LOW);
}

int webMorse(String text){
  play=true;
  playback=text;
  return 1;
}
int replay(String text){
  play=true;
}
void loop() {
  if(play){
    morse(LED,playback);
  }
  play=digitalRead(button)==LOW;
}
