#include <stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int prior;
    int tat;
    int wt;
    int comp;
};
typedef struct process process;
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p_array[n];
    for(int i =0;i<n;i++)
    {
        printf("Enter process id: ");
        scanf("%d",&p_array[i].pid);
        printf("Enter process arrival time: ");
        scanf("%d",&p_array[i].at);
        printf("Enter process burst time: ");
        scanf("%d",&p_array[i].bt);
        printf("Enter process priority: ");
        scanf("%d",&p_array[i].prior);
        p_array[i].tat =0;
        p_array[i].wt =0;
        p_array[i].comp =0;
    }
    
    int cpu_time=0;
    int t_n = n;
    while(t_n>0)
    {
        int j=-1;
        for(int i=0;i<n;i++)
        {
            if(j==-1 && p_array[i].at<=cpu_time && p_array[i].comp==0)
            {
                j=i;
            }
            else if(p_array[i].at<=cpu_time && p_array[i].comp==0 && p_array[j].prior<p_array[i].prior)
            {
                j=i;
            }
        }
        if(j!=-1)
        {
            cpu_time+=p_array[j].bt;
            p_array[j].tat = cpu_time-p_array[j].at;
            p_array[j].wt = p_array[j].tat - p_array[j].bt;
            p_array[j].comp = 1;
            t_n-=1;
        }
        else
        {
            cpu_time+=1;
        }
    }
    
    float t_wt = 0;
    
    for(int i =0;i<n;i++)
    {
        t_wt += p_array[i].wt;
        printf("%d %d %d %d %d %d",p_array[i].pid,p_array[i].prior,p_array[i].at,p_array[i].bt,p_array[i].tat,p_array[i].wt);
        printf("\n");
    }
    printf("%f \n",t_wt/n);
    return 0;
}
