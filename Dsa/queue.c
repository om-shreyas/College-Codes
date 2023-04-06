#include <stdio.h>
int front=-1;
int rear=-1;
int N=20;
void Insert(int A[],int e)
{
    if(front==-1)
    {
        front+=1;
        rear+=1;
        A[rear]=e;
    }
    else
    {
        if(rear==N-1)
        {
            printf("Overflow\n");
        }
        else
        {
            rear+=1;
            A[rear]=e;
        }
    }
}
void Delete(int A[])
{
    if(front==rear==-1)
    {
        printf("Underflow");
    }
    else
    {
        printf("Removed %d \n",A[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
    }
}
void traverse(int A[])
{
    int i=front;
    while(i!=rear+1)
    {
        printf("%d ",A[i]);
        if(i==N-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }

}
int main()
{
    int A[N];
    printf("Enter the number of elemnets to be entered: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter element: ");
        int e;
        scanf("%d",&e);
        Insert(A,e);
    }
    traverse(A);
    printf("Enter the number of elemnets to be deleted: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        Delete(A);
    }
    traverse(A);
    
    return 0;
}