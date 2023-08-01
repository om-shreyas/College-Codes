#include <stdio.h>
#include <stdlib.h>

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
int linear(int N,int A[],int e)
{
    for(int i=0;i<N;i++)
    {
        if(A[i]==e)
        {
            return(i+1);
        }
    }
}
int binary(int N, int A[],int e)
{
    int l=0;
    int h=N-1;
    while(h-l>0)
    {
        if(A[(h+l)/2]==e)
        {
            return((h+l)/2+1);
        }
        else if (A[(h+l)/2]>e)
        {
            h=(h+l)/2;
        }
        else if (A[(h+l)/2]<e)
        {
            l=(h+l)/2;
        }        
    }
    return(0);
}

int binary_recursive(int l, int N, int A[],int e)
{
    if(A[(N+l)/2]==e)
    {
        return((N+l)/2+1);
    }
    else if (A[(N+l)/2]>e)
    {
        return(binary_recursive(l,(N+l)/2,A,e));
    }
    else if (A[(N+l)/2]<e)
    {
        return(binary_recursive((N+l)/2,N,A,e));
    }        
}

int main()
{
    int N;
    int * A;
    printf("Enter the size of the array: ");
    scanf("%d",&N);
    A = create(N);
    
    int e;
    printf("Enter Element for Linear search: ");
    scanf("%d",&e);

    printf("Element %d is at %d\n",e,linear(N,A,e));

    printf("Enter Element for binary search: ");
    scanf("%d",&e);

    printf("Element %d is at %d\n",e,binary(N,A,e));
    printf("Element %d is at %d\n",e,binary_recursive(0,N,A,e));

    return(0);
}