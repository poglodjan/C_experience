#include <iostream>
using namespace std;
#include <time.h>
#include "card.h"
#include "history.h"
#include "pattern.h"

const int M=50;

int main()
{
    // __ PART 1 initializing __
    {
    card k1, k2(M);
    card k3(k2);
  
    k1=k3;
    cout<<"k1:"<<endl<<k1<<endl;
    cout<<"k2:"<<endl<<k2<<endl;
  
    k3(0,0) = element(14);
    k3.egg();
    cout<<"k3:"<<l3.size()<<endl<<k3<<endl;

    for(int i=0; i<M/10; i++)
      {
        int sx=rand()%M;
        k3+=pattern(sx, element(14));
      }
    k3.egg();
    cout<<"k3:"<<endl<<k3<<endl;
    }

  // __ PART 2 creating program with history __
  int pattern_color = 14;
  srand((unsigned)time(NULL));

  card p(M), empty(M);
  p.egg();
  history h(p);
  int k;

  do{
    cout<<p;
    cout<<"\nMENU:"<<endl;
    cout<<"1 - pattern"<<endl;
    cout<<"2 - egg"<<endl;
    cout<<"3 - undo"<<endl;
    cout<<"0 - end"<<endl;
    cout<<"Enter option:"<<endl;
    cin>>k;

    switch(k)
    {
      case 1:
        {
          for(int i=0;i<M/10;i++)
            p+=pattern(rand()%M, element(pattern_color));
          pattern_color--;
          if(pattern_color<8) pattern_color=14;

          p.egg()
          h.write(p);
        }
        break;
      case 2:
        {
          p = empty;
          p.egg();
          h.write(p);
          pattern_color=14;
          break;
        }
      case 3:
        p=h.undo();
        break;
    }
      
  }while(k!=0)

  return 0;
}






