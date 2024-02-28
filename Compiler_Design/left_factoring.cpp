#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

    unordered_map<string, vector<string>> non_terminals;

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
            non_terminals[start].push_back(betas[0] + new_start);
            for (int k = 1; k < betas.size(); ++k) {
                non_terminals[new_start].push_back(betas[k]);
            }
            non_terminals[new_start].push_back("epsilon");

            string common_prefix = "";
            for (int k = 0; k < alphas.size(); ++k) {
                if (common_prefix.empty()) {
                    common_prefix = alphas[k];
                } else {
                    int j = 0;
                    while (j < common_prefix.size() && j < alphas[k].size() && common_prefix[j] == alphas[k][j]) {
                        j++;
                    }
                    common_prefix = common_prefix.substr(0, j);
                }
            }

            if (!common_prefix.empty()) {
                non_terminals[start].push_back(common_prefix + new_start);
                for (int k = 0; k < alphas.size(); ++k) {
                    string remainder = alphas[k].substr(common_prefix.size());
                    if (!remainder.empty()) {
                        non_terminals[new_start].push_back(remainder);
                    }
                }
            } else {
                non_terminals[start].insert(non_terminals[start].end(), alphas.begin(), alphas.end());
            }
        } else {
            non_terminals[start].insert(non_terminals[start].end(), betas.begin(), betas.end());
        }
    }

    for (auto it = non_terminals.begin(); it != non_terminals.end(); ++it) {
        new_grammar.push_back(it->first + "->");
        for (int i = 0; i < it->second.size(); ++i) {
            new_grammar.push_back(it->second[i]);
            if (i != it->second.size() - 1)
                new_grammar.back() += "|";
        }
    }

    cout << "New Grammar:" << endl;
    print_vector(new_grammar);

    return 0;
}
