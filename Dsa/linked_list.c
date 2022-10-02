#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

void Insert_sort(int e)
{
    node *new = (node *)malloc(sizeof(node));
    new->value=e;
    new->next=NULL;

    node *current = head;

    while (e < current->next->value)
    {
        current->next;
    }
    
    new->next = current->next;
    current->next = new;
}

void Insert(int e, int n)
{
    if(n!=-1)   /*Entering at user defined position*/
    {
        node * new = (node *)malloc(sizeof(node));
        new->value=e;
        new->next=NULL;

        node * current = head;

        for(int i=1;i<n-1;i++)
        {
            current = current->next;
        }
        new->next=current->next;
        current->next=new;
    }
    else    /*Entering at last position*/
    {
        node * new;
        new->value=e;
        new->next=NULL;

        node * current = head;

        while(current->next!=NULL)
        {
            current = current->next;
        }
        new->next=current->next;
        current->next=new;
    }
}

void delete_value(int v)
{
    if(head!=NULL)
    {
        node * current = head;
        node * prior = NULL;
        while(current->value != v)
        {
            prior = current;
            current=current->next;
        }
        prior->next = current->next;
    }
    else
    {
        printf("Underflow");
    }
}

void delete(int n)
{
    if(head->next!=NULL)
        if(n!=-1)
        {   
            node * current = head;
            node * prior = NULL;
            while(current->next!=NULL)
            {
                prior = current;
                current=current->next;
            }
            prior->next=NULL;
        }
        else
        {
            node * current = head;
            node * prior = NULL;
            for(int i=1;i<n;i++)
            {
                prior = current;
                current = current->next;
            }
            prior->next = current->next;
        }
    else
    {
        printf("Underflow");
    }
}

void traversal()
{
    node * current = head;

    while(current->next!=NULL)
    {
        printf("%d ",current->value);
    }
    printf("\n");
}

void search(int e)
{
    node * current = head;
    int n = 0;
    while(current->value!=e)
    {
        n++;
        current = current->next;
    }
    if(current->value==e)
    {
        printf("The element is at %d",n);
    }
    else
    {
        printf("Element not present");
    }
}

int main()
{
    printf("Enter the number of elements to be added: ");
    int n,pos,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Position(Enter -1 for last): ");
        //int p;
        scanf("%d",&pos);
        printf("Value: ");
        //int e;
        scanf("%d",&value); 
        printf("check");
        Insert(value,pos);
    }
    traversal();
}