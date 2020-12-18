#include "charliePlexing.h"
int analogLevel = 0;

//create Charlie Plexing instance with digital inputs given as parameters
CharliePlexing cp(8,9,10);

void setup() {


}

void loop() {
  //Simple demo
  analogLevel = analogRead(A0);
  cp.levelStatus(map(analogLevel,0,1023,0,100));

}
