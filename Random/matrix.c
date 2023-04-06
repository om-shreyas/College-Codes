#include <stdio.h>
#include <math.h>

int main()
{
    /* Creating array 1*/
    printf("Enter array dimensions: ");
    int n1,m1;
    scanf("%d %d",&n1,&m1);
    int A1[n1][m1];
    int n=0;
    for(int i =0;i<n1;i++)
    {
        for(int j =0;j<m1;j++)
        {
            printf("Enter element %d: ",n+1);
            n++;
            scanf("%d",&A1[i][j]);
        }
    }

    /* creating array 2*/
    printf("Enter array dimensions: ");
    int n2,m2;
    scanf("%d %d",&n1,&m1);
    int A2[n2][m2];
    int n=0;
    for(int i =0;i<n2;i++)
    {
        for(int j =0;j<m2;j++)
        {
            printf("Enter element %d: ",n+1);
            n++;
            scanf("%d",&A2[i][j]);
        }
    }


}
