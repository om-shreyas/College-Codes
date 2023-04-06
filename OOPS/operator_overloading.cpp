/* 5.	Write a program in which length is measured in feet and inches. User enters two values of lengths then a menu will be displayed for performing the following operations on it. Use operator overloading for all the functions:
1.	Add two lengths: + operator
2.	Compare the lengths using < operator
3.	Compare the lengths using == operator
4.	Use *= operator to multiply the length with given integer value */

#include <iostream>
using namespace std;

class Dist
{
    int feet;
    int inches;

    public:
    Dist(){feet=0;inches=0;}
    Dist(int f, int i)
    {
        feet = f;
        inches = i;
    }

    Dist operator + (Dist d){
        Dist temp;
        temp.inches = (inches + d.inches)%12;
        temp.feet = feet + d.feet + (inches + d.inches)/12;
        return(temp);
    }

    int operator < (Dist d){
        if(feet<d.feet){
            return(1);
        }
        else{
            if(inches<d.inches){
                return(1);
            }
            else{
                return(0);
            }
        }
    }

    int operator == (Dist d){
        if(feet==d.feet && inches==d.inches){
            return(1);
        }
        else{
            return(0);
        }
    }

    Dist operator *= (int n){
        Dist temp;
        temp.feet = n*feet + n*inches/12;
        temp.inches = n*inches%12;
        return temp;
    }

    void print()
    {
        cout<<"Feet: "<<feet<<" inches: "<<inches<<endl;
    }

};

int main()
{
    Dist d1(10,5);
    Dist d2(5,10);
    Dist d3;

    d3=d1+d2;
    d3.print();

    if(d1<d2)
    {
        d2.print();
    }
    else
    {
        d1.print();
    }

    Dist d4;
    d4=d1;
    if(d3==d1)
    {
        d3.print();
    }
    else if(d4==d1)
    {
        d4.print();
    }

    d3 = d1*=2;

    d3.print();

    return(0);
}