#include <stdio.h>
#include <stdlib.h>
int max (int A[],int n)
{
    int m = A[0];
    for(int i = 1;i<n;i++)
    {
        if(A[i]>m)
        {
            m=A[i];
        }
    }
    return(m);
}
int min_right(int A[], int n, int current)
{
    int m = -1;
    for(int i = 0;i<n;i++)
    {
        if(A[i]>current)
        {
            if(m==-1)
            {
                m=A[i];
            }
            else if(current-A[i]>current-m)
            {
                m=A[i];
            }
        }
    }
    return(m);
}
int min_left(int A[], int n, int current)
{
    int m = -1;
    for(int i = 0;i<n;i++)
    {
        if(A[i]<current)
        {
            if(m==-1)
            {
                m=A[i];
            }
            else if(current-A[i]<current-m)
            {
                m=A[i];
            }
        }
    }
    return(m);
}
int min (int A[], int n)
{
    int m = A[0];
    for(int i = 1;i<n;i++)
    {
        if(A[i]<m)
        {
            m=A[i];
        }
    }
    return(m);
}
int main()
{
    int m;
    printf("Enter the highest disk location: ");
    scanf("%d",&m);

    int n;
    printf("Enter the number of disk locations: ");
    scanf("%d",&n);
    int * disk_string = (int *)malloc(sizeof(int)*n);
    for(int i =0;i<n;i++)
    {
        printf("Enter the disk location: ");
        scanf("%d",&disk_string[i]);
    }

    int current;
    printf("Enter the start location at the disk: ");
    scanf("%d",&current);

    int d;
    printf("Enter direction(0: left | 1:right): ");
    scanf("%d",&d);

    int seektime = 0;

    if(d==0)
    {
        seektime = current - 2*min(disk_string,n) + 2*max(disk_string,n) -min_right(disk_string,n,current);
    }
    else if(d==1)
    {
        printf("%d \n",min_left(disk_string,n,current));
        seektime = 2*max(disk_string,n) - current  - min(disk_string,n) + min_left(disk_string,n,current);
    }

    printf("The seek time is : %d",seektime);

    return 0;
}