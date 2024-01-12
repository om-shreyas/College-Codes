#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fout;
    fout.open("sample.txt");

    ofstream fin;
    fin.open("new_sample.txt");

    char ch;
    while(fout.get(ch)){
        fin<<ch;
    }
    fout.close();
    fin.close();

}