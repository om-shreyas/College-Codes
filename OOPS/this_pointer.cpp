#include <iostream>
using namespace std;

class temp
{
    int value;
public:
    temp()
    {
        cout<<"Enter value: ";
        cin>>value;
    }
    void add(int value)
    {
        cout<<"The sum is : "<<this->value+value;
    }

};
int main()
{
    temp t1;
    int n;
    cout<<"Enter value to add: ";
    cin>>n;
    t1.add(n);
    return 0;
}
