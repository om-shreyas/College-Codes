#include <iostream>
using namespace std;

class student
{
    protected:
    int roll;
    public:
    void get_roll()
    {
        cout<<"The roll no. is: "<<roll<<endl;
    }
    void put_roll(int n)
    {
        roll=n;
    }
};
class exam: public student
{
    protected:
    int sub1;
    int sub2;
    public:
    void put_mark(int n1, int n2)
    {
        sub1=n1;
        sub2=n2;
    }
    void get_mark()
    {
        cout<<"Marks in subject 1: "<<sub1<<" and marks in subject 2: "<<sub2<<endl;
    }
};
class sport
{
    protected:
    int score;
    public:
    void put_score(int n)
    {
        score=n;
    }
    void get_score()
    {
        cout<<"Score is : "<<score<<endl;
    }
};
class result:public exam, public sport
{
    protected:
    int result;
    public:
    void get_result()
    {
        cout<<"Total result is : "<<score+sub1+sub2<<endl;
    }
};
int main()
{
    result r1;
    r1.put_roll(10);
    r1.put_mark(90,80);
    r1.put_score(52);
    r1.get_roll();
    r1.get_mark();
    r1.get_score();
    r1.get_result();

    return 0;
}