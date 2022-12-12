#include <stdio.h>
#include <stdlib.h>
void insertion(int A[],int N,int l,int e)
{
    int i;
    for(i=N;i>l-1;i--)
    {
        A[i]=A[i-1];
    }
    A[l-1]=e;
}
void deletion(int A[],int n,int N)
{
    int i;
    for(i=n;i<N;i++)
    {
        A[i-1]=A[i];
    }
}
void traversal(int A[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
}
int* create(int N)
{
    int * A;
    A = (int *)malloc(100*sizeof(int));
    int i;
    for(i=0;i<N;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    return (A);
}
int main()
{
    int * A;
    int N;
    printf("Enter the size of the array: ");
    scanf("%d",&N);
    A = create(N);
    traversal(A,N);
    int l;
    printf("Enter the location: ");
    scanf("%d",&l);
    int e;
    printf("Enter the element: ");
    scanf("%d",&e);
    insertion(A,N,l,e);
    N+=1;
    traversal(A,N);
    int n;
    printf("Enter the element to be deleted: ");
    scanf("%d",&n);
    deletion(A,n,N);
    N-=1;
    traversal(A,N);
    return(0);
}
