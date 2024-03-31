#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <regex.h>

using namespace std;

string intermediate_code(string inputString)
{
    // sample inputString = "a=b+((d+e)+c)"
    string workingString = inputString;
    map<int, string> temp;
    string result = "";
    while (workingString.find('(') != string::npos)
    {
        for (int i = 0; i < workingString.size(); i++)
        {
            if (workingString[i] == '(')
            {
                int start = i;
                int end = workingString.find(')');
                string subString = workingString.substr(start + 1, end - start - 1);
                if (subString.find('(') != string::npos)
                {
                    continue;
                }
                temp[start] = subString;
                cout << "t" + to_string(temp.size()) << "=" << subString << endl;
                result += "t" + to_string(temp.size()) + "=" + subString + "\n";
                string varName = "t" + to_string(temp.size());
                workingString.replace(start, end - start + 1, varName);
                // cout << workingString << endl;
            }
        }
    }
    cout << workingString << endl;
    result += workingString;

    return result;
}

// int main()
// {
//     string inputString = "";
//     ifstream fin("input.txt");
//     // set the input string to the string in the file
//     fin >> inputString;
//     // call the lexical function
//     intermediate_code(inputString);
//     return 0;
// }