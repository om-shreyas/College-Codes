#include <iostream>
using namespace std;

class temporary
{
    int n;
    public:
    temporary(int a)
    {
        n=a;
        cout<<"Tempary class"<<n<<" created"<<endl;
    }

    ~temporary()
    {
        cout<<"Tempary class"<<n<<" destroyed"<<endl;
    }
};
int main()
{
    temporary a(1);
    temporary b(2);
    return(0);
}