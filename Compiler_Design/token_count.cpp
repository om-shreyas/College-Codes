#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fout;
    fout.open("sample.txt");

    char ch;
    int tokens=0;
    int quotes = 0;
    char last_char = '-';
    while(fout.get(ch)){
        if(ch == '"'){
            quotes += 1;
        }
        if(quotes == 2){
            quotes = 0;
        }
        if((ch == '\n' || ch == ' ' || ch=='\t') && quotes==0 && (last_char != '\n' || last_char != ' ' || last_char!='\t')){
            tokens+=1;
        }
        last_char = ch;
    }
    cout<<tokens<<endl;
    fout.close();

}