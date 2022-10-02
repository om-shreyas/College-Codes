#include <iostream>
using namespace std;

class DistM;
class DistF
{
    int m;
    int cm;
    public:
    DistF(int meter=0,int centimeter=0)
    {
        m=meter;
        cm=centimeter;
    }
    friend void add(DistF f, DistM m);
};
class DistM
{
    int f;
    int i;
    public:
    DistF(int feet=0,int inches=0)
    {
        f=feet;
        i=inches;
    }
    friend void add(DistF f, DistM m);
};
void add(DistF f, DistM m)
{
    int tcm= m.cm + m.m*100 + m.f*30 + m.i*2.5;
    cout<<"Total meter: "<<tcm/100<<endl;
    cout<<"Total centimeter"<<tcm%100<<endl;
}