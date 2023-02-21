#include <stdio.h>

struct process{
    int at;
    int bt;
    int tat;
    int wt;
    int priority;
    int pid;
};
typedef struct process process;

int main()
{
    printf("Enter the number of Processes: ");
    int n;
    scanf("%d",&n);
    process p_array[n];

    for(int i=0;i<n;i++)
    {
        int t_at,t_bt,t_pid;
        printf("Enter the process id: ");
        scanf("%d",&p_array[i].pid);
        printf("Enter the process arrival time: ");
        scanf("%d",&p_array[i].at);
        printf("Enter the process burst time: ");
        scanf("%d",&p_array[i].bt);
        p_array[i].priority=0;
        p_array[i].tat=0;
        p_array[i].wt=0;
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p_array[j].at>p_array[j+1].at)
            {
                process temp=p_array[j];
                p_array[j]=p_array[j+1];
                p_array[j+1]=temp;
            }
        }
    }

    int cpu_time = 0;

    for(int i=0;i<n;i++)
    {
        cpu_time += p_array[i].bt;
        p_array[i].tat = cpu_time-p_array[i].at;
        p_array[i].wt = p_array[i].tat - p_array[i].bt;
    }

    for(int i = 0;i<n;i++)
    {
        printf("%d %d %d %d",p_array[i].pid,p_array[i].at,p_array[i].bt,p_array[i].tat,p_array[i].wt);
        printf("\n");
    }

    return 0;
}
