#include <iostream>
using namespace std;

class clock
{
private:
    int hours;
    int minutes;
public:
    clock()
    {
        hours = 0;
        minutes = 0;
    }
    clock(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    void create()
    {
        int h,m;
        cout<<"Enter hours: ";
        cin>>h;
        cout<<"Enter minutes: ";
        cin>>m;

        hours = h;
        minutes = m;
    }
    void print()
    {
        cout<<hours<<":"<<minutes<<endl;
    }
    void add(clock c1, clock c2)
    {
        hours = c1.hours + c2.hours + ((c1.minutes + c2.minutes)/60);
        minutes = (c1.minutes + c2.minutes)%60;
    }
};

int main()
{
    clock c1(10,20);
    c1.print();
    clock c2(5,50);
    c2.print();

    clock c3;
    c3.add(c1,c2);
    c3.print();

    return 0;
}
