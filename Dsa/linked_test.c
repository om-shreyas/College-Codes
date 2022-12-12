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
    else if(p==1)
    {
        new->next=head;
        head = new;
    }
    else if(p<=(count()+1))
    {
        int i;
        for(i=1;i<p-1;i++)
        {
            current = current->next;
        }
        new->next = current->next;
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
                {

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
                }

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
