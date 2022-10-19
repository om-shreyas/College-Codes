#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int exp;
    int coff;
    struct linked_list * next;
};
typedef struct linked_list node;

node * create_poly(node * head)
{
    int n;
    printf("Enter the order of the equation: ");
    scanf("%d",&n);
    for(int i=n;i>=0;i--)
    {
        node * new = (node *)malloc(sizeof(node));
        new->exp=i;
        if(i!=0)
        {
            printf("Enter the coeffecient for x^(%d): ",i);
        }
        else
        {
            printf("Enter the constant: ");
        }
        int c;
        scanf("%d",&c);
        new->coff=c;

        new->next=NULL;
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
    return head;
}

node * add_node(int exp, int coff, node * head)
{
    node * new = (node *)malloc(sizeof(node));
    new->exp=exp;
    new->coff=coff;
    new->next=NULL;

    node * current = head;
    node * prior = NULL;
    int add = 0;
    while(current->exp>=exp)
    {
        prior=current;
        current=current->next;
    }
    if(prior==NULL && add==0)
    {
        new->next=head;
        head = new;
    }
    else if(add==0)
    {
        new->next=current;
        prior->next=new;
    }
    return(head);
}

node * add(node * h1, node *h2)
{
    node * eq1 = h1;
    while(eq1!=NULL)
    {
        node * eq2 = h2;
        int add = 0;
        while(eq2!=NULL)
        {
            if(eq1->exp==eq2->exp)
            {
                eq2->coff = eq2->coff+eq1->coff;
                add++;
                break;
            }
            eq2 = eq2->next;
        }
        if(add==0)
        {
            h2 = add_node(eq1->exp,eq1->coff,h2);
        }
        eq1 = eq1->next;
    }
    return h2;
}

void print_poly(node * head)
{
    node * current = head;
    while(current->next!=NULL)
    {
        if(current->coff!=0)
        {
            printf("%dx^%d + ",current->coff,current->exp);
        }
        current=current->next;
    }
    if(current->coff!=0)
    {
        printf("%d ",current->coff);
    }
    printf("\n\n");
}

int main()
{
    node * eq1 = NULL;
    eq1 = create_poly(eq1);
    print_poly(eq1);

    node * eq2 = NULL;
    eq2 = create_poly(eq2);
    print_poly(eq2);

    print_poly(add(eq1,eq2));

    return 0;
}