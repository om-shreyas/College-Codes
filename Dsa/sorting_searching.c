#include <stdio.h>
#include <stdlib.h>

int * insertion_sort(int A[])
{
    int n = sizeof(A)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        int k = A[i];
        int j = i-1;
        while(j>=0 && A[j]>k)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = k;
    }
    return A;
}

int main()
{
    int * A = {91,28,73,46,55,64,37,82,19,10};
    int n = sizeof(A)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    A = insertion_sort(A);

    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");

    return(0);
}
