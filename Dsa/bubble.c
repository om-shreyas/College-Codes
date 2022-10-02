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
void traversal(int A[],int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
}
int main()
{
    int temp;
    int N;
    int * A;
    printf("Enter the size of the array: ");
    scanf("%d",&N);
    A = create(N);

    traversal(A,N);
    printf("\n");

    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }

    traversal(A,N);
}