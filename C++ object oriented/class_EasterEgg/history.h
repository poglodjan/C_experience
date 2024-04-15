#pragma once
#include "card.h"

class history
{
  static const int n=3;
  card h[n];
  int num;  // 1<=num<=n

public:
  history(const card& c);  // at the beginning we enter the current picture in the history
  
  void write(const card& c);
  card undo();
}
