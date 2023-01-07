#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
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

void postorder(node * root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(node * root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node * root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void insert_node(int value)
{
    node * new = (node *)malloc(sizeof(node));
    new->data = value;
    new->left = NULL; new->right = NULL;


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
    inorder(base_root);
    printf("\n");
}

int check_leaf(node * n)
{
    if(n->left==NULL && n->right==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main()
{
    int e,p,n;
    int c=0;
    while(c!=6)
    {
        printf("Enter ur choice (0: Create list | 1:Enter data | 2:Delete Data | 3:Search Data | 4:Show Data | 5:Exit): ");
        scanf("%d",&c);

        switch (c)
        {
            case 0:
            {
                create_tree();
                break;
            }

            case 1:
            {
                printf("Enter Value: ");
                scanf("%d",&e);
                insert_node(e);
                break;
            }

            case 2:
            {
                printf("Enter the value: ");
                scanf("%d",&e);
                delete_node(e);
                break;
            }

            case 3:
            {
                printf("Enter the value to search for: ");
                scanf("%d",&e);
                search_node(e);
                break;
            }

            case 4:
            {
                inorder(base_root);
                break;
            }

            default:
            {
                break;
            }
        }
    }
    return 0;
}
