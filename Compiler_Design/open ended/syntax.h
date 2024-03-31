#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }

        else
        {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                   !st.empty() && prec(s[i]) == prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

struct node
{
    char data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node * return_tree(string exp)
{
    stack <node *> stack;
    
    for(int i = 0;i<exp.size();i++)
    {
        if(exp[i]!='+')
        {
            node * new_node = new node;
            new_node->data = exp[i];
            stack.push(new_node);
        }
        else{

            node * new_node_l = stack.top();
            stack.pop();
            node * new_node_r = stack.top();
            stack.pop();

            node * new_node = new node;
            new_node->data = exp[i];
            new_node->left = new_node_l;
            new_node->right = new_node_r;

            stack.push(new_node);
        }
    }
    node * root = stack.top();
    return root;
}


void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void printTree(node *root, int space = 0, int height = 10)
{
    if (root == nullptr)
        return;

    space += height;

    printTree(root->right, space, height);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";

    cout << root->data << "\n";

    printTree(root->left, space, height);
}

int syntax(string exp)
{
    exp = exp.substr(exp.find("=") + 1);
    cout << infixToPostfix(exp) << endl;

    node *root = return_tree(infixToPostfix(exp));

    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;

    printTree(root);
    return 0;
}