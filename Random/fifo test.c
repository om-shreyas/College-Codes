#include <stdio.h>
#include <stdlib.h>
int *add_queue(int A[],int nf,int p)
{
    for(int i = 0;i<nf-1;i++)
    {
        printf("%d %d",A[i],A[i+1]);
        A[i]=A[i+1];
    }
    printf("%d %d",A[nf],p);
    A[nf]=p;
    return(A);
}
void traverse_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void main()
{
    int * a = (int *)malloc(sizeof(int)*3);
    for(int i =0;i<3;i++)
    {
        a[i]=-1;
    }
    traverse_array(a,3);
    printf("\n");
    a = add_queue(a,3,2);
    printf("\n");
    traverse_array(a,3);
}
