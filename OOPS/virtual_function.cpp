#include <iostream>
using namespace std;

class media
{
    public:
    char title[100];
    char publication[100];
    virtual void read(){
        cout<<"";
    }
    virtual void show(){
        cout<<"";
    }
};

class book:public media
{
    public:
    int pages;
    void read()
    {
        cout<<"Enter title of the book: ";
        cin>>title;
        cout<<"Enter Publication: ";
        cin>>publication;

        cout<<"Enter the number of pages: ";
        cin>>pages;
    }

    void show()
    {
        cout<<"The title: "<<title<<" The publication is: "<<publication<<" The pages are: "<<pages<<endl;
    }
};

class video_tapes:public media
{
    public:
    int time;

    void read()
    {
        cout<<"Enter title of the movie: ";
        cin>>title;
        cout<<"Enter Publication: ";
        cin>>publication;

        cout<<"Enter the total time of the movie: ";
        cin>>time;
    }

    void show()
    {
        cout<<"The title: "<<title<<" The publication is: "<<publication<<" The total time is: "<<time<<endl;
    }
};

int main()
{
    book b1;
    b1.read();
    b1.show();

    video_tapes v1;
    v1.read();
    v1.show();

    return 0;
}