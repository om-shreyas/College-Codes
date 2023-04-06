#include <iostream>
using namespace std;

class Length
{
    int feet;
    int inches;

    public:
        Length()
        {
            feet = 0;
            inches = 0;
        }
        Length(int x, int y)
        {
            feet = x;
            inches = y;
        }
        Length operator + (Length X)
        {
            Length Res;
            Res.feet = feet + X.feet + (inches + X.inches)/12;
            Res.inches = (inches + X.inches)%12;
            return Res;
        }
        Length operator < (Length X)
        {
            int p = feet*12 + inches;
            int q = X.feet*12 + X.inches;
            if (p < q)
            {
                cout << "True." << endl;
            } else
            {
                cout << "False." << endl;
            }
        }
        Length operator == (Length X)
        {
            int p = feet*12 + inches;
            int q = X.feet*12 + X.inches;
            if (p==q)
            {
                cout << "Equal." << endl;
            } else
            {
                cout << "Not Equal." << endl;
            }
        }
        Length operator *= (int X)
        {
            int p = feet*12 + inches;
            int q = p*X;
            feet = q/12;
            inches = q%12;
        }
        void print()
        {
            cout << feet << " feet and " << inches << " inches." << endl;
        }
};

int main()
{
    Length A(7, 9);
    Length B(4, 11);

    Length C = A + B;
    C.print();

    A < B;
    A == B;

    C*=12;
    C.print();

    return 0;
}
