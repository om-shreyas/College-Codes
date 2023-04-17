#include <stdio.h>
#include <stdlib.h>
int *pop_array(int A[], int value, int n)
{
    int index=-1;
    for (int i = 0; i < n; i++)
    {
        if(value==A[i])
        {
            index=i;
        }
    }
    for(int i=index;i<n;i++)
    {
        A[i]=A[i+1];
    }
    return (A);
}
int next_disk(int A[],int current,int n)
{
    int next = -1;
    int diffrence = 0;
    for(int i=0;i<n;i++)
    {
        if(next==-1)
        {
            next = A[i];
            diffrence = abs(A[i]-n);
        }
        else if(abs(A[i]-n)<diffrence)
        {
            next = A[i];
            diffrence = abs(A[i]-n);
        }
    }
    return(next);
}
int main()
{
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
    int seektime = 0;
    while(n>0)
    {
        int next = next_disk(disk_string,current,n);
        disk_string = pop_array(disk_string,next,n);
        n=n-1;
        seektime += abs(current-next);
        current = next;
    }

    printf("The seek time is : %d",seektime);

    return 0;
}