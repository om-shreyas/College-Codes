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

void * multiply(node * h1, node * h2)
{
    node * c1 = h1;
    node * c2 = h2;
    while(c1!=NULL)
    {
        while(c2!=NULL)
        {
            node * new = (node *)malloc(sizeof(node));
            new->exp=c1->exp+c2->exp;
            new->coff=c1->coff*c2->coff;
            new->next=NULL;

            node * temp = h2;
            int add = 0;
            while(temp!=NULL)
            {
                if(temp->exp==new->exp)
                {
                    temp->coff=temp->coff+new->coff;
                    add++;
                    break;
                }
            }
            if(add==0)
            {
                node * current = h2;
                node * prior = NULL;
                while(current->exp>new->exp)
                {
                    prior = current;
                    current = current->next;
                }
                if(prior == NULL)
                {
                    new ->next = h2;
                    h2 = new;
                }
                else
                {
                    new->next=current;
                    prior->next=new;
                }
            }
            c2=c2->next;
        }
        c1=c1->next;
    }
    return(h2);
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

    print_poly(multiply(eq1,eq2));

    return 0;
}