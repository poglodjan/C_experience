// 1) abstrakcja - kazdy obiekt traktujemy abstrakcyjnie - wykonawca wprowadza zmiany (stan, akcje, komunikacje)
// bez ujawniania w jaki sposob zaimplementowano cechy 

// 2) hermetyzacja - obiekt nie zmienia stanu wewnętrznego innych obiektow w nieprzewidziany sposob.
// jedynie jego wlasne metody są uprawnione do zmian stanu

// 3) dziedziczenie - tworzenie hierarchii obiektow na podstawie juz wczesniej zdefiniowanych ogolnych obiektow.

// 4) polimorfizm statyczny - przeciązenie operatorow, funkcji.
// polimorfizm dynamiczny - metody wirtualne

#include <iostream>
#include "header.h"
using namespace std;

void swap_p(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(const int N, int a[10])
{
    for(int i=0;i<(N-1);i++)
    {
        int min_idx = i;
        for(int j=i+1; j<N;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx>i)
        {
            swap_p(&a[i],&a[min_idx]);
        }
    }
}


int main() 
{
    // 1) selection sort algorithm
    const int N = 10;
    int a[10] = {52, 1, 12, 16, 99, 1002,
        2001, 0, 79, 99};

    selection_sort(N, a);

    for (int i = 0; i < N; i++)
    {
        cout << i << " " << a[i] << endl;
    }

    // 2) printing functions
    int l=-355;
    cout<<l<<endl;
    cout.width(10);
    cout<<left<<l<<l<<l<<endl;
    cout.fill('*');
    cout<<right<<l<<endl;
    cout.width(10);
    cout.fill('#');
    cout<<left<<l<<endl;
    cout.width(10);
    cout.fill('_');
    cout<<internal<<l<<endl;
    int hexadecimal = 0x42;
    cout<<hexadecimal<<endl;
    double double_num[] = { 1.126456789123, 2.12345, 3 };
    cout << double_num[0] << endl << endl;
    cout.precision(6);
    for( int i = 0; i < 3; i++ )
    {
        cout << double_num[i] << endl;
    }
    cout<<scientific<<double_num[0]<<endl<<endl;
    cout<<fixed<<showpos<<showpoint<<double_num[2]<<endl;
    cout.unsetf(ios::fixed);
    cout.unsetf(ios::showpos);
    cout.unsetf(ios::showpoint);
    cout.unsetf(ios::scientific);
    cout << Area(3) <<endl;

    // overloading
    int x=5,y=2;
    double n=5.0,m=2.0;
    cout << operate(x,y) << endl;
    cout << operate(n,m) << endl;

    // structures
    rectangle b = {3, 4};
    cout << "The area of a: " << b.area() << endl;

    // alocating 
    double *d;
    d = new double;
    *d=45.3;
    *d=*d+5;
    cout<<"Result: " << *d <<endl;
    delete d;

    d=new double[15];
    d[0]=4456;
    d[1]=d[0]+567;
    cout<<"Content of d[1]: "<<d[1]<<endl;
    delete [] d;

    return 0;
}

double Area(double InputRadius, double Pi){return Pi*power(InputRadius);}

int operate (int a, int b){return (a*b);}
double operate (double a, double b){return (a/b);}