#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool is_operator(char w)
{
    vector<char> op = {'+', '-', '='};
    for (int i = 0; i < op.size(); i++)
    {
        if (w == op[i])
        {
            return true;
        }
    }
    return false;
}
bool is_seperator(char w)
{
    vector<char> sep = {'[', ']', '(', ')', '(', ')', ';', ','};
    for (int i = 0; i < sep.size(); i++)
    {
        if (w == sep[i])
        {
            return true;
        }
    }
    return false;
}
bool is_identifier(char w)
{
    if ((w >= 'a' && w <= 'z') || (w >= 'A' && w <= 'Z'))
    {
        return true;
    }
    return false;
}
void display(vector<char> &a)
{
    cout << "{";
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ", ";
    }
    cout << "}" << endl;
    cout << endl;
    return;
}
int lexical(string inputString)
{
    int c_op = 0;
    int c_sep = 0;
    int c_id = 0;
    vector<char> op;
    vector<char> sep;
    vector<char> id;
    string str;
    cout << "Enter string: ";
    str = inputString;
    int i = 0;
    string word = "";
    while (i <= str.length())
    {
        char ch = str[i];
        if (is_operator(ch) == true)
        {
            op.push_back(ch);
            c_op++;
        }
        else if (is_seperator(ch) == true)
        {
            sep.push_back(ch);
            c_sep++;
        }
        else if (is_identifier(ch) == true)
        {
            id.push_back(ch);
            c_id++;
        }
        ++i;
    }
    cout << endl;
    cout << "Total tokens are: " << (c_op + c_sep + c_id) << endl;
    cout << "Out of them:\n"
         << endl;
    cout << "Operators are: " << c_op << endl;
    display(op);
    cout << "Seperators are: " << c_sep << endl;
    display(sep);
    cout << "Identifiers are: " << c_id << endl;
    display(id);
    return 0;
}