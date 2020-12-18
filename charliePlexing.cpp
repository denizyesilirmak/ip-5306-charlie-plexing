#include "charliePlexing.h"

/*
        D0   D1   D2
        +    +    +
        |    |    |
        |    |    |
+-------+    |    +---+
|            |        |
|       +----+        |
|       |             |
|       |             |
|  +--+ | +--+   +--+ | +--+
+--+L1+-+-+L2+-+-+L3+-+-+L4+---+
|  +--+   +--+ | +--+   +--+   |
|              |               |
|              |               |
+--------------+---------------+

*/

CharliePlexing::CharliePlexing(int input1, int input2, int input3) {
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
}

void CharliePlexing::ledOn(int number) {
  if (number == 1) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH);
  }
  else if (number == 2) {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);

  }
  else if (number == 3) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
  }
  else if (number == 4) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
  else if (number == 0) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}

void CharliePlexing::levelStatus(int level) {
  if (level <= 25) {
    ledOn(1);
    delayMicroseconds(frequency);
  }
  if (level <= 50 && level > 25) {
    ledOn(1);
    delayMicroseconds(frequency);
    ledOn(0);
    delayMicroseconds(frequency);
    ledOn(2);
    delayMicroseconds(frequency);
    ledOn(0);
    delayMicroseconds(frequency);
  }
  if (level <= 75 && level > 50) {
    ledOn(1);
    delayMicroseconds(frequency);
    ledOn(2);
    delayMicroseconds(frequency);
    ledOn(3);
    delayMicroseconds(frequency);
  }
  if (level <= 100 && level > 75) {
    ledOn(1);
    delayMicroseconds(frequency);
    ledOn(2);
    delayMicroseconds(frequency);
    ledOn(3);
    delayMicroseconds(frequency);
    ledOn(4);
    delayMicroseconds(frequency);
  }
}
