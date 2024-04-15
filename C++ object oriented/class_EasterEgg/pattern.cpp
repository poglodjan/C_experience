#include "pattern.h"
#include "card.h"

pattern::pattern(int sx, element el)
{
  this->sx = sx;
  this->el = el;
}

void pattern::paint(card& c) const
{
  for(int j=0; j<c.size(); j+=2)
    c(sx,j) = el;
}
