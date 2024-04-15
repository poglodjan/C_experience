#include "history.h"

history::history(const card& c)
{
  h[0] = c;
  num = 1;
}

void history::write(const card& c)
{
  if(num!=n)
  {
    h[num] = c;
    num++;
  }
  else
  {
    for(int i=0; i<n-1; i++)
    {
      h[i] = h[i+1]; 
    }
    h[n-1] = c;
  }
}

card history::undo()
{
  num--;
  return h[num-1];
}
