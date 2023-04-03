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
void traverse_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    int np;
    printf("Enter the number of processes: ");
    scanf("%d",&np);
    int nr;
    printf("Enter the number of resources: ");
    scanf("%d",&nr);
    int *process_array=(int*)malloc(sizeof(int)*np);
    int required[np][nr];
    int allocated[np][nr];
    int requested[np][nr];
    int max_resource[nr];
    int availaibe[nr];
    for(int i=0;i<nr;i++)
    {
        printf("Enter the maximum availaible instances for resource %d: ",i);
        scanf("%d",&max_resource[i]);
        availaibe[i]=max_resource[i];
    }

    for(int i=0;i<np;i++)
    {
        process_array[i]=i;
        printf("Enter the resource details for the process %d : ",i);
        printf("\n");
        for(int j=0;j<nr;j++)
        {
            printf("Enter the max request for resource %d: ",j);
            scanf("%d",&required[i][j]);
            printf("Enter the allocated instances for resource %d: ",j);
            scanf("%d",&allocated[i][j]);
            requested[i][j]=required[i][j]-allocated[i][j];
            availaibe[j]=availaibe[j]-allocated[i][j];
        }
    }
    traverse_array(process_array,np);
    while(np>0)
    {
        int process_excuted = -1;
        for(int i =0;i<np;i++)
        {

            int process_mimatch = 0;
            for(int j=0;j<nr;j++)
            {
                if(requested[process_array[i]][j]>availaibe[j])
                {
                    process_mimatch+=1;
                    break;
                }
            }
            if(process_mimatch==0)
            {
                process_excuted=process_array[i];
                break;
            }
        }
        if(process_excuted!=-1)
        {
            for(int i =0;i<nr;i++)
            {
                availaibe[i]+=allocated[process_excuted][i];
            }
            printf("%d process executed without issues \n",process_excuted);
            process_array=pop_array(process_array,process_excuted,np);
            np-=1;
            traverse_array(process_array,np);
        }
        else
        {
            printf("Deadlock occured");
        }
    }
}