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

int main()
{
    int N;
    int * A;
    printf("Enter the size of the array: ");
    scanf("%d",&N);
    A = create(N);
    int l=A[0];
    int s=A[0];
    for(int i=0;i<N;i++)
    {
        if(A[i]>l)
        {
            s=l;
            l=A[i];
        }
        if(A[i]>s || s==l)
        {
            s=A[i];
        }
    }
    printf("The second Largest Number is %d",s);

    int sm=A[0];
    int ssm=A[0];
    for(int i=0;i<N;i++)
    {
        if(A[i]<sm)
        {
            ssm=sm;
            sm=A[i];
        }
        if(A[i]<ssm || ssm==sm)
        {
            ssm=A[i];
        }
    }
    printf("\nThe second smallest Number is %d",ssm);

    return(0);

}
