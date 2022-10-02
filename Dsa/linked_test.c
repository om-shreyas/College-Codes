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
    if(p==-1)
    {
        node * new = (node *)malloc(sizeof(node));
        new->value = n;
        new->next = NULL;

        node * current = head;
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
        node * new = (node *)malloc(sizeof(node));
        new->value = n;
        new->next = NULL;

        node * current = head;
        int i;
        for(i=1;i<n;i++)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
    else
    {
        printf("Invalid  Location or Overflow");
    }
}

void Traversal()
{
    node * current = head;
    while(current!=NULL)
    {
        printf("%d",current->value);
        current = current->next;
    }
}

int main()
{
    Insert(10,-1);
    Traversal();
    Insert(10,5);
    return 0;
}