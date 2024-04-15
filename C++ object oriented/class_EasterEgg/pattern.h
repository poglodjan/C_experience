#pragma once
#include "element.h"

class card;

class pattern
{
  int sx;
  element el;

public:
  pattern(int sx, element el);
  void paint(card& c) const; //draws a line pattern int the card table
}
