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
    }
    printf("The second Largest Number is %d",s);

    return(0);   

}