#ifndef CHARLIEPLEXING_H
#define CHARLIEPLEXING_H
#include <Arduino.h>
#include <DFRobot_QMC5883.h>

class CharliePlexing {
  public:
    CharliePlexing(int input1, int input2, int input3);
    void init();
    void ledOn(int number);
    void levelStatus(int level);
    int TurnOnLeds();
    int frequency = 2000;

};
#endif
