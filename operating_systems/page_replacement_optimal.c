#include <stdio.h>
#include <stdlib.h>
int search(int A[],int np,int p)
{
    int bool=0;
    for(int i = 0;i<np;i++)
    {
        if(p==A[i])
        {
            bool = 1;
            break;
        }
    }
    return(bool);
}
int * replace(int A[],int np,int p1,int p2)
{
    for(int i=0;i<np;i++)
    {
        if(A[i]==p1)
        {
            A[i]=p2;
            break;
        }
    }
    return(A);
}
void traverse_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if(A[i]==-1)
        {
            printf("_ ");
        }
        else
        {
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}
int to_replace(int A[],int i,int np,int f[],int nf)
{
    int to_replace = -1;
    int last_use = -1;
    for(int j=0;j<nf;j++)
    {
        if(f[j]==-1)
        {
            to_replace = -1;
            break;
        }
        else
        {
            for(int k =i;k<np;k++)
            {
                if(A[k]==f[j])
                {
                    if(last_use==-1)
                    {
                        to_replace=f[j];
                        last_use=k;
                    }
                    else if(last_use<k)
                    {
                        to_replace=f[j];
                        last_use=k;
                    }
                    break;
                }
                else if(k==np-1)
                {
                    to_replace=f[j];
                    last_use=k;
                }
            }
        }
    }
    return(to_replace);
}
int main()
{
    int np;
    printf("Enter the number of pages: ");
    scanf("%d",&np);
    int nf;
    printf("Enter the number of frames: ");
    scanf("%d",&nf);
    int* frame = (int *)malloc(sizeof(int)*nf);
    int* pages = (int *)malloc(sizeof(int)*np);

    for(int i = 0;i<nf;i++)
    {
        frame[i]=-1;
    }

    for(int i =0;i<np;i++)
    {
        printf("Enter page %d: ",i);
        scanf("%d",&pages[i]);
        printf("\n");
    }
    int hit = 0;
    int fault = 0;
    for(int i = 0;i<np;i++)
    {
        traverse_array(frame,nf);
        printf("%d ",pages[i]);

        if(search(frame,nf,pages[i])==1)
        {
            printf(" Hit\n");
            hit+=1;
        }
        else
        {
            printf("Fault %d\n",to_replace(pages,i,np,frame,nf));
            int replace_page = to_replace(pages,i,np,frame,nf);
            fault+=1;
            frame = replace(frame,nf,replace_page,pages[i]);
        }
        printf("\n");
    }
    printf("Total Hit:%d\nTotal Fault:%d",hit,fault);
    return 0;
}
//1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6