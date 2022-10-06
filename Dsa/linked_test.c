#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int value;
    struct linked_list * next;
};
typedef struct linked_list node;

node * head = NULL;

int count()
{
    node * current = head;
    int c=0;
    while(current!=NULL)
    {
        current=current->next;
        c++;
    }
    return(c);
}

void Insert(int n, int p)
{
    node * new = (node *)malloc(sizeof(node));
    new->value = n;
    new->next = NULL;
    node * current = head;
    if(p==-1)
    {
        if(current!=NULL)
        {
            while(current->next!=NULL && current!=NULL)
            {
                current=current->next;
            }
            new->next=current->next;
            current->next = new;
        }
        else
        {
            head = new;
        }
    }
    else if(p<=count())
    {
        int i;
        for(i=1;i<n;i++)
        {
            current = current->next;
        }
        new->next = current;
        current->next = new;
    }
    else
    {
        printf("Invalid  Location or Overflow\n");
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
        printf("Underflow\n");
    }
}

void Traversal()
{
    node * current = head;
    while(current!=NULL)
    {
        printf("%d ",current->value);
        current = current->next;
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
        printf("The element is at %d\n",n);
    }
    else
    {
        printf("Element not present\n");
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

int main()
{
    Insert(10,-1);
    Insert(20,-1);
    Insert(30,-1);
    Insert(40,-1);
    Insert(50,-1);
    Insert(60,-1);
    Insert_sort(25);
    delete(2);
    delete_value(50);
    search(30);
    
    Traversal();
    return 0;
}