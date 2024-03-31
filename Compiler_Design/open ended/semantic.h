#include <bits/stdc++.h>
using namespace std;

int prec_s(char c)
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

string infixToPostfix_s(string s)
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
            while (!st.empty() && prec_s(s[i]) < prec_s(st.top()) ||
                   !st.empty() && prec_s(s[i]) == prec_s(st.top()))
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

struct node_s
{
    char data;
    struct node_s *left;
    struct node_s *right;
};
typedef struct node_s node_s;

node_s *return_tree_s(string exp)
{
    stack <node_s *> stack;
    
    for(int i = 0;i<exp.size();i++)
    {
        if(exp[i]!='+')
        {
            node_s * new_node = new node_s;
            new_node->data = exp[i];
            stack.push(new_node);
        }
        else{

            node_s * new_node_l = stack.top();
            stack.pop();
            node_s * new_node_r = stack.top();
            stack.pop();

            node_s * new_node = new node_s;
            new_node->data = exp[i];
            new_node->left = new_node_l;
            new_node->right = new_node_r;

            stack.push(new_node);
        }
    }
    node_s * root = stack.top();
    return root;
}

void postorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_s(root->left);
        postorder_s(root->right);
        printf("%c ", root->data);
    }
}
void preorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%c ", root->data);
        preorder_s(root->left);
        preorder_s(root->right);
    }
}
void inorder_s(node_s *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_s(root->left);
        printf("%c ", root->data);
        inorder_s(root->right);
    }
}

void printTree_s(node_s *root, int space = 0, int height = 10)
{
    if (root == nullptr)
        return;

    space += height;

    printTree_s(root->right, space, height);

    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";

    cout << root->data << "\n";

    printTree_s(root->left, space, height);
}

int semantic(string exp)
{
    exp = exp.substr(exp.find("=") + 1);
    cout << infixToPostfix_s(exp) << endl;

    node_s *root = return_tree_s(infixToPostfix_s(exp));

    preorder_s(root);
    cout << endl;
    postorder_s(root);
    cout << endl;
    inorder_s(root);
    cout << endl;

    printTree_s(root);
    return 0;
}