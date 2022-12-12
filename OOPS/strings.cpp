#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string S1 = "Amity";
    string S2 = "University";
    string S3 = "";
    S3 = S1;
    cout<<S3<<endl;
    cout<<"The location of Univ in S2 is:"<<S2.find("Univ")<<endl;

    if(S1.compare(S2)==0)
    {
        cout<<"S1 is equal to S2"<<endl;
    }
    else if(S1.compare(S2)<0)
    {
        cout<<"S1 is smaller than S2"<<endl;
    }
    else if(S1.compare(S3)>0)
    {
        cout<<"S1 is greater than S2"<<endl;
    }

    return 0;
}
