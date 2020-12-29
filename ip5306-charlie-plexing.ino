#include <ChuckPlex.h>
#define LED_1 3
#define LED_2 1
#define LED_3 5
#define LED_4 2

int pins[] = {6, 3, 5};
int nodes = 6;
ChuckPlex plex = ChuckPlex(pins, 3);
int batteryValue = 0;
int breatheInterval = 50;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 300;
boolean direction = false;

void setup()
{
  GreetUser();
}

void loop()
{
  batteryValue = analogRead(A0);
  ledControl(map(batteryValue, 0, 1024, 344, 500), true);
}

void ledControl(int batteryLevelAdc, boolean isCharging)
{
  if (isCharging)
  {
    if ((millis() - lastDebounceTime) >= debounceDelay) {
      direction = ! direction;
      lastDebounceTime = millis();
    }

    if (batteryLevelAdc < 368 && batteryLevelAdc >= 344)
    {
      if (direction)
        plex.enable(LED_1);
      else
        plex.clear();
    }
    else if (batteryLevelAdc < 397 && batteryLevelAdc >= 368)
    {
      plex.enable(LED_1); // 1.led
      if (direction)
        plex.enable(LED_2); // 2.led
    }
    else if (batteryLevelAdc < 423 && batteryLevelAdc >= 397)
    {
      plex.enable(LED_1);    // 1.led
      if (!direction)
        plex.write(LED_2, 128);
      else
        plex.write(LED_2, 255);

      if (direction)
        plex.write(LED_3, 8);


    }
    else if (batteryLevelAdc < 452 && batteryLevelAdc >= 423)
    {
      plex.enable(LED_1);    // 1.led
      plex.enable(LED_2);    // 2.led
      if (!direction)
        plex.write(LED_3, 10);
      else
        plex.write(LED_3, 255);
      if (direction)
        plex.write(LED_4, 32);
    }
    else if (batteryLevelAdc >= 452)
    {
      plex.enable(LED_1);    // 1.led
      plex.enable(LED_2);    // 2.led
      plex.enable(LED_3);    // 3.led
      plex.write(LED_4, 10); // 4.led  //last two leds brighter!
    }

  }
  else
  {
    //battery usage
    if (batteryLevelAdc < 344)
    {
      // Dangerous battery level, abort
      plex.clear();
      return;
    }
    else if (batteryLevelAdc < 354 && batteryLevelAdc >= 344)
    {
      FadeInOut(LED_1, 10, 30); // 1.led fade in and out.
    }
    else if (batteryLevelAdc < 368 && batteryLevelAdc >= 354)
    {
      plex.enable(LED_1); // 1.led static
    }
    else if (batteryLevelAdc < 397 && batteryLevelAdc >= 368)
    {
      plex.enable(LED_1); // 1.led
      plex.enable(LED_2); // 2.led
    }
    else if (batteryLevelAdc < 423 && batteryLevelAdc >= 397)
    {
      plex.enable(LED_1);    // 1.led
      plex.enable(LED_2);    // 2.led
      plex.write(LED_3, 8); // 3.led //last two leds brighter!
    }
    else if (batteryLevelAdc < 452 && batteryLevelAdc >= 423)
    {
      plex.enable(LED_1);    // 1.led
      plex.enable(LED_2);    // 2.led
      plex.enable(LED_3);    // 3.led
      plex.write(LED_4, 10); // 4.led  //last two leds brighter!
    }
    else
    {
      plex.clear();
    }
  }
}

void GreetUser()
{
  int leds[4] = {3, 1, 5, 2};
  for (int t = 0; t < 4; t++)
  {
    for (int i = 1; i <= 16; i++)
    {
      plex.write(leds[t], i * i - 1);
      delay(10);
    }
    for (int i = 16; i >= 1; i--)
    {
      plex.write(leds[t], i * i - 1);
      delay(5);
    }
  }
  for (int t = 2; t >= 0; t--)
  {
    for (int i = 1; i <= 16; i++)
    {
      plex.write(leds[t], i * i - 1);
      delay(10);
    }
    for (int i = 16; i >= 1; i--)
    {
      plex.write(leds[t], i * i - 1);
      delay(5);
    }
  }
}

void FadeInOut(int ledNumber, int fadeSpeed, int fadeDelay)
{
  for (int i = 1; i <= 16; i++)
  {
    plex.write(ledNumber, i * i - 1);
    delay(fadeSpeed);
  }
  delay(fadeDelay);
  for (int i = 16; i >= 1; i--)
  {
    plex.write(ledNumber, i * i - 1);
    delay(fadeSpeed);
  }
}
