#include <iostream>
#include <fstream>
#include "lexical.h"
#include "intermediate_code.h"
#include <string.h>
#include "code_gen.h"
#include "semantic.h"
#include "syntax.h"

using namespace std;

int main()
{
    string inputString = "";
    ifstream fin("input.txt");
    // set the input string to the string in the file
    fin >> inputString;
    // call the lexical function
    cout << "Lexical Analysis:\n";
    lexical(inputString);
    cout << "\nSyntax Analysis:\n";
    syntax(inputString);
    cout << "\nSemantic Analysis:\n";
    semantic(inputString);
    string intermediateCode = intermediate_code(inputString);
    cout << "\nIntermediate Code:\n"
         << intermediateCode << "\n\nThree Address Code generation:\n";
    code_generation(intermediateCode);
    return 0;
}