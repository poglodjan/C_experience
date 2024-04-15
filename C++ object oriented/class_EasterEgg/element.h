#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

class element;
{
  char sign;
  char color;
public:
  element(int color=0, char sign='*'):sign(sign), color(color){}

  friend ostream& operator<<(ostream& out, const element& e)
  {
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hconsole, e.color);
    out<<e.sign;

    SetConsoleTextAttribute(hconsole,15);
    return out;
  }
}
