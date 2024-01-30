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
        vector <string> user_defined;
        if(ch == '"'){
            quotes += 1;
        }
        if(quotes == 2){
            quotes = 0;
        }
        if(ch=='(' && check_keywords(keywords,bufer)==0 && quotes == 0){
            int user_flag = 0;
            for(int i=0;i<user_defined.size();i++)
            {
                if(bufer.compare(user_defined[i])){
                    user_flag = 1;
                    break;
                }
            }
            if(user_flag==0 && check_keywords(pre_defined,bufer)==0)
                {
                    user_functions+=1;
                    user_defined.push_back(bufer);

                }
                else{
                    count_functions+=1;   
                }
        }
        if((ch == '\n' || ch == ' ' || ch=='\t') && quotes==0 && (last_char != '\n' || last_char != ' ' || last_char!='\t'))
        {            
            if(check_keywords(keywords,bufer)==1){
                count_keywords += check_keywords(keywords,bufer);
            }
            else if(check_digit(bufer)==0){
                cout<<bufer<<endl;
                cons+=1;
            }
            
            tokens+=1;
            bufer = "";
        }
        else{
            bufer += ch;
        }
        last_char = ch;
    }
    cout<<"Number of Tokens: "<<tokens<<endl;
    cout<<"Number of Functions: "<<count_functions<<endl;
    cout<<"Number of User Functions: "<<user_functions<<endl;
    cout<<"Number of Keywords: "<<count_keywords<<endl;
    cout<<"Number of cons: "<<cons<<endl;
    fout.close();
}