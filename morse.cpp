#include "application.h"
using namespace std;
const int pelay=75;
void beeper(int pin, bool pLong, int num){
    //if(num==0){
    //    morse(pin,pLong,num-1);
    //}
    for(int i=0; i<num; i++){
        if(pLong){
            digitalWrite(pin, 1);
            delay(pelay*3);
            digitalWrite(pin, 0);
            delay(pelay);
        }
        else{
            digitalWrite(pin, 1);
            delay(pelay);
            digitalWrite(pin, 0);
            delay(pelay);
        }
    }
}
void beeper(int pin, bool pLong){
    beeper(pin,pLong,1);
}
int morse(int pin, String t, int location){
  if(location==0){
    t=t.toLowerCase();
  }
    if (location>=t.length()){
      return 0;
    }
    switch(t[location]){
        case 'a':
          beeper(pin, false);
          beeper(pin, true);
          break;
        case 'b':
          beeper(pin, true);
          beeper(pin, false, 3);
          break;
        case 'c':
          beeper(pin, true);
          beeper(pin, false);
          beeper(pin, true);
          beeper(pin, false);
          break;
        case 'd':
          beeper(pin,true);
          beeper(pin,false,2);
          break;
        case 'e':
          beeper(pin,false);
          break;
        case 'f':
          beeper(pin, false, 2);
          beeper(pin, true);
          beeper(pin, false);
          break;
        case 'g':
          beeper(pin, true, 2);
          beeper(pin, false);
          break;
        case 'h':
          beeper(pin, false, 4);
          break;
        case 'i':
          beeper(pin, false, 2);
          break;
        case 'j':
          beeper(pin, false);
          beeper(pin, true, 3);
          break;
        case 'k':
          beeper(pin, true);
          beeper(pin, false);
          beeper(pin, true);
          break;
        case 'l':
          beeper(pin, false);
          beeper(pin, true);
          beeper(pin, false, 2);
          break;
        case 'm':
          beeper(pin, true, 2);
          break;
        case 'n':
          beeper(pin, true);
          beeper(pin, false);
          break;
        case 'o':
          beeper(pin, true, 3);
          break;
        case 'p':
          beeper(pin, false);
          beeper(pin, true, 2);
          beeper(pin, false);
          break;
        case 'q':
          beeper(pin, true, 2);
          beeper(pin, false);
          beeper(pin, true);
          break;
        case 'r':
          beeper(pin, false);
          beeper(pin, true);
          beeper(pin, false);
          break;
        case 's':
          beeper(pin, false, 3);
          break;
        case 't':
          beeper(pin, true);
          break;
        case 'u':
          beeper(pin, false, 2);
          beeper(pin, true);
          break;
        case 'v':
          beeper(pin, false, 3);
          beeper(pin, true);
          break;
        case 'w':
          beeper(pin, false);
          beeper(pin, true, 2);
          break;
        case 'x':
          beeper(pin, true);
          beeper(pin, false, 2);
          beeper(pin, true);
          break;
        case 'y':
          beeper(pin, true);
          beeper(pin, false);
          beeper(pin, true, 2);
          break;
        case 'z':
          beeper(pin, true, 2);
          beeper(pin, false, 2);
          break;
        default:
          delay(pelay*2);
          break;
    }
    delay(pelay);
    return morse(pin, t, location+1);
}
int morse(int pin, String t){
  morse(pin,t,0);
}
