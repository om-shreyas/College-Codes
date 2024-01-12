#include <iostream>
using namespace std;
#include <vector>
#include <string>
int precedence(char s){
    if(s=='^'){
        return 2;
    }
    else if(s=='/' or s=='*'){
        return 1;
    }
    else{
        return 0;
    }
}
class Stack{
    public:
    char stack[100];
    int top;
    Stack(){
        top = -1;
    }
    void push(char a){
        top++;
        if(top<100){
            stack[top]=(a);
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>0)
        {
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    char back(){
        return(stack[top]);
    }
};
string infix_postfix(string s){
    Stack stack;
    string s1;
    int i = 0;
    for(int i = 0;i<s.size();i++)
    {
        cout<<s1<<" "<<s[i]<<" "<<endl;
        if(isalnum(s[i])){
            s1 = s1+s[i];
        }
        else if(s[i]=='('){
            stack.push(s[i]);
        }
        else if (s[i]==')')
        {
            while(stack.back()!='(')
            {
                s1 = s1+stack.back();
                stack.pop();
            }
            stack.pop();
        }
        else{
            if(stack.top!=-1){
                while(stack.back()!='(' and (s[i])>=precedence(stack.back())){
                    s1 = s1 + stack.back();
                    stack.pop();
                    if(stack.top==-1){
                        break;
                    }
                }
            }
            stack.push(s[i]);
        }
    }
    return s1;
}
int main(){
    string s;
    cin>>s;
    cout<<infix_postfix(s);
    return 0;
}