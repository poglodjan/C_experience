#pragma once
using namespace std;
#include "element.h"

class pattern;

class card
{
  element* t;  // a dynamic m*m array representing a square array
  int m;

  void init(int _m, element el, element* tab=nullptr);
public:

  card() : t(nullptr), m(0){}
  card(int m, element el=element(2));
  card(const card& k);
  ~card(){ delete [] t; }
  
  card& operator=(const card& c);
  card& operator+=(const pattern& g);

  element operator()(int i, int j) const;
  element& operator operator()(int i,int j);

  int size() const; //returns size of the array
  void egg(element el=element());
  
  friend ostream& operator<<(ostream& out, const card& k);
}
