#include <iostream>
using namespace std;

class Person
{
    char name[64]="";
    char add[64]="";
    int age;
    int salary;

    public:
    Person(Person &p)
    {
        
    }
    void entervalue()
    {
        cout<<"Enter the name:";
        cin>>name;
        cout<<"Enter address";
        cin>>add;
        cout<<"Enter age";
        cin>>age;
        cout<<"Enter salary";
        cin>>salary;
    }
};