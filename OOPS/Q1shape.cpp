#include <iostream>
using namespace std;

class Shape
{
    int radius;
    int width;
    int length;
    public:
    Shape(int r)
    {
        radius=r;
    }
    Shape(int w,int l)
    {
        radius=-1;
        width=w;
        length=l;
    }
    void perimeter()
    {
        if(radius==-1)
        {
            cout<<"The perimeter is: "<<2*(width+length)<<endl;
        }
        else
        {
            cout<<"The perimeter is: "<<2*3.14*radius<<endl;
        }
    }
    void area()
    {
        if(radius==-1)
        {
            cout<<"The area is: "<<(width*length)<<endl;
        }
        else
        {
            cout<<"The area is: "<<3.14*radius*radius<<endl;
        }        
    }
    ~Shape()
    {
        cout<<"Shape Destroyed"<<endl;
    }
};

int main()
{
    int r,l,w;
    cout<<"Enter the radius of the circle: ";
    cin>>r;
    Shape circle(r);

    cout<<"Enter the length and width: ";
    cin>>w>>l;
    Shape rectangle(w,l);

    rectangle.area();
    rectangle.perimeter();

    circle.area();
    circle.perimeter();

    return 0;
}