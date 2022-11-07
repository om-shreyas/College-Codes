#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* root;
    struct node* left;
    struct node* right;
};
typedef struct node node;

node * base_root = NULL;

node * search(int n)
{
    node * current = base_root;
    while(current!=NULL && current->data!=n)
    {
        if(current->data>n)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return(current);
}

void traverse(node * root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        traverse(root->left);
        printf("-%d-",root->data);
        traverse(root->right);
    }
}

void insert_node(int value)
{
    node * new = (node *)malloc(sizeof(node));
    new->data = value;
    new->root = NULL; new->left = NULL; new->right = NULL;


    if(base_root==NULL)
    {
        base_root = new;
    }
    else
    {
        node * current = base_root;
        node * prior = NULL;
        while(current!=NULL)
        {
            if(current->data>value)
            {
                prior = current;
                current=current->left;
            }
            else
            {
                prior = current;
                current = current->right;
            }
        }
        if(prior->data<value)
        {
            prior->right=new;
        }
        else
        {
            prior->left=new;
        }
    }
}

void create_tree()
{
    int n;
    printf("Enter the no. of values u need to enter in the tree: ");
    scanf("%d",&n);
    for(int i =0; i<n;i++)
    {
        int temp;
        printf("Enter the value: ");
        scanf("%d",&temp);
        insert_node(temp);
    }
    traverse(base_root);
    printf("\n");
}

void delete_node(int n)
{
    node * n = search(n);
    if(n->left==NULL && n->right==NULL)
    {
        node * r = n->root;

    }
}

int main()
{
    create_tree();
    return 0;
}
