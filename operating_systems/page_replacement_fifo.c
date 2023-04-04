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
int *add_queue(int A[],int nf,int p)
{
    for(int i = 0;i<nf-1;i++)
    {
        A[i]=A[i+1];
    }
    A[nf-1]=p;
    return(A);
}
int main()
{
    int np;
    printf("Enter the number of pages: ");
    scanf("%d",&np);
    int nf;
    printf("Enter the number of frames");
    scanf("%d",&nf);
    int* frame = (int *)malloc(sizeof(int)*nf);
    int* pages = (int *)malloc(sizeof(int)*np);
    int* frame_queue = (int *)malloc(sizeof(int)*nf);

    for(int i = 0;i<nf;i++)
    {
        frame[i]=-1;
        frame_queue[i]=-1;
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
            printf("Fault \n");
            fault+=1;
            frame = replace(frame,nf,frame_queue[0],pages[i]);
            frame_queue = add_queue(frame_queue,nf,pages[i]);
        }
    }
    printf("Total Hit:%d\nTotal Fault:%d",hit,fault);
    return 0;
}
// 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6