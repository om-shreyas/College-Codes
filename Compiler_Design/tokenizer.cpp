#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int check_keywords(vector<string> keywords, string word){
    for(int i = 0;i<keywords.size();i++){
        if(keywords[i]==word){

            return 1;
        }
    }
    return 0;
}
int check_digit(string s) {
   for( int i = 0; i < s.length(); i++ ) {
      if( !isdigit( s[i])) {
         return 1;
      }
   }
   return 0;
}
int main()
{
    vector<string> keywords = {"asm", "double", "new", "switch","auto","else","operator","template","break","enum","private","this","case","extern","protected","throw","catch","float","public","try","char"
    ,"for","register","typedef","class","friend","return","union","constant","goto","short","unsigned","continue","if","signed","virtual","default","inline","sizeof","void","delete","int","static","volatile","do"
    ,"long","struct","while", "cout","using"};
    vector<string> pre_defined = {"main",};

    ifstream fout;
    fout.open("sample.txt");

    vector <string> user_defined = {"---",};

    char ch;
    int tokens=0;
    int quotes = 0;
    int count_keywords = 0;
    int count_functions = 0;
    int user_functions = 0;
    int cons = 0;
    string bufer="";

    char last_char = '-';

    while(fout.get(ch)){
        cout<<bufer;
        if(ch=='\n' || ch==' ' || ch=='\t')
        {
            cout<<bufer<<endl;
            tokens+=1;
            bufer = "";
        }
        else{
            bufer += ch;
        }
    }
    cout<<"Number of Tokens: "<<tokens<<endl;
    fout.close();
}