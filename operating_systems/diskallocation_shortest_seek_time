#include <stdio.h>
#include <stdlib.h>
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
    for(int i=0;i<n;i++)
    {
        seektime += abs(current-disk_string[i]);
        current = disk_string[i];
    }

    printf("The seek time is : %d",seektime);

    return 0;
}