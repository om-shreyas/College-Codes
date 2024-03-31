#include <iostream>
#include <fstream>
#include <string.h>
#include "intermediate_code.h"
#include <vector>
#include <map>

using namespace std;

void display(string inputString)
{
    vector<string> statements;
    for (int i = 0; i < inputString.size(); i++)
    {
        if (inputString[i] == '\n')
        {
            statements.push_back(inputString.substr(0, i));
            inputString = inputString.substr(i + 1, inputString.size() - i - 1);
            i = 0;
        }
        if (i == inputString.size() - 1)
        {
            statements.push_back(inputString);
            break;
        }
    }
    map<string, string> registers;
    string lastVar = "";
    for (int i = 0; i < statements.size() + 1; i++)
    {
        string statement = statements[i];
        if (statement.empty())
        {
            continue;
        }
        // cout << "Statement" << i << ": " << statement << endl;
        string operand1 = "", operand2 = "", expression = "", varName = "";
        for (int j = 0; j < statement.size(); j++)
        {
            if (statement[j] == '=')
            {
                varName = statement.substr(0, j);
                // cout << varName << endl;
            }
            if (statement[j] == '+')
            {
                int op1_s = statement.find("=") + 1;
                int op1_len = statement.find("+") - statement.find("=") - 1;
                // cout << "Operand 1 length: " << op1_len << endl;
                // cout << "Operand 1 start: " << op1_s << endl;
                int op2_s = statement.find("+") + 1;
                int op2_len = statement.size() - statement.find("+");
                // cout << "Operand 2 start: " << op2_s << endl;
                // cout << "Operand 2 length: " << op2_len << endl;
                operand1 = statement.substr(op1_s, op1_len);
                operand2 = statement.substr(op2_s, op2_len);
                // cout << "Operand 1: " << operand1 << endl;
                // cout << "Operand 2: " << operand2 << endl;
            }
        }
        if (registers.find(operand1) == registers.end())
        {
            registers[operand1] = "R" + to_string(registers.size());
            cout << "LDR " << registers[operand1] << ", " << operand1 << endl;
        }
        if (registers.find(operand2) == registers.end())
        {
            registers[operand2] = "R" + to_string(registers.size());
            cout << "LDR " << registers[operand2] << ", " << operand2 << endl;
        }
        if (registers.find(varName) == registers.end())
        {
            registers[varName] = "R" + to_string(registers.size());
        }
        cout << "ADDR " << registers[varName] << ", " << registers[operand1] << ", " << registers[operand2] << endl;
        lastVar = varName;
    }
    cout << "STR " << lastVar << ", "
         << "R" + to_string(registers.size() - 1) << endl;
}

int main()
{
    string inputString = "";
    ifstream fin("input.txt");
    // set the input string to the string in the file
    inputString = "t1=d+e\nt2=t1+c\na=b+t2";
    // call the lexical function
    display(inputString);
    return 0;
}