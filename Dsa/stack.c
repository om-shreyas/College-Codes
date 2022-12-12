#include <stdio.h>
int top=0;
int N=20;
void push(int e,int A[])
{
    if(top!=N)
    {
        top+=1;
        A[top]=e;
    }
    else
    {
        printf("Overflow");
    }
}
void pop(int A[])
{
    if(top!=0)
    {
        printf("The %d is popped.",A[top]);
        top-=1;
    }
    else
    {
        printf("Underflow");
    }
}
void peek(int A[])
{
    int n=top;
    while(n>=0)
    {
        printf(" %d ,",A[n]);
        n--;
    }
}
int main()
{
    int A[N];
    int c=0;
    while(c!=4)
    {
        printf("Enter the choice(1:push 2:pop 3:peak):");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the no. of elments u want to enter:");
            int n;
            scanf("%d",&n);

            for(int i=0;i<n;i++)
            {
                printf("Enter element: ");
                int e;
                scanf("%d",&e);
                push(e,A);
            }
            break;
        case 2:
            printf("Enter the no. of elments u want to delete:");
            int n1;
            scanf("%d",&n1);
            for(int i=0;i<n1;i++)
            {
                pop(A);
            }
            break;
        case 3:
            peek(A);
            break;
        default:
            c=4;
            break;
        }
    }
    return(0);
}
