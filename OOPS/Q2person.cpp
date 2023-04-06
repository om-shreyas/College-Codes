#include <iostream>
using namespace std;

class Person
{
    public:
    char name[64]="";
    int age;
    char address[64]="";
    int salary;
    Person()
    {
        cout<<"Enter name of the person: ";
        cin>>name;
        cout<<"Enter age of the person: ";
        cin>>age;
        cout<<"Enter address of the person: ";
        cin>>address;
        cout<<"Enter salary of the person: ";
        cin>>salary;

        cout<<"Name: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<endl;
    }
};
void eldest_youngest(Person A[])
{
    int y=0;
    int e=0;
    int n=sizeof(A)/sizeof(Person);
    for(int i=0;i<n;i++)
    {
        if(A[i].age > A[e].age)
        {
            e=i;
        }
        else if(A[i].age < A[y].age)
        {
            y=i;
        }
    }
    cout<<"The eldest person is: "<<A[e].name<<" aged: "<<A[e].age<<endl;
    cout<<"The youngest person is: "<<A[y].name<<" aged: "<<A[y].age<<endl;
}

int main()
{
    int n;
    cout<<"Enter the length of the array of people: ";
    cin>>n;
    Person A[n];
    eldest_youngest(A);
}