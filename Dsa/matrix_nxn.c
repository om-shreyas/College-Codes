#include <stdio.h>

void traverse(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",A[(i)*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d",&n);
    int A[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value for A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    traverse(A,n);

    int B[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter value for B[%d][%d]: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    traverse(A,n);

    int C[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sum = 0;
            for(int k=0;k<n;k++)
            {
                sum += A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
    traverse(C,n);


}
