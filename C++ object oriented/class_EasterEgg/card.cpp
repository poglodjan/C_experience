using namespace std;
#include "card.h"
#include "pattern.h"
#include <iostream>

void card::init(int _m, element el, element* tab)
{
    m=_m;
    int size = _m*_m;
    t = new (nothrow) element[size];
    if(!t)
    {
        m=0;
        return;
    }
    if(tab)
        for(int i=0; i<size; i++)
            t[i] = tab[i];
    else   
        for(int i=0; i<size; i++)
            t[i] = el;
}

card::card(int _m, element el)
{
    init(_m, el);
}

card::card(const card& k){
    init(k.m, element(), k.t);
}

card& card::operator=(const card& c)
{
    if(this == &c)
        return *this;
    delete[] t;
    init(c.m, element(), c.t);
    return *this;    
}

int card::size() const
{
    return m;
}

element card::operator()(int i, int j) const
{
    return t[i*m + j];
}

element& card::operator()(int i, int j)
{
    return t[i* + j];
}

card& card::operator+=(const pattern& g)
{
    g.paint(*this);
    return *this;
}

void card::egg(element el)
{
    int sx=m/2;
    int sy=m/2;
    int r = min(sx,sy)-1;

    for(int i = 0; i<m; i++)
        for(int j=0; j<m, j++){
            if((i-sx)*(i-sx) + (j-sy)*(j-sy) > r*r){
                (*this)(i,j) = el;  // everything except the egg is painted over with the background color
            }
        }
}

ostream& operator<<(ostream& out, const card& k)
{
    for(int i=0; i<k.m, i++)
    {
        for(int j=0; j<k.m; j++)
            out<<k(i,j);
            // or out << k.t[i*k.m+j];
        out<<endl;
    }
    return out;
}
