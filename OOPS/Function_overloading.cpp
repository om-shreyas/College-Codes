#include <iostream>
using namespace std;

float vol(float a) //For Circle
{
    return(4/3*3.14*a*a*a);
}
float vol(float a,float b) //For Cylinder
{
    return(3.14*a*a*b);
}
float vol(float a, float b, float c) //For Cuboid
{
    return(a*b*c);
}

int main()
{
    cout<<"Enter choice(1:Circle, 2:Cylinder 3:Cuboid)";
    int a;
    cin>>a;
    switch (a)
    {
    case 1:
        int r;
        cout<<"Enter radius:";
        cin>>r;
        cout<<vol(r);
        break;
    case 2:
        int b,h;
        cout<<"Enter radius and height";
        cin>>b>>h;
        cout<<vol(b,h);
        break;
    case 3:
        int x,y,z;
        cout<<"Enter length, breadth and height";
        cin>>x>>y>>z;
        cout<<vol(x,y,z);
        break;
    default:
        break;
    }

}
