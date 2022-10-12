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
    int c;
    if(current->next!=head && current!=NULL)
    {
        current = current->next;
        c=1;
        while(current!=head)
        {
            current=current->next;
            c++;
        }
    }
    else
    {
        if(current==NULL)
        {
            c=0;
        }
        else
        {
            c=1;
        }
    }
    return(c);
}

void Insert(int v, int p)
{
    node * new = (node *)malloc(sizeof(node));
    new->value=v;
    new->next=NULL;

    node * current = head;

    if(p==-1)
    {
        if(head!=NULL)
        {
            while(current->next!=head)
            {
                current=current->next;
            }
            current->next=head;
            new->next=head;
        }
        else
        {
            head = new;
            new->next=head;
        }
    }
    else if(p==1)
    {
        if(head!=NULL)
        {
            new->next=head;
            head = new;
        }
        else
        {
            head = new;
            new->next = head;
        }
    }
    else if(p<=count()+1)
    {
        current=current->next;
        for(int i =1;i<p-1;i++)
        {
            current=current->next;
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
        while(current->value!=v)
        {
            prior = current;
            current=current->next;
        }
        prior->next=current->next;
    }
    else
    {
        printf("Underflow\n");
    }
}

void delete(int p)
{
    if(head!=NULL)
    {
        if()
        node * current = head;
        node * prior = NULL;   
        for(int)
    }
}

int main()
{
    int e,p,n;
    int c=0;
    while(c!=6)
    {
        printf("Enter ur choice (0: Create list | 1:Enter data | 2:Delete Data | 3:Delete Position | 4:Search Data | 5:Show Data | 6:Exit): ");
        scanf("%d",&c);

        switch (c)
        {
            case 0:
            int n;
            printf("Enter no. of values");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                int e;
                printf("Enter Value: ");
                scanf("%d",&e);
                Insert(e,-1);
            }
            break;

            case 1:
            printf("Enter Value: ");
            scanf("%d",&e);
            printf("Enter position(enter -1 for last): ");
            scanf("%d",&p);
            Insert(e,p);
            break;

            case 2:
            printf("Enter the value: ");
            scanf("%d",&e);
            delete_value(e);
            break;

            case 3:
            printf("Enter the position: ");
            scanf("%d",&p);
            delete(p);
            break;

            case 4:
            printf("Enter the value to search for: ");
            scanf("%d",&e);
            search(e);
            break;

            case 5:
            Traversal();

            default:
                break;
        }
    }
    return 0;
}