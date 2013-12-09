#ifndef _MenuEntry_
#define _MenuEntry_

#include <Arduino.h>

#include "Adafruit_RGBLCDShield.h"

#define MENU_TIER   0x0
#define MENU_INPUT  0x1
#define MENU_OUTPUT 0x2

class MenuEntry {
  public:
    String name;
    MenuEntry *nextSibling;
    MenuEntry *prevSibling;
    MenuEntry *parent;

    MenuEntry(String name, MenuEntry *parent = NULL);

    virtual byte type() = 0;
    virtual MenuEntry* render(Adafruit_RGBLCDShield *lcd, boolean init = false) = 0;

  protected:
    byte pressedButton(Adafruit_RGBLCDShield *lcd);
    boolean buttonPressed;
};

#endif