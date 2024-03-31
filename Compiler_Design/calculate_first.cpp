#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector(vector<string> s){
    for(int i = 0;i<s.size();i++)
    {
        cout<<s[i] << " ";
    }
    cout<<endl;
}
string findCommonPrefix(const string& str1, const string& str2) {
    int minLength = min(str1.length(), str2.length());
    string commonPrefix = "";

    for (int i = 0; i < minLength; ++i) {
        if (str1[i] == str2[i]) {
            commonPrefix += str1[i];
        } else {
            break;
        }
    }

    return commonPrefix;
}
string common_string(vector<string> rhs_production)
{
    string common = "";
    for(int i = 0;i<rhs_production.size()-1;i++)
    {
        string new_common = findCommonPrefix(rhs_production[0],rhs_production[1]);
        if(new_common=="")
        {
            continue;
        }
        else{
            if(common.size()<new_common.size() and common.size()!=0){
                continue;
            }
            else{
                common = new_common;
            }
        }
    }
    return(common);
}

int main(){
    vector<string> grammar;
    string s;
    while(true){
        s = "";
        cout<<"Enter the production (enter exit to stop): ";
        cin>>s;
        if(s=="exit")
        {
            break;
        }
        grammar.push_back(s);
    }
    print_vector(grammar);

    vector <string> new_grammar;

    for(int i = 0;i<grammar.size();i++)
    {
        string start;
        string rhs;
        string production = grammar[i];
        start = production.substr(0,production.find("->"));
        rhs = production.substr(production.find("->")+2); 

        vector<string> rhs_production;
        int initial = 0;
        int j = 0; 
        while (initial < rhs.size()) { 
            int pipe_pos = rhs.find("|", initial);
            string temp_production;
            if (pipe_pos != string::npos) {
                temp_production = rhs.substr(initial, pipe_pos - initial);
                initial = pipe_pos + 1;
            } else {
                temp_production = rhs.substr(initial);
                initial = rhs.size();
            }
            rhs_production.push_back(temp_production);
        }
        string common = common_string(rhs_production);
        string new_start = start + "'";
        string common_rhs = common;
        string new_rhs = "";
        int epsilon = 0;
        if(common!=""){
            int size = common.size();
            for(int j=0;j<rhs_production.size();j++)
            {
                if(rhs_production[j].find(common)==0){
                    if(rhs_production[j].size()==common.size() && epsilon == 0){
                        common_rhs += "|epsilon";
                    }
                    rhs_production[j] = rhs_production[j].replace(0,common.size(),new_start);
                    // cout<<rhs_production[j];
                }
                new_rhs+=(rhs_production[j])+='|';
            }
            new_grammar.push_back(start+"->"+new_rhs.substr(0,new_rhs.size()-1));
            new_grammar.push_back(new_start+"->"+common_rhs);
        }
        else{
            new_grammar.push_back(grammar[i]);
        }
        
    }

    print_vector(new_grammar);

    return 0;
}