#include <stdio.h>
#include <stdlib.h>

struct linked_list
{
    int exp;
    int coff;
    struct linked_list * next;
};
typedef struct linked_list node;

node* add_node(node * head, int exp, int coff)
{
    node * current = head;
    node * prior = NULL;
    int add = 0;

    while(current!= NULL && current->exp>=exp)
    {
        if(current->exp == exp)
        {
            add++;
            current->coff=current->coff+coff;
            break;
        }
        else
        {
            prior = current;
            current = current->next;
        }
    }
    if(add==0)
    {
        node * new = (node *)malloc(sizeof(node));
        new->exp=exp;new->coff=coff;new->next=NULL;
        if(prior==NULL)
        {
            new->next = current;
            head = new;
        }
        else
        {
            new->next=current;
            prior->next=new;
        }
    }
    return head;
}

node * create_poly(node * head)
{
    int n;
    printf("Enter the order of the equation: ");
    scanf("%d",&n);
    for(int i=n;i>=0;i--)
    {
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
        head = add_node(head,i,c);

    }
    return head;
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

node * multiply(node * h1, node * h2, node * h3)
{
    node * c1 = h1;
    while(c1!=NULL)
    {
        node * c2 = h2;
        while(c2!=NULL)
        {
            int e = c1->exp+c2->exp;
            int c = c1->coff*c2->coff;
            h3 = add_node(h3,e,c);

            c2 = c2->next;
        }
        c1 = c1->next;
    }
    return h3;
}

node * add(node * h1, node * h2, node * h3)
{
    node * c1 = h1;
    while(c1!=NULL)
    {
        h3 = add_node(h3,c1->exp,c1->coff);
        c1 = c1->next;
    }
    node * c2 = h2;
    while(c2!=NULL)
    {
        h3 = add_node(h3,c2->exp,c2->coff);
        c2 = c2->next;
    }
    return h3;
}

int main()
{
    node * eq1 = NULL;
    eq1 = create_poly(eq1);
    print_poly(eq1);

    node * eq2 = NULL;
    eq2 = create_poly(eq2);
    print_poly(eq2);

    printf("The sum of the two polynomials is: ");
    node * eq3 = NULL;
    eq3 = add(eq1,eq2,eq3);
    print_poly(eq3);

    printf("The product of the two polynomial is: ");
    node * eq4 = NULL;
    eq4 = multiply(eq1,eq2,eq4);
    print_poly(eq4);
    return 0;
}
