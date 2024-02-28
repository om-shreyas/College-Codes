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

        vector<string> alphas;
        vector<string> betas;
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
            if(temp_production.find(start) == 0){
                alphas.push_back(temp_production.substr(1)); 
            } else {
                betas.push_back(temp_production);
            }
        }
        print_vector(alphas);
        print_vector(betas);

        if (!alphas.empty()) {
            string new_start = start + "'";
            new_grammar.push_back(start + "->"); 
            for (int k = 0; k < betas.size(); ++k) {
                new_grammar.push_back(betas[k] + new_start);
                if (k != betas.size() - 1) 
                    new_grammar.back() += "|";
            }
            new_grammar.push_back(new_start + "->"); 
            for (int k = 0; k < alphas.size(); ++k) {
                new_grammar.push_back(alphas[k] + new_start);
                if (k != alphas.size() - 1) 
                    new_grammar.back() += "|";
            }
            new_grammar.push_back(new_start + "->" + "epsilon");
        } else {
            new_grammar.push_back(grammar[i]);
        }
    }

    cout << "New Grammar:" << endl;
    print_vector(new_grammar);

    return 0;
}
