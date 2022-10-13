#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int value;
    struct linked_list * next;
};
typedef struct linked_list node;

node * head = NULL;

void delete_value(int n)
{
    if(head->value==n)
    {
        head = head->next;
    }
    else
    {
        node * current = head;
        node * prior = NULL;
        while(current->value!=n)
        {
            prior = current;
            current = current->next;
        }
        prior->next=current->next;
    }
}

void search(int e)
{
    node * current = head;
    int n = 1;
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

void delete (int p)
{
    node * current = head;
    node * prior = NULL;
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        if(p==1)
        {
            node * current = head;
            current = current->next;
            while(current->next!=head)
            {
                current = current->next;
            }
            head = head->next;
            current->next=head;
        }
        else
        {
            node * current = head;
            node * prior = NULL;
            for(int i=1;i<p;i++)
            {
                prior=current;
                current=current->next;
            }
            prior->next= current->next;
        }
    }
}

void Insert (int n, int p)
{
    node * new = (node *)malloc(sizeof(node));
    new->value = n;
    new->next = NULL;

    if(p==1)
    {
        if(head == NULL)
        {
            head = new;
            new->next = head;
        }
        else
        {
            new->next = head;
            node * current = head;
            while(current->next!=head)
            {
                current=current->next;
            }
            current->next=new;
            head=new;
        }
    }
    else if(p==-1)
    {
        if(head == NULL)
        {
            head = new;
            new->next = head;
        }
        else
        {
            node * current = head;
            current = current->next;
            while(current->next!=head)
            {
                current = current->next;
            }
            new->next=current->next;
            current->next=new;
        }
    }
    else
    {
        node * current = head;
        for(int i=0;i<n-1;i++)
        {
            current=current->next;
        }
        new->next=current->next;
        current->next=new;
    }
}

void Traversal()
{
    node * current = head;
    if (head != NULL)
    {
        printf("%d",current->value);
        current=current->next;
        while(current!=head)
        {
            printf("%d",current->value);
            current=current->next;
        }
        printf("\n");
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